/*
 * function: func_021E54CC
 * address: 0x021E54CC
 * packet: pkt_ov178_021E54CC
 * region: ov178
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   PLIST_COMM_End 0x021B6108 thumb ov090
 *   func_02034A5C 0x02034A5C arm
 *   ov090_id 0x0000005A data
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj14379.h"
#include "../include/Obj24455.h"
extern void *POKEPARTY_GetMember(void *,unsigned);
typedef signed int     s32;
typedef unsigned int   u32;
struct Party;
struct PartyMon;
struct S020314B8;
struct S020315D4;
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern void PLIST_COMM_End(void *);
extern void func_02034A5C(s32 handle);
extern unsigned ov090_id[];
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned);
int func_021E54CC(void *handle,int unused,char *q,char *p)
{
 unsigned char i;
 for(i=0;i<6;i++) {
 unsigned n=*(unsigned char *)(p+i+0x51);
 if(n!=0)POKEPARTY_Add(((struct Obj14379 *)q)->f1C,POKEPARTY_GetMember(((struct Obj14379 *)q)->f4,n-1));
 }
 PLIST_COMM_End(p+8);func_02034A5C((unsigned)ov090_id);
 func_0203133C(((struct Obj24455 *)p)->fD0);func_020315D4(handle);func_020306F0(0x58);
 return 1;
}
