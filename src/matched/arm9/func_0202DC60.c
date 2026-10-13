/*
 * unit:     no
 * function: PMS_DRAW_PrintOffset
 * address:  0x0202DC60
 * packet:   pkt_0202DC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The forwarding shim in front of PMS_DRAW_PrintElem: it copies four of the
 * object's own fields into the callee's five stack arguments and clears
 * the selection word at +0x28 afterwards.
 *
 * The ARGUMENT ORDER is what this function pins, and it corrects the
 * reading in docs/notes/pkt_0202E1F0.c.txt: r1 is the object pointer at
 * +8, r2 the word at +4 and r3 the caller's own `a`, which the prologue
 * parks in r4 (`adds r4, r1, #0`) precisely because it is consumed LAST.
 * Spelling the call (e, a, p->f08, p->f04, ...) instead leaves `a` in r1
 * and loses the r4 copy, four bytes short.
 *
 * The five stack words are four plain u32 arguments behind `w`, not a
 * 16-byte struct passed by value: a by-value struct makes the compiler
 * build a local and ldm/stm it into the outgoing area (18 bytes more),
 * whereas the original stores each field straight to its slot. The
 * halfword fields at +0x24, +0x31 and +0x00 are widened to words at the
 * call, so the parameters are u32.
 *
 * symbols:
 *   PMS_DRAW_PrintElem  0x0202E1F0  thumb
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/PMS_DRAW_PrintOffset.c \
 *       --func PMS_DRAW_PrintOffset --addr 0x0202DC60 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u16   f00;
    u8    pad02[2];
    u32   f04;
    void *f08;
    u8   *f0c;
    u8    pad10[0x14];
    u16   f24;
    u8    pad26[2];
    u32   f28;
    u8    pad2c[5];
    u8    f31;
};

extern void PMS_DRAW_PrintElem(u8 *e, void *a1, u32 a2, u32 a3,
                          void *w, u32 c0, u32 c1, u32 c2, u32 c3);

void PMS_DRAW_PrintOffset(struct Obj *p, u32 a, void *w, u32 i, u32 e)
{
    PMS_DRAW_PrintElem(p->f0c + i * 0x28, p->f08, p->f04, a, w,
                  e, p->f24, p->f31, p->f00);
    p->f28 = 0;
}
