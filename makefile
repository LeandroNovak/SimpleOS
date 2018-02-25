CC := i686-elf-gcc
AS := i686-elf-as

SRCDIR := src
BUILDDIR := build
BINDIR := bin

TARGET := $(BINDIR)/sos.bin

SRCEXT := c
SOURCES := $(wildcard $(SRCDIR)/*.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

CFLAGS := -std=gnu99 -ffreestanding -O2 -Wall -Wextra
INC := -I include 

$(TARGET): $(OBJECTS) $(BUILDDIR)/boot.o
	@mkdir -p $(dir $@)
	@echo " Linking..."; $(CC) -T $(SRCDIR)/linker.ld -o $(TARGET) -ffreestanding -O2 -nostdlib $^ -lgcc

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@echo " Building $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(BUILDDIR)/boot.o: $(SRCDIR)/boot.s
	@mkdir -p $(dir $@)
	@echo " Building $^"; $(AS) $^ -o $@

clean:
	@echo " Cleaning..."; $(RM) -r $(TARGET) $(BUILDDIR)

.PHONY: clean


