TARGET=writer
OBJS=writer.o


CC:=$(CROSS_COMPILE)gcc

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

writer.o: writer.c
	$(CC) -c writer.c -o writer.o

clean:
	rm -f $(OBJS) $(TARGET)