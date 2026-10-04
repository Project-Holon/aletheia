/*
 * function: func_021FBCF4
 * address: 0x021FBCF4
 * packet: pkt_ov135_021FBCF4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero bytes of alignment padding after the return.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021FA15C 0x021FA15C thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int on);
extern u32 func_0204B898(u32 p);
extern void func_0204B878(u32 p, u16 k);
extern int func_021FA15C(void *p);
int func_021FBCF4(u8 *p)
{
    int r;
    r = func_021FA15C(p);
    switch (r) {
    case -2:
        func_0204B3DC((struct Obj *)*(u32 *)(p + 8), 1);
        func_0204B878(*(u32 *)(p + 8), func_0204B898(*(u32 *)(p + 8)) + 9);
        *(int *)(p + 0x48) = 3;
        *(int *)(p + 0x4c) = 32;
        *(signed char *)(p + 64) = -2;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)*(u32 *)(p + 8), 1);
        func_0204B878(*(u32 *)(p + 8), func_0204B898(*(u32 *)(p + 8)) + 9);
        *(int *)(p + 0x48) = 3;
        *(int *)(p + 0x4c) = 32;
        *(signed char *)(p + 64) = r;
        break;
    }
    return -1;
}
