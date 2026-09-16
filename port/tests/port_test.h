/*
 * port/tests/port_test.h -- the whole test framework.
 *
 * There is no framework.  A test is a main() that returns 0 or 1, ctest runs
 * it, and these macros print one line per check so a failure names the case,
 * the expected value and the actual one without a debugger.
 */

#ifndef BW_PORT_TEST_H
#define BW_PORT_TEST_H

#include <stdio.h>
#include <string.h>

static int bw_failures;
static int bw_checks;

#define BW_CHECK_EQ(label, got, want)                                      \
    do {                                                                   \
        long bw_g = (long)(got);                                           \
        long bw_w = (long)(want);                                          \
        bw_checks++;                                                       \
        if (bw_g != bw_w) {                                                \
            bw_failures++;                                                 \
            printf("  FAIL %-40s got %ld, want %ld\n", (label), bw_g, bw_w); \
        }                                                                  \
    } while (0)

#define BW_REQUIRE(label, cond)                                            \
    do {                                                                   \
        bw_checks++;                                                       \
        if (!(cond)) {                                                     \
            bw_failures++;                                                 \
            printf("  FAIL %-40s (%s)\n", (label), #cond);                 \
            return 1;                                                      \
        }                                                                  \
    } while (0)

#define BW_REPORT(name)                                                    \
    do {                                                                   \
        printf("%s: %d checks, %d failures\n", (name), bw_checks, bw_failures); \
        return bw_failures == 0 ? 0 : 1;                                   \
    } while (0)

/*
 * Every test takes the data root the same way: argv[1] if given, else the
 * BW_DATA_ROOT environment variable, else the compiled-in default.  CMake
 * passes it on the command line so a ctest run needs no environment.
 */
#define BW_TEST_SETUP(argc, argv)                                          \
    do {                                                                   \
        if ((argc) > 1 && (argv)[1] != NULL && (argv)[1][0] != '\0') {     \
            bw_set_data_root((argv)[1]);                                   \
        }                                                                  \
        printf("data root: %s\n", bw_data_root());                         \
    } while (0)

#endif /* BW_PORT_TEST_H */
