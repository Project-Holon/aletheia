/*
 * function: MYSTERY_GRAPHIC_ExitClact
 * address: 0x021D98C0
 * packet: pkt_ov121_021D98C0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj13946.h"
typedef unsigned char u8;
struct Bank;
extern void CLACT_DeleteRenderer(void *);
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void MI_CpuFill8(void *,int,unsigned);
void MYSTERY_GRAPHIC_ExitClact(u8 *p) {
    CLACT_DeleteRenderer(((struct Obj13946 *)p)->f4);
    CLACT_DeleteUnit(((struct Obj13946 *)p)->f0);
    CLACT_ExitSystem();
    MI_CpuFill8(p,0,8);
}
