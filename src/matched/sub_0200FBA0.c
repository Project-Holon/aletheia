/*
 * function: sub_0200FBA0
 * address:  0x0200FBA0
 * packet:   pkt_0200F168
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0200FBA0_Obj  0x0214617C  data
 *
 * Zeroes two word fields of the module-wide object at 0x0214617C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200FBA0.c \
 *       --func sub_0200FBA0 --addr 0x0200FBA0 --cc 1.1p1
 */

typedef unsigned int u32;

struct Sub0200FBA0Obj {
    unsigned char pad[0x60];
};

extern struct Sub0200FBA0Obj sub_0200FBA0_Obj;

void sub_0200FBA0(void)
{
    *(u32 *)((unsigned char *)&sub_0200FBA0_Obj + 0x2c) = 0;
    *(u32 *)((unsigned char *)&sub_0200FBA0_Obj + 0x5c) = 0;
}
