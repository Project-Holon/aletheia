/*
 * function: GURU2_MAIN_StateWaitEffectToEnd
 * address: 0x021DF548
 * packet: pkt_ov137_021DF548
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: Two zero alignment bytes.
 * symbols:
 *   GURU2_MAIN_PopBgmWhenDone 0x021E19A4 thumb ov137
 */
#include "../include/Obj08218.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GURU2_MAIN_PopBgmWhenDone(void);
int GURU2_MAIN_StateWaitEffectToEnd(u8 *p) { if(((struct Obj08218 *)p)->fC<180) ((struct Obj08218 *)p)->fC+=1; if(!GURU2_MAIN_PopBgmWhenDone()) { ((struct Obj08218 *)p)->fC=0; ((struct Obj08218 *)p)->f0=42; } return 0; }
