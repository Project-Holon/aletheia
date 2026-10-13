/*
 * function: func_021E1594
 * address: 0x021E1594
 * packet: pkt_ov119_021E1594
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_0201EE84 0x0201EE84 thumb
 *   func_0201F250 0x0201F250 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 */
#include "../include/Obj00001.h"
typedef unsigned int u32;
typedef signed short   s16;
struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct WordSet;
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
void func_021E1594(void *a,void *b,int x,int y,int flag,char *p) {if(!flag) {MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),28,(void *)(*(int *)&((struct Obj00001 *)p)->f734));func_0201EE84(((struct Obj00001 *)p)->f724,0,a);func_0201F250((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f734));PRINTSYS_Print(b,x,y,(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f728));}}
