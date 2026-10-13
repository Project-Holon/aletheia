/*
 * function: func_021D9AC8
 * address: 0x021D9AC8
 * packet: pkt_ov121_021D9AC8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D9B26.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_Copy 0x02045838 arm
 *   func_021D9BC0 0x021D9BC0 thumb ov121
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 */
#include "../include/Obj01057.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { int x; int y; } Pair;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct U16Vec;
extern void STRBUF_Copy(struct U16Vec *dst, struct U16Vec *src);
extern void func_021D9BC0(void *, int, Pair *);
typedef unsigned int   u32;
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021D9AC8(u8 *p, int a, int b)
{
    Pair xy;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj01057 *)p)->fC), ((struct Obj01057 *)p)->f16 & 31);
    STRBUF_Copy(((struct Obj01057 *)p)->f10, (struct U16Vec *)a);
    func_021D9BC0(p, b, &xy);
    q = ((struct Obj01057 *)p)->f8;
    PRINTSYS_PrintQueColor(q, (u32)BMP_WIN_GetBmp(((struct Obj01057 *)p)->f0), (s16)xy.x, (s16)xy.y,
                 (u32)(((struct Obj01057 *)p)->f10), b, ((struct Obj01057 *)p)->f16);
    p[4] = 1;
}
