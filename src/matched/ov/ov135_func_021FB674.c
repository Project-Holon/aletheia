/*
 * function: func_021FB674
 * address: 0x021FB674
 * packet: pkt_ov135_021FB674
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021FA514 0x021FA514 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0204B3DC(u32 p, int on);
extern u32 func_0204B898(u32 p);
extern void func_0204B878(u32 p, u16 k);
extern int func_021FA514(void *p, u8 *flags);
int func_021FB674(u8 *p)
{
    int r;
    r = func_021FA514(p, p + 0x60);
    switch ((u32)r) {
    case -2:
        func_0204B3DC(*(u32 *)(p + 8), 1);
        func_0204B878(*(u32 *)(p + 8), func_0204B898(*(u32 *)(p + 8)) + 9);
        *(int *)(p + 0x48) = 3;
        *(int *)(p + 0x4c) = 20;
        *(s16 *)(p + 0x38) = -1;
        break;
    case 10:
        func_0204B3DC(*(u32 *)(p + 8), 1);
        func_0204B878(*(u32 *)(p + 8), func_0204B898(*(u32 *)(p + 8)) + 9);
        *(int *)(p + 0x48) = 3;
        *(int *)(p + 0x4c) = 20;
        *(s16 *)(p + 0x38) = -2;
        break;
    case -1: break;
    default:
        func_0204B3DC(*(u32 *)(p + 8), 1);
        func_0204B878(*(u32 *)(p + 8), 19);
        *(s16 *)(p + 0x38) = r;
        *(int *)(p + 0x48) = 20;
        break;
    }
    return -1;
}
