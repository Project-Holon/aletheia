/*
 * function: func_021E23C8
 * address: 0x021E23C8
 * packet: pkt_ov183_021E23C8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: bounded permuter extracted index/base/heap-address temporaries;
 *   unsigned index arithmetic and top-of-block declarations preserve behavior.
 *   This removes the 12-byte setup scheduling residue; fixed one confirms EXACT.
 * arity: 0201EE0C's unit declares five arguments; this caller visibly supplies
 *   the sixth stack word (2), retained without editing the callee.
 * symbols:
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   BR_UTIL_SetWindowTextBuf 0x021FD19C thumb ov186
 *   STRBUF_Delete 0x02045808 arm
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   d_021E3900 0x021E3900 data a4
 */
#include "../include/Obj02896.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct MsgBank; struct U16Vec; struct WordSet;
typedef struct { u8 a,b,c,d; void *value; } Rec;
typedef struct { u32 index; u8 f4[8]; char *owner; u8 f10[8]; u32 base; } Input;
extern const Rec d_021E3900[];
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern int BR_RES_GetWordSet(char *p);
extern int BR_RES_GetMsgData(char *);
extern void *func_02045EC0(struct MsgBank *,u32);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern void func_0201EE0C(struct WordSet *,u32,const void *,u32,u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void BR_UTIL_SetWindowTextBuf(char *p, void *q, void *text);
extern void STRBUF_Delete(struct U16Vec *);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern unsigned BR_RES_GetFont(char *p);
extern void *BR_UTIL_Create(u16,u32,u16,u16,u8,u8,void *,u16);
extern void BR_UTIL_SetTextFromMessage(char *,void *,void *,void *,u16);
void func_021E23C8(char *p,const Input *q) {
    struct WordSet *ws;
    struct U16Vec *str,*expanded;
    int font,bank,i;
    const Rec *r;
    char *slot;
    u32 tmp1,tmp;
    u16 *tmp2;
    if(!((struct Obj02896 *)p)->f4) ((struct Obj02896 *)p)->f4=BR_UTIL_CreateTextWin((int)q->owner,(void *)(*(int *)&((struct Obj02896 *)p)->f0),((struct Obj02896 *)p)->f1C);
    ws=(struct WordSet *)BR_RES_GetWordSet(q->owner);
    str=func_02045EC0((struct MsgBank *)BR_RES_GetMsgData(q->owner),321);
    tmp2=(u16 *)(p+28);
    expanded=STRBUF_Create(128,*tmp2);
    tmp1=q->base;
    tmp=q->index;
    func_0201EE0C(ws,0,*(void **)(q->base+tmp*4+16),
        *(u32 *)(tmp1+tmp*4+32),1,2);
    func_0201F250(ws,expanded,str);
    BR_UTIL_SetWindowTextBuf(((struct Obj02896 *)p)->f4,q->owner,expanded);
    STRBUF_Delete(expanded); STRBUF_Delete(str);
    BR_RES_LoadBgGraphics((void *)((int)q->owner),30,((struct Obj02896 *)p)->f1C);
    font=BR_RES_GetFont(q->owner);
    bank=BR_RES_GetMsgData(q->owner);
    for(i=0;i<2;i++) {
        r=&d_021E3900[i]; slot=p; slot=slot+i*4;
        ((struct Obj02896 *)slot)->fC=BR_UTIL_Create(4,r->a,r->b,r->c,r->d,14,((struct Obj02896 *)p)->f0,((struct Obj02896 *)p)->f1C);
        BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj02896 *)slot)->fC,(void *)bank,r->value,(void *)font,0x3da0);
    }
}
