/*
 * function: func_02039CD8
 * address:  0x02039CD8
 * packet:   pkt_02039CD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203A2F0  0x0203A2F0  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_0203A28C  0x0203A28C  arm
 *
 * Sweep the eight slot pointers at +0x8.  A slot that is still marked in use
 * (+0xd non-zero) and whose bit is not set in the key word at +0x3e is torn
 * down through the eight-argument delegate; a delegate failure aborts the
 * whole sweep with 0, otherwise the key's bit is set.  Falling off the end
 * clears the key word and reports success.
 *
 * The eight-argument call's first stack slot is the slot pointer itself and
 * the remaining three are the constants 1, 0, 1 (r5 is the object, 0xff/4/
 * 0x10 are the register arguments).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039CD8.c \
 *       --func func_02039CD8 --addr 0x02039CD8 --cc 1.1p1 --arm
 */
#include "../include/Obj15949.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0203A2F0(u32 a0, u32 a1);
extern u32  func_0203D3F8(void *obj, u32 a, u32 b, u32 c, void *slot,
                          int d, int e, int f);
extern u16 func_0203A28C(u16 mask, u32 idx, u32 set);

struct Obj {
    u8   pad_00[8];
    void *slot[8];
    u8   pad_28[0x16];
    u16  key;
};

int func_02039CD8(struct Obj *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (((struct Obj15949 *)((char *)p->slot[i]))->fD == 0)
            continue;
        if (func_0203A2F0(p->key, i) != 0)
            continue;
        if (func_0203D3F8(p, 0xff, 4, 0x10, p->slot[i], 1, 0, 1) != 0)
            func_0203A28C(p->key, i, 1);
        else
            return 0;
    }
    p->key = 0;
    return 1;
}
