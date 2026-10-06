/*
 * function: func_021C9FFC
 * address:  0x021C9FFC
 * packet:   pkt_ov021_021C9FFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Commits the +0xe counter and the current kind's level and redraws.
 *
 * symbols:
 *   func_021CA234  0x021CA234  thumb
 *   func_0200DB08  0x0200DB08  thumb
 *   func_0200DAC4  0x0200DAC4  thumb
 *   func_0200DAEC  0x0200DAEC  thumb
 *   func_0200DB60  0x0200DB60  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_021CA2DC  0x021CA2DC  thumb
 *   func_0200DA14  0x0200DA14  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00116.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_021CA234(u8 *p);
struct Big;
struct Blk1AC;
struct Blk3C;
extern void func_0200DB08(struct Blk1AC *p, u32 i, u16 v);
extern u16 func_0200DAC4(struct Blk1AC *p, u32 i);
extern void func_0200DAEC(struct Blk1AC *p, u32 i, u16 v);
extern void func_0200DB60(struct Blk1AC *p, u32 i);
extern void *func_02012EBC(struct Big *p);
extern void func_021CA2DC(u8 *p, u32 h, int flag, u16 v);
extern void func_0200DA14(struct Blk3C *p);

void func_021C9FFC(u8 *p, u32 x)
{
    u8 kind = p[9];
    u16 v = func_021CA234(p);

    func_0200DB08((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind, v);
    func_0200DAEC((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind, func_0200DAC4((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind));
    func_0200DB60((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind);
    func_021CA2DC(p, (u32)func_02012EBC((struct Big *)(*(u32 *)&((struct Obj00116 *)p)->f6C)), 1, v);
    func_0200DA14((struct Blk3C *)(((struct Obj00116 *)p)->f70));
}
