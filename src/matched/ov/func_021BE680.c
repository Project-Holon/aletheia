/*
 * function: func_021BE680
 * address:  0x021BE680
 * packet:   pkt_021BE4DC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD208 0x021BD208  thumb  ov208

 * Frees the three allocations at +0x5C..+0x64 and clears +0x30.
 */


extern void func_021BD208(int);
typedef unsigned int   u32;
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);

void func_021BE680(char *p)
{
    if (*(int *)(p + 0x30) != 0) {
        func_021BD208(*(int *)(p + 0x30));
        func_0204ADA4(*(int *)(p + 0x5c));
        func_0204A8D4(*(int *)(p + 0x60));
        func_0204AFD8(*(int *)(p + 0x64));
    }
    *(int *)(p + 0x30) = 0;
}

