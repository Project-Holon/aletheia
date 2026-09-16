/*
 * function: func_02065C78
 * address:  0x02065C78
 * packet:   pkt_02065020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Teardown tail of the cell-actor / OAM manager: raises the capture-enable
 * bit at 0x04000448, then, if the attached object still carries work bits at
 * +0x7c, clears the two per-bit slots and drops the object pointer.
 *
 * Decompiled as a leaf so that it becomes a `matched` witness for the call at
 * 0x0204CB44+0x64 (src/pending/func_0204CB44.c); it reads no argument, the r0
 * the caller passes is a leftover.
 *
 * symbols:
 *   g_02147B88    0x02147B88  data
 *   func_02067CB0 0x02067CB0  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02065C78.c \
 *       --func func_02065C78 --addr 0x02065C78 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u8  pad_00[0x74];
    u32 unk_74;       /* 0x74 */
    u8  pad_78[4];
    u32 unk_7c;       /* 0x7c */
};

struct Bank {
    u32         unk_00;
    u32         unk_04;
    struct Obj *obj;   /* 0x08 */
};

extern struct Bank g_02147B88;
extern void func_02067CB0(void);

void func_02065C78(void)
{
    u32 f;
    struct Obj *o;

    *(volatile u32 *)0x04000448 = 1;

    o = g_02147B88.obj;
    f = o->unk_7c;
    if (f != 0) {
        if (f & 1)
            g_02147B88.unk_04 = 0;
        if (f & 2) {
            o->unk_74 = 0;
            func_02067CB0();
        }
        g_02147B88.obj->unk_7c = 0;
    }
    g_02147B88.obj = 0;
}
