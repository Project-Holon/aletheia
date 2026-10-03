/*
 * function: func_021BB658
 * address: 0x021BB658
 * packet: pkt_ov110_021BB658
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_021BF6DC 0x021BF6DC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern u8 func_021BF6DC(u8 *);
void func_021BB658(u8 *p, int enable)
{
    if (enable) {
        if (**(int **)(p + 0x5c) == 0) {
            func_0204B3DC(*(void **)(p + 0x54), 1);
            if (func_021BF6DC(*(u8 **)(p + 4)) == 0) {
                func_0204B878(*(void **)(p + 0x54), 4);
            } else {
                func_0204B878(*(void **)(p + 0x54), 6);
            }
        } else {
            func_0204B3DC(*(void **)(p + 0x54), 0);
        }
    } else {
        func_0204B3DC(*(void **)(p + 0x54), 0);
    }
}
