/*
 * function: func_021BB5A0
 * address: 0x021BB5A0
 * packet: pkt_ov110_021BB5A0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj22359.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *);
u8 *func_021BB5A0(u8 *p,u8 *q) {
    u32 a;
    a=BMP_WIN_Create(1,10,3,11,2,12,1);
    BMP_Clear(func_02045770((struct Descriptor *)a),1);
    BMP_WIN_TransferChars((struct Descriptor *)a);
    ((struct Obj22359 *)p)->f94=a;
    return q+0x16;
}
