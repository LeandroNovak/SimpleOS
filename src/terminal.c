#include "terminal.h"

void terminal_initialize(void) {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
    
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}
 
void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}
 
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}
 
void terminal_putchar(char c) {
    switch(c) {
        case '\n':
            terminal_column = 0;
	        if (++terminal_row >= VGA_HEIGHT)
		        terminal_row = 0;
            break;
        case '\t':
            terminal_column += 4;
            if (terminal_column > VGA_WIDTH) {
                terminal_column -= VGA_WIDTH;
                terminal_row++;
            }
            break;
        default:
            terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
            if (++terminal_column == VGA_WIDTH) {
                terminal_column = 0;
                if (++terminal_row == VGA_HEIGHT)
                    terminal_row = 0;
            }
            break;
    }
}
 
void terminal_write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}
 
void terminal_writestring(const char* data) {
	terminal_write(data, strlen(data));
}

void terminal_writeint(int num, int base, int sign) {
    static char digits[] = "0123456789abcdef";
    char buff[16];
    int i;
    unsigned int x;

    if (sign && (sign = num < 0))
        x = -num;
    else
        x = num;
    i = 0;

    do {
        buff[i++] = digits[x % base];
    } while ((x /= base) != 0);

    if (sign)
        buff[i++] = '-';
    while (--i >= 0) 
        terminal_putchar(buff[i]);
}

void terminal_printf(const char* format, ...) {
    unsigned int* argptr;
    int i, c;
    char* s;

    if (format == 0)
        return;

    argptr = (unsigned int *)(void *)(&format + 1);
    for (i = 0; (c = format[i] & 0xff) != 0; i++) {
        if (c != '%') {
            terminal_putchar(c);
            continue;
        }

        c = format[++i] & 0xff;
        if (c == 0)
            break;
        switch (c) {
            case 'd':
            case 'i':
                terminal_writeint(*argptr++, 10, 1);
                break;
            case 'u':
                terminal_writeint(*argptr++, 10, 0);
                break;
            case 'o':
                terminal_writeint(*argptr++, 8, 0);
                break;
            case 'x':
            case 'p':
                terminal_writeint(*argptr++, 16, 0);
                break;
            case 'c':
                terminal_putchar((char)*argptr++);
                break;
            case 's':
                if ((s = (char*)*argptr++) == 0)
                    s = "(null)";
                while (*s) {
                    terminal_putchar(*s);
                    s++;
                }
                break;
            case '%':
                terminal_putchar('%');
                break;
            default:
                terminal_putchar('%');
                terminal_putchar('c');
                break;
        }
    }
}