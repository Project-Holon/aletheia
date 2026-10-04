/*
 * function: func_021FBDD0
 * address: 0x021FBDD0
 * packet: pkt_ov135_021FBDD0
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
 *   func_021FA394 0x021FA394 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int on);
extern u16 func_0204B898(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021FA394(void *p);
int func_021FBDD0(u8 *p)
{
    int r;
    r = func_021FA394(p);
    switch (r) {
    case -2:
        func_0204B3DC((struct Obj *)*(u32 *)(p + 8), 1);
        func_0204B878((struct Obj *)(*(u32 *)(p + 8)), func_0204B898((struct Obj *)(*(u32 *)(p + 8))) + 9);
        *(int *)(p + 0x48) = 3;
        *(int *)(p + 0x4c) = 35;
        *(signed char *)(p + 65) = -2;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)*(u32 *)(p + 8), 1);
        func_0204B878((struct Obj *)(*(u32 *)(p + 8)), func_0204B898((struct Obj *)(*(u32 *)(p + 8))) + 9);
        *(int *)(p + 0x48) = 3;
        *(int *)(p + 0x4c) = 35;
        *(signed char *)(p + 65) = *(u32 *)(*(u8 **)(p + 0x30) + (r + *(s16 *)(p + 0x56) * 4) * 8 + 4);
        break;
    }
    return -1;
}
