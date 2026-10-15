/*
 * function: WIFILOGIN_DISP_Delete
 * address: 0x021D4D10
 * packet: pkt_ov115_021D4D10
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   WIFILOGIN_MSG_Delete 0x021D5A9C thumb ov115
 *   WIFILOGIN_DISP_DeleteDisplay 0x021D4E04 thumb ov115
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj13851.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_020403F4(u32 i);
extern void WIFILOGIN_MSG_Delete(u8 *);
extern void WIFILOGIN_DISP_DeleteDisplay(u8 *);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int WIFILOGIN_DISP_Delete(u32 a,int b,int c,u8 *p) { func_020403F4(7); WIFILOGIN_MSG_Delete(*(u8 * *)&((struct Obj13851 *)p)->f38); WIFILOGIN_DISP_DeleteDisplay(*(u8 * *)&((struct Obj13851 *)p)->f34); func_020315D4((struct S020315D4 *)a); GFL_HEAP_DeleteChecked(120); return 1; }
