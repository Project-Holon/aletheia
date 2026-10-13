/*
 * function: func_0220C4DC
 * address: 0x0220C4DC
 * packet: pkt_ov198_0220C4DC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045738 0x02045738 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj04600.h"
#include "../include/Obj25138.h"
#include "../include/Obj25139.h"
#include "../include/Obj25140.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045770(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *,u32,u32,u32,u32,u32,u16);
extern void STRBUF_Delete(struct U16Vec *vec);
void func_0220C4DC(char *p,int value,int slot,int id,u16 x,s16 y,u32 color)
{
    void *handle;
    void *buf;
    void *text;
    void *context;
    u32 width;
    handle=*(void **)(p+0x1F70+slot*8);
    buf=STRBUF_Create(16,((struct Obj25138 *)(*(char * *)&((struct Obj04600 *)p)->f0))->f10);
    text=func_02045EC0(((struct Obj04600 *)p)->f1EA0,id);
    func_0201EF34(((struct Obj04600 *)p)->f1EA4,0,value);
    func_0201F250(((struct Obj04600 *)p)->f1EA4,buf,text);
    if (x==0xFFFF) {
        width=func_02045738(handle);
        x=((width<<3)-func_0201D304(buf,((struct Obj25139 *)(*(char * *)&((struct Obj04600 *)p)->f0))->fC,0))>>1;
    }
    context=((struct Obj04600 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(context,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),(s16)x,y,(u32)buf,((struct Obj25140 *)(*(char * *)&((struct Obj04600 *)p)->f0))->fC,(u16)color);
    *(u8 *)(p+slot*8+0x1F74)=1;
    STRBUF_Delete(text);
    STRBUF_Delete(buf);
}
