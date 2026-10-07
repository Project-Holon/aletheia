/*
 * file:     unit_021BB954_p13.c
 * unit:     yes
 * function: func_021BC6F4, func_021BC73C
 * address:  0x021BC6F4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_021BA928  0x021BA928  thumb  ov099
 */
#include "../../matched/include/Obj07225.h"

struct Entry;
struct Link;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef enum { K73 = 0x73 } Idx;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

extern u32 func_0203D378(void);
extern void func_021BAAB8(char *p, int a, int b);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *h, unsigned int a, unsigned int b);
extern int func_021BA928(void *p, int v);
int func_021BC6F4(char *p, int v);
int func_021BC73C(char *p, int v);


int func_021BC6F4(char *p, int v)
{
    u32 *a = (u32 *)p;
    Idx k;

    if (func_0203D378() != 0) {
        k = K73;
        func_021BAAB8(p, 0x73, 0);
        func_02039C68((struct Link *)func_020399A8(), 0x1b, 0xa);
        a[k] = 0x49;
    } else {
        func_021BAAB8(p, 0x72, 0);
        a[0x78] = 0x78;
        a[0x73] = 0x8f;
    }
    return v;
}


/*
 * Ages the counter at +0x1E0 into the guard call, then stamps the byte at
 * +0x1353 and selector 0x8A when it has gone negative; returns the selector.
 * The guard call takes the aged value, not the selector.
 */
int func_021BC73C(char *p, int v)
{
    func_021BA928(p, --((struct Obj07225 *)p)->f1E0);

    if (((struct Obj07225 *)p)->f1E0 < 0) {
        ((struct Obj07225 *)p)->f1353 = 0x79;
        ((struct Obj07225 *)p)->f1CC = 0x8A;
    }

    return v;
}
