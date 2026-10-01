/*
 * function: func_021FBBA0
 * address: 0x021FBBA0
 * packet: pkt_ov135_021FBBA0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021FA85C 0x021FA85C thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0204B3DC(u32 p, int on);
extern u32 func_0204B898(u32 p);
extern void func_0204B878(u32 p, u16 k);
extern int func_021FA85C(void *p);
extern void func_0202CAE4(void *p, int a, int b, int c, int d);
int func_021FBBA0(u8 *p)
{
    int r;
    r = func_021FA85C(p);
    switch (r) {
    case -2:
        func_0204B3DC(*(u32 *)(p + 8), 1);
        func_0204B878(*(u32 *)(p + 8), func_0204B898(*(u32 *)(p + 8)) + 9);
        func_0202CAE4(*(void **)(p + 0x18), 0, 0x60, 0x18, 1);
        *(int *)(p + 0x48) = 5;
        *(int *)(p + 0x4c) = 28;
        break;
    case -1: break;
    default:
        func_0204B3DC(*(u32 *)(p + 8), 1);
        func_0204B878(*(u32 *)(p + 8), func_0204B898(*(u32 *)(p + 8)) + 9);
        *(int *)(p + 0x48) = 3;
        *(int *)(p + 0x4c) = 29;
        *(s16 *)(p + 0x3e) = r;
        break;
    }
    return -1;
}
