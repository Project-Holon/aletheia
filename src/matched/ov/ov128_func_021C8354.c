/*
 * function: func_021C8354
 * address: 0x021C8354
 * packet: pkt_ov128_021C8354
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled function.
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   WF2DMAP_TOUCH_TransferScreen 0x021CA4B4 thumb ov128
 */
#include "../include/Obj23081.h"
#include "../include/Obj23082.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern void BG_SYS_ResetSlot(u32,u32,u32);
extern void WF2DMAP_TOUCH_TransferScreen(char *);
int func_021C8354(u8 *p,u8 *q) {if(PRINTSYS_QUE_IsFinished(*(const struct PrintSys * *)&((struct Obj23082 *)q)->f34)==1) {BG_SYS_ResetSlot(2,0,0);BG_SYS_ResetSlot(3,0,0);WF2DMAP_TOUCH_TransferScreen(**(char ** *)&((struct Obj23081 *)p)->f14);return 1;}return 0;}
