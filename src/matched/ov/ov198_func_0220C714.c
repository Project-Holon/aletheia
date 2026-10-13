/*
 * function: func_0220C714
 * address: 0x0220C714
 * packet: pkt_ov198_0220C714
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 */
#include "../include/Obj00508.h"
#include "../include/Obj14556.h"
#include "../include/Obj25145.h"
#include "../include/Obj25146.h"
#include "../include/Obj25147.h"
#include "../include/Obj25148.h"
#include "../include/Obj25149.h"
#include "../include/Obj25150.h"
#include "../include/Obj25151.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_022110D4(u8 *,int);
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintQueColor(void *,u32,u32,u32,u32,u32,u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct Bits7 { unsigned char value:7; unsigned char flag:1; };
void func_0220C714(u8 *p,int index)
{
    u8 *elem;
    void *text;
    void *buf;
    void *context;
    void *secondContext;
    void *thirdContext;
    u32 width;
    u16 x;
    elem=p+4+func_022110D4(p,index)*0x4C;
    text=func_02045EC0(((struct Obj00508 *)p)->f1EA0,0x21);
    context=((struct Obj00508 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(context,(u32)BMP_WIN_GetBmp(((struct Obj00508 *)p)->f2008),0,0,(u32)text,((struct Obj25145 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0x3DC0);
    ((struct Obj00508 *)p)->f200C=1;
    STRBUF_Delete(text);
    text=func_02045EC0(((struct Obj00508 *)p)->f1EA0,0x22);
    buf=STRBUF_Create(8,((struct Obj25146 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->f10);
    func_0201EFA4(((struct Obj00508 *)p)->f1EA4,0,((struct Bits7 *)(elem+0x16))->value,3,0,1);
    func_0201F250(((struct Obj00508 *)p)->f1EA4,buf,text);
    secondContext=((struct Obj00508 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(secondContext,(u32)BMP_WIN_GetBmp(((struct Obj00508 *)p)->f1FC8),0,0,(u32)buf,((struct Obj25147 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0x3DC0);
    ((struct Obj00508 *)p)->f1FCC=1;
    STRBUF_Delete(text);
    STRBUF_Delete(buf);
    text=func_02045EC0(((struct Obj00508 *)p)->f1EA0,0x23);
    thirdContext=((struct Obj00508 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(thirdContext,(u32)BMP_WIN_GetBmp(((struct Obj00508 *)p)->f2010),0,0,(u32)text,((struct Obj25148 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0x3DC0);
    ((struct Obj00508 *)p)->f2014=1;
    STRBUF_Delete(text);
    text=func_02045EC0(((struct Obj00508 *)p)->f1EA0,0x24);
    buf=STRBUF_Create(14,((struct Obj25149 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->f10);
    if (((struct Bits7 *)(elem+0x16))->value<100) {
        func_0201EFA4(((struct Obj00508 *)p)->f1EA4,0,((struct Obj14556 *)elem)->f24-((struct Obj14556 *)elem)->f1C,6,1,1);
    } else {
        func_0201EFA4(((struct Obj00508 *)p)->f1EA4,0,0,6,1,1);
    }
    func_0201F250(((struct Obj00508 *)p)->f1EA4,buf,text);
    width=BMP_WIN_GetWidth(((struct Obj00508 *)p)->f1FD0);
    x=(width<<3)-func_0201D304(buf,((struct Obj25150 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0);
    context=((struct Obj00508 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(context,(u32)BMP_WIN_GetBmp(((struct Obj00508 *)p)->f1FD0),(s16)x,0,(u32)buf,((struct Obj25151 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0x2120);
    ((struct Obj00508 *)p)->f1FD4=1;
    STRBUF_Delete(text);
    STRBUF_Delete(buf);
}
