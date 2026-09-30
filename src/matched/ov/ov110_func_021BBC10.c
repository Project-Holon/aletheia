/*
 * function: func_021BBC10
 * address: 0x021BBC10
 * packet: pkt_ov110_021BBC10
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_021BF6DC 0x021BF6DC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 func_0204B898(void *);
extern unsigned func_0204B98C(void *);
extern void func_0204B3DC(void *, unsigned);
extern void func_0204B878(void *, u16);
extern u8 func_021BF6DC(u8 *);
int func_021BBC10(u8 *p)
{
    u16 state = func_0204B898(*(void **)(p + 0x54));
    if (state != 31 && state != 30) return 1;
    if (func_0204B98C(*(void **)(p + 0x54)) == 0) {
        func_0204B3DC(*(void **)(p + 0x54), *(unsigned *)(p + 0x58));
        func_0204B878(*(void **)(p + 0x54), func_021BF6DC(*(u8 **)(p + 4)) == 0 ? 4 : 6);
        *(int *)(p + 0x58) = 0;
        return 1;
    }
    return 0;
}
