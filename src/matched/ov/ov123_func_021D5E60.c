/*
 * unit: no
 * function: GSYNC_DISP_Draw
 * address: 0x021D5E60
 * packet: pkt_ov123_021D5E60
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DrawSystem 0x0204A600 arm
 *   GSYNC_DISP_UpdateBlendFade 0x021D6678 thumb ov123
 *   GSYNC_DISP_UpdateParticles 0x021D6934 thumb ov123
 */
#include "../include/Obj03267.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern void CLACT_DrawSystem(void);
extern void GSYNC_DISP_UpdateBlendFade(u8 *);
struct Obj;
extern void GSYNC_DISP_UpdateParticles(struct Obj *);
void GSYNC_DISP_Draw(u8 *p){(((struct Obj03267 *)p)->f43C6)++;if(((struct Obj03267 *)p)->f43C6>=192)((struct Obj03267 *)p)->f43C6=0;CLACT_DrawSystem();GSYNC_DISP_UpdateBlendFade(p);GSYNC_DISP_UpdateParticles((struct Obj *)p);}
