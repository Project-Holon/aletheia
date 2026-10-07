/*
 * file:     field_fog_p12.c
 * unit:     yes
 * function: func_021A0338, func_021A0354, func_021A0358, func_021A0380, func_021A0390, func_021A03A4, func_021A03B8, func_021A03CC
 * address:  0x021A0338
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj07486.h"
#include "../../matched/include/Obj17988.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef struct {
    u8 state;
    u8 pad[3];
    void *buf;
    int val;
} S;

extern u32 func_020307B0(void *p);
void func_021A0338(u8 *p, u32 id, u32 c, u8 d);
u8 func_021A0354(u8 *p);
void func_021A0358(S *s);
int func_021A0380(int *p);
int func_021A0390(int *p);
int func_021A03A4(int *p);
int func_021A03B8(int *p);
int func_021A03CC(int *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021A0338(u8 *p, u32 id, u32 c, u8 d)
{
    if (id != 0x0FFFFFFF) {
        p[0] = 1;
        ((struct Obj07486 *)p)->f2 = id;
        p[1] = d;
    }
    ((struct Obj07486 *)p)->f8 = c;
}


/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021A0354(u8 *p)
{
    return ((struct Obj17988 *)p)->f0;
}


void func_021A0358(S *s)
{
    if (s->buf != 0) {
        func_020307B0(s->buf);
        s->buf = 0;
    }
    s->val = 0x0FFFFFFF;
    if (s->state == 1) {
        s->state = 0;
    }
}

/*
 * Unlabelled leaf, filed as a blocker of the ov024/ov025 lane S26.
 */
int func_021A0380(int *p)
{
    return p[1] != 0 ? 1 : 0;
}

int func_021A0390(int *p)
{
    return p[2] != 0x0FFFFFFF ? 1 : 0;
}

int func_021A03A4(int *p)
{
    int *q = (int *)p[1];

    if (q != 0) {
        return q[0];
    }
    return 0x0FFFFFFF;
}

int func_021A03B8(int *p)
{
    int *q = (int *)p[1];

    if (q != 0) {
        return q[1];
    }
    return 0x0FFFFFFF;
}

int func_021A03CC(int *p)
{
    return p[2];
}
