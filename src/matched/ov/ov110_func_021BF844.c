/*
 * function: func_021BF844
 * address: 0x021BF844
 * packet: pkt_ov110_021BF844
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C3C84 0x021C3C84 data a1
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 */
#include "../include/Obj02819.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_021C3C84[];
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u8 *func_021BF6D4(u8 *);
u8 *func_021BF844(void *a,void *b,void *c) {
    u8 *p=func_02030734(42,160,0,d_021C3C84,154);
    ((struct Obj02819 *)p)->f0=a; ((struct Obj02819 *)p)->f4=b; ((struct Obj02819 *)p)->f8=c;
    ((struct Obj02819 *)p)->f48=STRBUF_Create(32,42);
    ((struct Obj02819 *)p)->fC=(void *)BMP_WIN_Create(2,3,0,26,32,13,1);
    ((struct Obj02819 *)p)->f10=(void *)BMP_WIN_Create(2,0,0,12,4,13,1);
    ((struct Obj02819 *)p)->f14=0; ((struct Obj02819 *)p)->f18=0;
    ((struct Obj02819 *)p)->f9C=func_021BF6D4(*(u8 * *)&((struct Obj02819 *)p)->f4);
    return p;
}
