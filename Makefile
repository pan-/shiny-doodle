sources=a.c b.c b.h
#CC=clang

all: o0.elf o2.elf lto.elf
	@echo -n "Number of occurence of bar (should be 0): "
	@objdump -t lto.elf | grep 'bar' | wc -l

o0.elf: $(sources)
	@$(CC) -c -o a0.o a.c
	@$(CC) -c -o b0.o b.c
	@$(CC) -c -o c0.o c.c
	@$(CC) -o $@ a0.o b0.o c0.o

o2.elf: $(sources)
	@$(CC) -c -O2 -o a2.o a.c
	@$(CC) -c -O2 -o b2.o b.c
	@$(CC) -c -O2 -o c2.o c.c
	@$(CC) -o $@ a2.o b2.o c2.o

lto.elf: $(sources)
	@$(CC) -c -flto -O2 -o alto.o a.c
	@$(CC) -c -flto -O2 -o blto.o b.c
	@$(CC) -c -flto -O2 -o clto.o c.c
	@$(CC) -flto -o $@ alto.o blto.o clto.o

clean:
	@echo Cleaning…
	-@rm *.o
	-@rm *.elf
