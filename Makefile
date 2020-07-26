CC = clang
CFLAGS = -g -ggdb -Wall -Wpedantic -Wextra \
	-D_FORTIFY_SOURCE=2 -fstack-protector-strong -fPIE \
	-Wformat -Wformat-security 

OBJ = tmp/crypto-hex.o tmp/crypto-base64.o tmp/crypto-aes256.o \
	tmp/crypto-sha256.o tmp/crypto-sha256-hmac.o tmp/crypto-sha256-hkdf.o

all: tmp tmp2 bin/test-crypto

test: bin/test-crypto
	./bin/test-crypto

tmp:
	mkdir tmp

tmp2:
	mkdir tmp2

tmp/%.o: src/%.c src/%.h
	@echo cc -c -o $0 $<
	@$(CC) -c -o $@ $< $(CFLAGS) -I../src

tmp2/%.o: srctest/%.c
	@echo cc -c -o $0 $<
	@$(CC) -c -o $@ $< $(CFLAGS) -Isrc

bin/test-crypto: tmp2/crypto.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS) $(LIBS) tmp2/crypto.o

clean:
	rm -f bin/test-crypto tmp/*.o tmp2/*.o

