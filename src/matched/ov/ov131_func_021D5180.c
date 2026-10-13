/*
 * function: P_STATUS_DeleteButtonActors
 * address: 0x021D5180
 * packet: pkt_ov131_021D5180
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_RIBBON_DeleteObjects 0x021D89FC thumb ov131
 *   P_STA_SKILL_DeleteObjects 0x021D9BD4 thumb ov131
 *   P_STA_SUB_DeleteObjects 0x021D694C thumb ov131
 *   func_0204B3B4 0x0204B3B4 arm
 */
#include "../include/Obj10504.h"
typedef unsigned char u8;
struct Obj;
extern void P_STA_RIBBON_DeleteObjects(void *unused, unsigned char *s);
extern void P_STA_SKILL_DeleteObjects(void *a, u8 *p);
extern void P_STA_SUB_DeleteObjects(void *a, unsigned char *p);
extern void func_0204B3B4(struct Obj *p);
void P_STATUS_DeleteButtonActors(char *p)
{
    u8 i;
    P_STA_RIBBON_DeleteObjects(p,((struct Obj10504 *)p)->f94);
    P_STA_SKILL_DeleteObjects(p,((struct Obj10504 *)p)->f90);
    P_STA_SUB_DeleteObjects(p,((struct Obj10504 *)p)->f88);
    for (i=0;i<8;i++) func_0204B3B4(*(void **)(p+i*4+0x178));
    for (i=0;i<2;i++) func_0204B3B4(*(void **)(p+i*4+0x198));
}
