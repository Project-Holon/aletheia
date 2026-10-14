/*
 * unit: no
 * function: GURU2_MAIN_AddBackgroundUnit
 * address: 0x021E0640
 * packet: pkt_ov137_021E0640
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   gGuru2BackgroundUnitSetup 0x021E1D80 data a4
 */
#include "../include/Obj02208.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern u16 G3D_UTIL_AddUnit(struct Util *,const struct Setup *);
extern void G3X_SetClearColor(u16,int,int,int,int);
extern const struct Setup gGuru2BackgroundUnitSetup;
void GURU2_MAIN_AddBackgroundUnit(u8 *p){((struct Obj02208 *)p)->fDA4=G3D_UTIL_AddUnit(*(struct Util * *)&((struct Obj02208 *)p)->fAF4,&gGuru2BackgroundUnitSetup);G3X_SetClearColor(0,0,32767,0,0);}
