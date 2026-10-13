/*
 * function: func_021D7060
 * address: 0x021D7060
 * packet: pkt_ov116_021D7060
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes after the epilogue.
 * symbols:
 *   func_021C9530 0x021C9530 arm ov114
 *   func_021D70E4 0x021D70E4 thumb ov116
 *   func_0200DE94 0x0200DE94 thumb
 *   BSUBWAY_SAVEDATA_GetTrainersTagB 0x0200DEA0 thumb
 */
#include "../include/Obj10339.h"
typedef unsigned char u8;
struct Blk1AC;
struct RecSlot;
extern u8 func_0200DE94(struct RecSlot *p);
extern u8 BSUBWAY_SAVEDATA_GetTrainersTagB(struct RecSlot *p);
extern u8 func_0200DCFC(struct Blk1AC *p);
typedef unsigned int   u32;
extern void func_021C9530(u32 a, u32 b, u32 c, const void *p, const void *q, u32 v);
extern void func_021D70E4(u8 *);
void func_021D7060(u8 *p, u8 *q) {
    int a, b, c;
    a = func_0200DE94(((struct Obj10339 *)p)->f160);
    b = BSUBWAY_SAVEDATA_GetTrainersTagB(((struct Obj10339 *)p)->f160);
    c = func_0200DCFC(((struct Obj10339 *)p)->f164);
    func_021C9530((u8)a,(u8)b,(u8)c,p+0x70,p+0x16e,(int)0x80);
    func_021D70E4(q);
}
