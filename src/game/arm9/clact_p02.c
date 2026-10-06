/*
 * file:     clact_p02.c
 * unit:     yes
 * function: func_0204BD3C, func_0204BD64, func_0204BD7C, func_0204BD94, func_0204BE28
 * address:  0x0204BD3C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0206343C  0x0206343C  arm
 *   func_02063640  0x02063640  arm
 *   s_clact_c       0x020A7F74  data
 *   func_02065AA8   0x02065AA8  arm
 *   func_02030734   0x02030734  arm
 *   func_0204BE84   0x0204BE84  arm
 *   func_02065B64   0x02065B64  arm
 */
#include "../../matched/include/Obj11428.h"

struct NNSG2dOamManagerInstance;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Sub {
    u8  pad_00[0x1c];
    u32 bound;   /* 0x1c */
};

struct Obj {
    u8 pad_00[0x80];
    u32 f80;
    u8 pad_84[0x14];
    u32 f98;
    u32 f9c;
};

typedef unsigned short u16;

extern unsigned int func_02063138(void *p, int a, int b, int which);
extern void func_0206343C(struct NNSG2dOamManagerInstance *pMan, u32 bound);
extern void func_02063640(struct NNSG2dOamManagerInstance *pMan);
extern void func_02065AA8(u8 *o);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_0204BE84(void *dst, void *src);
extern void func_02065B64(int p0, void *p1);
extern u32 func_020307B0(void *p);
void func_0204BD3C(char *p, int a, int b, int which);
void func_0204BE28(int *p);
extern const char s_clact_c[];

void func_0204BD3C(char *p, int a, int b, int which)
{
    if (b == 0) {
        ((struct Obj11428 *)p)->f1C = 0;
        return;
    }
    func_02063138(p, a, b, which);
    ((struct Obj11428 *)p)->f1C = 1;
}


/*
 * Blocked at MATCH: all 24 concrete bytes are correct, but the PC24 at +0x0010
 * (the call to func_0206343C) has no witness of any class.  0x0206343C has
 * exactly one branch reference image wide and it is that call, so no cut frees
 * it; the only unblock is a `matched` entry at 0x0206343C, a 508-byte function
 * in pkt_02063078, claimed by lane-C and far outside this lane.
 *
 * Release one bound 0x20-byte OAM sub-record of a cell actor.  The "bound"
 * flag at +0x1c is the same one func_0204BD3C sets, and an unbound record is
 * an early return predicated onto the compare (`popeq`).
 */
void func_0204BD64(struct Sub *s)
{
    if (s->bound == 0) {
        return;
    }

    func_0206343C((struct NNSG2dOamManagerInstance *)s, s->bound);
}


/*
 * Blocked at MATCH: all 24 concrete bytes are correct, but the PC24 at +0x0010
 * (the call to func_02063640) has no witness of any class.  0x02063640 has
 * exactly one branch reference image wide and it is that call; the only unblock
 * is a `matched` entry at 0x02063640, a 316-byte function in pkt_02063640,
 * claimed by lane-C.
 *
 * Release one bound 0x20-byte OAM sub-record of a cell actor.  The "bound"
 * flag at +0x1c is the same one func_0204BD3C sets, and an unbound record is
 * an early return predicated onto the compare (`popeq`).  The r1 read at the
 * call is a leftover, not an argument: 0x02063640 overwrites r1 at +0x1C with
 * `ldrh r1, [r5, #8]` before any use (docs/notes/func_02063640.c.txt).
 */
void func_0204BD7C(struct Sub *s)
{
    if (s->bound == 0) {
        return;
    }

    func_02063640((struct NNSG2dOamManagerInstance *)s);
}


/*
 *           this body (the tool prints "no witness outside 0204BD94..0204BE2C");
 *           func_0204BE84 lives in pkt_0204BE84, which is not this lane's.
 *
 * Byte-identical at 148 bytes; only the two PC24 call fields at +0x14 and
 * +0x68 stay wildcarded.  The 0x020A7F74 pool word is ABS32 into the string
 * area and resolves `literal`, and func_02065B64 resolves `matched`.
 *
 * Spellings that mattered: `for (i = 0; i < count; i++)` with an unsigned `i`
 * and a signed `count` is what gives the single `popls` loop guard and the
 * `blo` back-edge.  Adding an explicit `if (count <= 0) return;` in front of
 * the loop emits BOTH `pople` and `popls` and costs four bytes of layout.
 */
void func_0204BD94(struct Obj *obj, u8 *src, int count, u32 heap)
{
    u32 i;

    func_02065AA8((u8 *)obj);
    obj->f80 = 1;
    obj->f98 = (u32)func_02030734(heap, count * 0x48, 0, s_clact_c, 0xfc7);
    obj->f9c = count;
    for (i = 0; i < count; i++) {
        func_0204BE84((void *)(obj->f98 + i * 0x48), src + i * 0x10);
        func_02065B64((int)obj, (void *)(obj->f98 + i * 0x48));
    }
}

void func_0204BE28(int *p){ func_020307B0((void *)p[0x26]); }
