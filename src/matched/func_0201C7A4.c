/*
 * function: func_0201C7A4
 * address:  0x0201C7A4
 * packet:   pkt_0201C7A4
 * region:   arm9
 * compiler: ../2.0/sp2
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
 * Compiler pin.  Under dsi/1.1p1 the body is right and 48 bytes long: the
 * scratch address is used at two sites, and 1.1p1 caches it in a
 * callee-saved register and copies it into r0 twice.  2.0/sp2
 * rematerialises the pool load at each site, as the image does, and the
 * function is byte-exact (docs/families/cluster_020737C0.h records the
 * same tell for a repeated small constant).  The notes' three passes and
 * 3800 permuter compiles all ran under 1.1p1.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Scratch {
    u8 unk_00[1];
};

extern struct Scratch g_0214655C;

extern u16 *func_02045A90(void *s);
extern void sub_0201C808(struct Scratch *p, void *w, void *x, s16 y, s16 z);
extern void func_0201C8BC(struct Scratch *c, void *s);

void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w)
{
    func_02045A90(s);
    sub_0201C808(&g_0214655C, w, x, y, z);
    func_0201C8BC(&g_0214655C, s);
}
