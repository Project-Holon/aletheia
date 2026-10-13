/*
 * function: func_0220CDF0
 * address: 0x0220CDF0
 * packet: pkt_ov198_0220CDF0
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
#include "../include/Obj00509.h"
#include "../include/Obj14557.h"
#include "../include/Obj25156.h"
#include "../include/Obj25157.h"
#include "../include/Obj25158.h"
#include "../include/Obj25159.h"
#include "../include/Obj25160.h"
#include "../include/Obj25161.h"
#include "../include/Obj25162.h"
#include "../include/Obj25163.h"
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
void func_0220CDF0(u8 *p,int index)
{
    u8 *elem;
    void *text;
    void *buf;
    void *context;
    void *secondContext;
    u32 width;
    u32 otherWidth;
    u16 x;
    elem=p+4+func_022110D4(p,index)*0x4C;
    text=func_02045EC0(((struct Obj00509 *)p)->f1EA0,0x26);
    context=((struct Obj00509 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(context,(u32)BMP_WIN_GetBmp(((struct Obj00509 *)p)->f1FD8),0,0,(u32)text,((struct Obj25156 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0x3DC0);
    ((struct Obj00509 *)p)->f1FDC=1;
    STRBUF_Delete(text);
    text=func_02045EC0(((struct Obj00509 *)p)->f1EA0,0x29);
    width=func_0201D304(text,((struct Obj25157 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0);
    x=((BMP_WIN_GetWidth(((struct Obj00509 *)p)->f1F90)<<3)-width)>>1;
    secondContext=((struct Obj00509 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(secondContext,(u32)BMP_WIN_GetBmp(((struct Obj00509 *)p)->f1F90),(s16)x,0,(u32)text,((struct Obj25158 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0x2120);
    ((struct Obj00509 *)p)->f1F94=1;
    STRBUF_Delete(text);
    text=func_02045EC0(((struct Obj00509 *)p)->f1EA0,0x27);
    buf=STRBUF_Create(8,((struct Obj25159 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->f10);
    func_0201EFA4(((struct Obj00509 *)p)->f1EA4,0,((struct Obj14557 *)elem)->f10,3,0,1);
    func_0201F250(((struct Obj00509 *)p)->f1EA4,buf,text);
    otherWidth=func_0201D304(buf,((struct Obj25160 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0);
    context=((struct Obj00509 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(context,(u32)BMP_WIN_GetBmp(((struct Obj00509 *)p)->f1F90),(s16)(x-otherWidth),0,(u32)buf,((struct Obj25161 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0x2120);
    ((struct Obj00509 *)p)->f1F94=1;
    STRBUF_Delete(text);
    STRBUF_Delete(buf);
    text=func_02045EC0(((struct Obj00509 *)p)->f1EA0,0x28);
    buf=STRBUF_Create(8,((struct Obj25162 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->f10);
    func_0201EFA4(((struct Obj00509 *)p)->f1EA4,0,((struct Obj14557 *)elem)->f12,3,0,1);
    func_0201F250(((struct Obj00509 *)p)->f1EA4,buf,text);
    context=((struct Obj00509 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(context,(u32)BMP_WIN_GetBmp(((struct Obj00509 *)p)->f1F90),(s16)(x+width),0,(u32)buf,((struct Obj25163 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0x2120);
    ((struct Obj00509 *)p)->f1F94=1;
    STRBUF_Delete(text);
    STRBUF_Delete(buf);
}
