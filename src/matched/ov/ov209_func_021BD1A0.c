/*
 * function: ZUKAN_LIST_StateScrollWait
 * address: 0x021BD1A0
 * packet: pkt_ov209_021BD1A0
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_LIST_IsActorAnimActive 0x021BD8C4 thumb ov209
 *   ZUKAN_LIST_UpdateArrowActors 0x021BE5D4 thumb ov209
 */
#include "../include/Obj00088.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bits {u16 low:1;u16 high:15;};
extern u32 ZUKAN_LIST_IsActorAnimActive(char *p, u32 idx);extern void ZUKAN_LIST_UpdateArrowActors(char *,int);
int ZUKAN_LIST_StateScrollWait(char *p) { if(ZUKAN_LIST_IsActorAnimActive(p,((struct Bits *)(p+0xc24))->high)==0){ZUKAN_LIST_UpdateArrowActors(p,0);return ((struct Obj00088 *)p)->f18;}return 6; }
