CC=gcc
CFLAGS=-Wall -pedantic
OBJS=spamid.o dynamic_string_array.o err.o trainfile_loader.o word_hashtable.o eval.o testfile_loader.o output.o
EXE=spamid.exe

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $^