/*
 * function: func_0201C7A4
 * address:  0x0201C7A4
 * packet:   pkt_0201C7A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045A90  0x02045A90  arm
 *   sub_0201C808   0x0201C808  thumb
 *   func_0201C8BC  0x0201C8BC  thumb
 *   g_0214655C     0x0214655C  data
 *
 * A printsys entry point: builds the shared print request in the static
 * scratch through sub_0201C808 and hands it to func_0201C8BC with the
 * string object.  The leading func_02045A90(s) call's result is unused.
 *
 * Withdrawn 2026-09-24 (wave 20, lane 20G): the ../2.0/sp2 pin is retired.
 * The scratch address is held as an integer, a u32 local assigned
 * (u32)&g_0214655C and cast back at each site, matching func_0201C7D0.c.
 * Spelled this way, dsi/1.1p1 caches the address in a callee-saved
 * register and copies it into r0 at each site, byte-exact under the
 * default compiler.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Scratch {
    u8 unk_00[1];
};

extern struct Scratch g_0214655C;

struct U16Vec;
extern u16 *func_02045A90(struct U16Vec *vec);
struct PrintCtx;
extern void sub_0201C808(struct PrintCtx *p, void *w, void *x, u32 y, s16 z);
extern void func_0201C8BC(u8 *a0, int a1);

void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w)
{
    u32 base;

    func_02045A90(s);
    base = (u32)&g_0214655C;
    sub_0201C808((struct PrintCtx *)base, w, x, y, z);
    func_0201C8BC((u8 *)((struct Scratch *)base), (int)s);
}
