/*
 * function: func_0207312C
 * address:  0x0207312C
 * packet:   pkt_0207312C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_0214E00C  0x0214E00C  data
 *   g_0214E018  0x0214E018  data
 *   g_0214E024  0x0214E024  data
 *   g_0214E464  0x0214E464  data
 *   func_02060468  0x02060468  arm
 *   func_020604AC  0x020604AC  arm
 *
 * Pinned ../2.0/sp2 on the documented "kept constants" tell.  The image
 * materialises the allocator's element size TWICE, `mov r1, #0x14`
 * (`14 10 a0 e3`) at 0x02073134 and again at 0x02073140; 1.1p1 -O4,p CSEs the
 * pair into one hoisted `mov r4, #0x14` plus two `mov r1, r4`, which costs a
 * further callee-saved register and turns the original's
 * `push {r4, r5, r6, r7, r8, sb, sl, lr}` (`f0 47 2d e9`) into a ten-register
 * `push {r3, r4, ..., fp, lr}`, 180 bytes with 128 concrete bytes out.  The
 * indexed-subscript spelling of the two loops additionally leaves an `mla`
 * cursor under both front ends; the pointer-cursor form above is what
 * reproduces the original's `add r7, r7, #0x44` / `add sb, sb, #0x24`
 * strength reduction.  Under the pin the same C is 180 bytes, 0 concrete
 * mismatches.
 *
 * Note c->b3c is the loop INDEX, not zero: the `strb r6, [r7, #0x3c]` at
 * 0x02073164 stores the counter before the `add r6, r6, #1` at 0x0207316C,
 * while c->b2c takes the separate hoisted zero in r5.  Writing both as 0
 * leaves exactly one byte out at +0x38.
 *
 * Blocked at MATCH, evidence class: `literal` unavailable for the ABS32 site
 * at +0xAC.  The word 0x0214E024 appears in exactly one pool image-wide, my
 * own pool_020731D8 at 0x020731D8 (the three grep hits in asm/arm9/src are
 * that one address seen through three overlapping listings), so it has no
 * witness outside 0x0207312C..0x020731E0 and cannot be attested.  Every other
 * site resolves: four `label`, three `literal`.
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef signed int s32;

struct Chan { u8 p00[0x2c]; u8 b2c; u8 p2d[0x3c - 0x2d]; u8 b3c; u8 p3d[0x44 - 0x3d]; };
struct Slot { u8 p00[0x0c]; u8 p0c[0x18 - 0x0c]; u32 f18; u32 f1c; u8 b20; u8 p21[0x24 - 0x21]; };

extern char g_0214E00C[];
extern char g_0214E018[];
extern struct Chan g_0214E024[];
extern struct Slot g_0214E464[];

extern void func_02060468(void *list, u32 size);
extern void func_020604AC(void *list, void *node);

void func_0207312C(void)
{
    s32 i;
    struct Chan *c;
    struct Slot *s;

    func_02060468(g_0214E018, 0x14);
    func_02060468(g_0214E00C, 0x14);

    for (i = 0, c = g_0214E024; i < 0x10; i++, c++) {
        c->b2c = 0;
        c->b3c = (u8)i;
        func_020604AC(g_0214E00C, c);
    }

    for (i = 0, s = g_0214E464; i < 0x20; i++, s++) {
        func_02060468(s, 0xc);
        func_02060468(&s->p0c, 0);
        s->b20 = 0x7f;
        s->f18 = 1;
        s->f1c = 0;
    }
}
