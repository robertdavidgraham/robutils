/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include "crypto-aes256.h"
#include "crypto-base64.h"
#include "crypto-hex.h"
#include "crypto-sha256-hkdf.h"
#include "crypto-sha256-hmac.h"
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(WIN32) || defined(_WIN32)
#define snprintf _snprintf
#endif


/**
 * For selftests, prints a message when the test fails/succeeds
 */
static int STATUS(int test_result, const char *name) {
    if (test_result)
        fprintf(stderr, "[-] %s: failed\n", name);
    else
        fprintf(stderr, "[+] %s: succeeded\n", name);
    return test_result;
}

/**
 * Call all the quick selftest functions for the crypto modules, to make
 * sure all the routines are running well. It's not a comprehensive test,
 * though. */
static int selftest(void) {
    int failure_count = 0;

    failure_count += STATUS(AES256_selftest(0), "AES-256");
    failure_count += STATUS(base64_selftest(), "BASE64");
    failure_count += STATUS(crypto_hkdf_selftest(), "HKDF-SHA256");
    exit(STATUS(failure_count, "selftest") != 0);
}


int main(int argc, char *argv[]) {

    return selftest();
}
