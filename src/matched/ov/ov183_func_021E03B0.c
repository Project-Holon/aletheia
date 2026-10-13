/*
 * function: func_021E03B0
 * address: 0x021E03B0
 * packet: pkt_ov183_021E03B0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FC7C4 0x021FC7C4 thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02025B64 0x02025B64 thumb
 *   func_0201F048 0x0201F048 thumb
 *   func_0201F094 0x0201F094 thumb
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   gSpeciesNameBank 0x020A7370 data a4
 */
#include "../include/Obj00277.h"
#include "../include/Obj00351.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int gSpeciesNameBank;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern int func_021FC21C(char *);
extern void func_021FC754(char *,void *,void *,void *,u16);
extern void func_021FC7C4(char *,void *,void *,u16);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u8 func_02025B64(u32);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
void func_021E03B0(char *p,char *q,int mode)
{
    int first,second,ws;
    void *data,*text;
    first=func_021FC20C(*(char * *)&((struct Obj00351 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj00351 *)q)->f8);
    switch(mode) {
    case 0:
        if(((struct Obj00351 *)q)->f18!=19)func_021FC754(*(char * *)&((struct Obj00277 *)p)->f24,(void *)second,(void *)(((struct Obj00351 *)q)->f18+205),(void *)first,0x3da0);
        else func_021FC754(*(char * *)&((struct Obj00277 *)p)->f24,(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 1:
        if(((struct Obj00351 *)q)->f14!=0xffff)func_021FC754(*(char * *)&((struct Obj00277 *)p)->f2C,(void *)gSpeciesNameBank,(void *)(u32)((struct Obj00351 *)q)->f14,(void *)first,0x3da0);
        else func_021FC754(*(char * *)&((struct Obj00277 *)p)->f2C,(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 2:
        if(((struct Obj00351 *)q)->f16==255 && ((struct Obj00351 *)q)->f17==255) {
            func_021FC754(*(char * *)&((struct Obj00277 *)p)->f34,(void *)second,(void *)117,(void *)first,0x3da0);
            return;
        }
        ws=func_021FC21C(*(char * *)&((struct Obj00351 *)q)->f8);
        data=func_02045EC0((void *)second,24);
        text=STRBUF_Create(128,((struct Obj00277 *)p)->f54);
        if(!func_02025B64(((struct Obj00351 *)q)->f16))func_0201F048((void *)ws,0,((struct Obj00351 *)q)->f16);
        else func_0201F094((void *)ws,0,((struct Obj00351 *)q)->f16,((struct Obj00351 *)q)->f17);
        func_0201F250((void *)ws,text,data);
        func_021FC7C4(*(char * *)&((struct Obj00277 *)p)->f34,text,(void *)first,0x3da0);
        STRBUF_Delete(data);STRBUF_Delete(text);
        break;
    }
}
