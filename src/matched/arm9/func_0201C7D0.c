/*
 * function: func_0201C7D0
 * address:  0x0201C7D0
 * packet:   pkt_0201C7D0
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
 *   sub_0201C8A4   0x0201C8A4  thumb
 *   g_0214655C     0x0214655C  data
 *
 * A printsys entry point: the func_0201C7A4 body plus a
 * sub_0201C8A4(scratch, v) step between building the shared print request
 * in the static scratch and handing it to func_0201C8BC.  The leading
 * func_02045A90(s) call's result is unused.
 *
 * What closed it (wave 20): the scratch address is held as an integer, a
 * u32 local assigned (u32)&g_0214655C and cast back at each of the three
 * sites.  Spelled `&g_0214655C` at every site, 1.1p1 value-numbers the
 * address once, caches it in r4 and schedules z's outgoing stack store
 * straight after the first call to free that register (37 bytes out).
 * Through the integer local the address is rematerialised from its one pool
 * word at every site, z stays in r4 until its store after r0..r3 as the
 * image does, and the stacked u16 read keeps the 1.1p1 base.  This retires
 * the ../2.0/sp2 near miss (2 out) the notes carried.
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
extern void sub_0201C808(struct Scratch *p, void *w, void *x, s16 y, s16 z);
extern void func_0201C8BC(struct Scratch *c, void *s);
extern void sub_0201C8A4(struct Scratch *c, u16 v);

void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v)
{
    u32 base;

    func_02045A90(s);
    base = (u32)&g_0214655C;
    sub_0201C808((struct Scratch *)base, w, x, y, z);
    sub_0201C8A4((struct Scratch *)base, v);
    func_0201C8BC((struct Scratch *)base, s);
}
