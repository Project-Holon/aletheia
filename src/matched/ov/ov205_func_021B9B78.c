/*
 * function: func_021B9B78
 * address: 0x021B9B78
 * packet: pkt_ov205_021B9B78
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021B9BAA follow; no follower.
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_020071F0 0x020071F0 thumb
 *   GAME_DATA_PartSaveMain 0x02012E7C thumb
 *   func_020072A4 0x020072A4 thumb
 */
#include "../include/Obj10884.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;struct Sub020072A4Ctrl;extern void *GAME_DATA_GetSaveControl(struct Big *);extern int func_020071F0(void *);extern int GAME_DATA_PartSaveMain(char *,int);extern void func_020072A4(struct Sub020072A4Ctrl *,u32);
void func_021B9B78(char *p) { void *save; u32 n;save=GAME_DATA_GetSaveControl(*(struct Big * *)&((struct Obj10884 *)p)->f4);if(func_020071F0(save)==0) { n=GAME_DATA_PartSaveMain(*(char * *)&((struct Obj10884 *)p)->f4,8);if(n-2<=1) { func_020072A4(save,8);((struct Obj10884 *)p)->f3C=1; } } }
