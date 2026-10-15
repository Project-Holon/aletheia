/*
 * function: GTSNEGO_DISP_VBlank
 * address: 0x021D6530
 * packet: pkt_ov120_021D6530
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding follows.
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 */
#include "../include/Obj08078.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_FillScrollArea(u32,u32,u32);
void GTSNEGO_DISP_VBlank(void *unused,u8 *p){CLACT_VBlankSystem();if(((struct Obj08078 *)p)->f100){BG_SYS_FillScrollArea(4,3,((struct Obj08078 *)p)->f104+72);BG_SYS_FillScrollArea(6,3,((struct Obj08078 *)p)->f104+72);((struct Obj08078 *)p)->f100=0;}}
