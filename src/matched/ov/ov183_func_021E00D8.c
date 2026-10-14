/*
 * function: func_021E00D8
 * address: 0x021E00D8
 * packet: pkt_ov183_021E00D8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddStrItem 0x0201F898 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_02012944 0x02012944 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   func_02025B64 0x02025B64 thumb
 *   func_0201F048 0x0201F048 thumb
 *   func_0201F094 0x0201F094 thumb
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_021FC8C8 0x021FC8C8 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   d_021E3780 0x021E3780 data a4
 *   d_021E372E 0x021E372E data a4
 */
#include "../include/Obj02231.h"
#include "../include/Obj03330.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {u32 words[10];} Config;
typedef struct {int a,b,c;} Triple;
typedef struct {u16 a,b,c;u8 flag,pad;} Params;
typedef struct {u8 a,b,c,d;u16 file;} Record;
typedef struct Slot Slot;
extern const Config d_021E3780;
extern const Record d_021E372E[];
struct MsgBank;
struct Sub0200852CObj;
struct U16Vec;
struct WordSet;
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern Slot *BMP_MENUWORK_Create(u32,u32);
extern void BMP_MENUWORK_AddStrItem(struct Slot *table, u32 a, u32 b, u32 tag);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u8 *func_02012944(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern int BR_RES_GetWordSet(char *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u8 func_02025B64(u32);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *func_021FC8C8(Config *,u32);
extern void MI_CpuFill8(void *,u32,u32);
extern int BR_RES_GetSprite(int,int,Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
int func_021E00D8(char *p,char *q)
{
    int first,second,a,b;
    void *v,*text,*data;
    int ws;
    Config cfg;
    Triple triple;
    Params params;
    first=BR_RES_GetFont(*(char * *)&((struct Obj03330 *)q)->f8);
    second=BR_RES_GetMsgData(*(char * *)&((struct Obj03330 *)q)->f8);
    BR_RES_LoadBgGraphics((void *)(*(int *)&((struct Obj03330 *)q)->f8),28,((struct Obj02231 *)p)->f54);
    text=STRBUF_Create(128,((struct Obj02231 *)p)->f54);
    v=func_02012944(((struct Obj03330 *)q)->f10);
    a=func_0200856C(v);b=func_02008570(v);
    ws=BR_RES_GetWordSet(*(char * *)&((struct Obj03330 *)q)->f8);
    data=func_02045EC0((void *)second,125);
    if(!func_02025B64(a))func_0201F048((void *)ws,0,a);
    else func_0201F094((void *)ws,0,a,b);
    func_0201F250((void *)ws,text,data);
    STRBUF_Delete(data);
    *(Slot * *)&((struct Obj02231 *)p)->f14=BMP_MENUWORK_Create(1,((struct Obj02231 *)p)->f54);
    BMP_MENUWORK_AddStrItem(*(Slot * *)&((struct Obj02231 *)p)->f14,(u32)text,0,((struct Obj02231 *)p)->f54);
    STRBUF_Delete(text);
    cfg=d_021E3780;
    cfg.words[0]=*(u32 *)&((struct Obj02231 *)p)->f14;cfg.words[1]=1;
    cfg.words[5]=*(u32 *)&((struct Obj03330 *)q)->f8;cfg.words[6]=((struct Obj03330 *)q)->f4;
    ((struct Obj02231 *)p)->f18=func_021FC8C8(&cfg,((struct Obj02231 *)p)->f54);
    MI_CpuFill8(&params,0,8);
    BR_RES_GetSprite(*(int *)&((struct Obj03330 *)q)->f8,6,&triple);
    params.a=d_021E372E[0].a;params.b=d_021E372E[0].b;params.c=d_021E372E[0].c;params.flag=1;
    ((struct Obj02231 *)p)->fC=func_021FB378(&params,d_021E372E[0].file,96,1,*(int *)&((struct Obj03330 *)q)->f4,((struct Obj02231 *)p)->f44,first,second,&triple,((struct Obj02231 *)p)->f54);
    return 1;
}
