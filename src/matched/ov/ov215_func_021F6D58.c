/*
 * function: func_021F6D58
 * address: 0x021F6D58
 * packet: pkt_ov215_021F6D58
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MCSS_SetAnmStopFlag 0x02015E04 thumb
 *   MCSS_SetPaletteFade 0x02015F50 thumb
 */
#include "../include/Obj14712.h"
typedef unsigned char u8;
struct McssFade;
extern void MCSS_SetAnmStopFlag(void *);
typedef signed int     s32;
typedef unsigned int   u32;
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
void func_021F6D58(char *p){MCSS_SetAnmStopFlag(((struct Obj14712 *)p)->f34);MCSS_SetPaletteFade(*(struct McssFade * *)&((struct Obj14712 *)p)->f34,0,16,0,32767);}
