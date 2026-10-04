/*
 * function: func_0220D6DC
 * address: 0x0220D6DC
 * packet: pkt_ov198_0220D6DC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 */
#include "../include/Obj01077.h"
#include "../include/Obj25176.h"
#include "../include/Obj25177.h"
#include "../include/Obj25178.h"
#include "../include/Obj25179.h"
#include "../include/Obj25180.h"
#include "../include/Obj25181.h"
#include "../include/Obj25182.h"
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
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u8 func_02045738(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_0220D6DC(char *p,u8 *record,int slot)
{
    void *buf;
    void *text;
    void *context;
    void *secondContext;
    u32 width;
    u32 otherWidth;
    buf=func_020457B0(6,((struct Obj25176 *)(*(char * *)&((struct Obj01077 *)p)->f0))->f10);
    text=func_02045EC0(((struct Obj01077 *)p)->f1EA0,0x35);
    context=((struct Obj01077 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),40,24,(u32)text,((struct Obj25177 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj01077 *)p)->f1EA0,0x38);
    width=func_0201D304(text,((struct Obj25178 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0);
    secondContext=((struct Obj01077 *)p)->f1EAC;
    func_0201C724(secondContext,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),80,24,(u32)text,((struct Obj25179 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj01077 *)p)->f1EA0,0x37);
    func_0201EFA4(((struct Obj01077 *)p)->f1EA4,0,record[3],2,0,1);
    func_0201F250(((struct Obj01077 *)p)->f1EA4,buf,text);
    context=((struct Obj01077 *)p)->f1EAC;
    width+=80;
    func_0201C724(context,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),(s16)width,24,(u32)buf,((struct Obj25180 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj01077 *)p)->f1EA0,0x36);
    func_0201EFA4(((struct Obj01077 *)p)->f1EA4,0,record[2],2,0,1);
    func_0201F250(((struct Obj01077 *)p)->f1EA4,buf,text);
    otherWidth=func_0201D304(buf,((struct Obj25181 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0);
    context=((struct Obj01077 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),(s16)(80-otherWidth),24,(u32)buf,((struct Obj25182 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    func_02045808(text);
    func_02045808(buf);
}
