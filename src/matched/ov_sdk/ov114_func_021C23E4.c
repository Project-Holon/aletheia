/*
 * function: func_021C23E4
 * address:  0x021C23E4
 * packet:   pkt_ov114_021C23E4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiNewPost (ghttppost.o)
 *
 * Closed (w5_nm): the 7x4 byte-store loop is memset(post, 0, sizeof(GHIPost))
 * through string.h, placed after the null check; mwccarm expands it inline and
 * shares the zero with the early return.
 *
 * symbols:
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   func_02184144                  0x02184144  arm ov009
 *   func_0217EAE0                  0x0217EAE0  arm ov009
 *   func_021C235C                  0x021C235C  arm ov114
 */

#include "../arm9_sdk/libc/string.h"

typedef enum { GHTTPFalse, GHTTPTrue } GHTTPBool;

struct DArrayImplementation;

typedef struct GHIPost {
    struct DArrayImplementation *data;
    void (*callback)(int, int, int, int, int, void *);
    void *param;
    GHTTPBool hasFiles;
    GHTTPBool hasSoap;
    GHTTPBool useDIME;
    GHTTPBool autoFree;
} GHIPost;

extern void *func_0217EAB0(unsigned long size);
extern struct DArrayImplementation *func_02184144(int elemSize, int numElemsToAllocate,
                                                  void (*elemFreeFn)(void *));
extern void func_0217EAE0(void *ptr);
extern void func_021C235C(void *elem);

GHIPost *func_021C23E4(void)
{
    GHIPost *post;

    post = (GHIPost *)func_0217EAB0(sizeof(GHIPost));
    if (post == 0)
        return 0;
    memset(post, 0, sizeof(GHIPost));
    post->autoFree = GHTTPTrue;
    post->data = func_02184144(0x18, 0, func_021C235C);
    if (post->data == 0) {
        func_0217EAE0(post);
        return 0;
    }
    return post;
}
