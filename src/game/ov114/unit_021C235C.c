/*
 * file:     unit_021C235C.c
 * unit:     yes
 * function: func_021C235C, func_021C23E4
 * address:  0x021C235C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217EAE0  0x0217EAE0  arm
 *   func_02181D84  0x02181D84  arm
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   func_02184144                  0x02184144  arm ov009
 */
#include "ghttp_types.h"
#include "../../matched/arm9_sdk/libc/string.h"

struct DArrayImplementation;
typedef struct Obj {
    int type;
    void *p4;
    void *p8;
    void *pC;
    void *p10;
    void *p14;
} Obj;


extern void func_0217EAE0(void *);
extern void func_02181D84(void *);
extern void *func_0217EAB0(unsigned long size);
extern struct DArrayImplementation *func_02184144(int elemSize, int numElemsToAllocate,
                                                  void (*elemFreeFn)(void *));
void func_021C235C(void *elem);
GHIPost *func_021C23E4(void);


void func_021C235C(void *elem)
{
    Obj *o = elem;
    if (o->type != 3)
        func_0217EAE0(o->p4);
    if (o->type == 0) {
        func_0217EAE0(o->p8);
    } else if (o->type == 1) {
        func_0217EAE0(o->p8);
        func_0217EAE0(o->pC);
        func_0217EAE0(o->p10);
    } else if (o->type == 2) {
        func_0217EAE0(o->p10);
        func_0217EAE0(o->p14);
    } else if (o->type == 3) {
        func_02181D84(o->p8);
    }
}


/*
 * sdk:      ghiNewPost (ghttppost.o)
 *
 * Closed (w5_nm): the 7x4 byte-store loop is memset(post, 0, sizeof(GHIPost))
 * through string.h, placed after the null check; mwccarm expands it inline and
 * shares the zero with the early return.
 */
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
