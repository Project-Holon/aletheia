/*
 * function: ZUKAN_LIST_StateWaitFade
 * address: 0x021BCDE0
 * packet: pkt_ov209_021BCDE0
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 */
#include "../include/Obj14668.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 PALANM_GetFadeRequestBits(const char *);
int ZUKAN_LIST_StateWaitFade(char *p) { if(PALANM_GetFadeRequestBits(*(char * *)&((struct Obj14668 *)p)->fC)==0)return ((struct Obj14668 *)p)->f1C;return 2; }
