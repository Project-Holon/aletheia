/*
 * function: func_021FB964
 * address: 0x021FB964
 * packet: pkt_ov135_021FB964
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021F9CDC 0x021F9CDC thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int on);
extern u32 func_0204B898(u32 p);
extern void func_0204B878(u32 p, u16 k);
extern int func_021F9CDC(void *p, u8 *flags);
int func_021FB964(u8 *p)
{
    int r;
    r = func_021F9CDC(p, p + 0x60);
    switch ((u32)r) {
    case 0: case 1: case 2: case 3: case 4:
        func_0204B3DC((struct Obj *)*(u32 *)(p + 8), 1);
        func_0204B878(*(u32 *)(p + 8), func_0204B898(*(u32 *)(p + 8)) + 9);
        *(int *)(p + 0x48) = 24;
        *(s16 *)(p + 0x3a) = r;
        break;
    case -2:
        func_0204B3DC((struct Obj *)*(u32 *)(p + 8), 1);
        func_0204B878(*(u32 *)(p + 8), func_0204B898(*(u32 *)(p + 8)) + 9);
        *(int *)(p + 0x48) = 24;
        *(s16 *)(p + 0x3a) = -1;
        break;
    }
    return -1;
}
