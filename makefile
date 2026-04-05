CC      = gcc
CFLAGS  = -O2 -Wall
TARGET  = scraptest
PREFIX  = /usr/local
OBJS    = scraptest.o fetch_os.o fetch_hardware.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

install: $(TARGET)
	install -D -m 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)

clean:
	rm -f $(TARGET) *.o

.PHONY: all install clean
