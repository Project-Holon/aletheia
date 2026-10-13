/*
 * function: func_021C9180
 * address: 0x021C9180
 * packet: pkt_ov128_021C9180
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C6ADC 0x021C6ADC thumb ov128
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */
#include "../include/Obj00329.h"
#include "../include/Obj10490.h"
#include "../include/Obj14044.h"
#include "../include/Obj23102.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct WordSet;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_021C6ADC(u8 *p, u8 *q, unsigned v);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02041B6C(u32 bit);
void func_021C9180(char *p,char *q,char *r) {
 char *s;
 func_0201F02C(((struct Obj00329 *)r)->f0,0,GAME_DATA_GetMyStatus(((struct Obj23102 *)q)->f4));
 func_021C6ADC((u8 *)r,(u8 *)(r+12),50);
 s=*(char * *)&((struct Obj10490 *)p)->f14;
 func_02041090(2,(u32)(s+12),0,0,(((struct Obj14044 *)s)->f0>>3)&255,(((struct Obj14044 *)s)->f2>>3)&255);
 func_02041B6C(2);
}
