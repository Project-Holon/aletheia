/*
 * function: func_021FC7C4
 * address: 0x021FC7C4
 * packet: pkt_ov186_021FC7C4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment padding at 0x021FC82E.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_Copy 0x02045838 arm
 *   func_021FC870 0x021FC870 thumb ov186
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 */
#include "../include/Obj02903.h"
typedef struct Pair {int x,y;} Pair;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct U16Vec;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void STRBUF_Copy(struct U16Vec *dst, struct U16Vec *src);
extern void func_021FC870(int,Pair *,const void *,void *,void *,Pair *);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021FC7C4(char *p,void *text,void *font,unsigned short value)
{
    Pair xy;
    void *owner;
    BMP_Clear(func_02045770(((struct Obj02903 *)p)->fC),((struct Obj02903 *)p)->f14);
    STRBUF_Copy(((struct Obj02903 *)p)->f10,text);
    func_021FC870(((struct Obj02903 *)p)->f18,(Pair *)(p+28),func_02045770(((struct Obj02903 *)p)->fC),((struct Obj02903 *)p)->f10,font,&xy);
    owner=((struct Obj02903 *)p)->f8;
    PRINTSYS_PrintQueColor(owner,(u32)func_02045770(((struct Obj02903 *)p)->f0),(short)xy.x,(short)xy.y,(u32)(((struct Obj02903 *)p)->f10),(u32)font,value);
    p[4]=1;
}
