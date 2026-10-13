/*
 * function: P_STA_SKILL_DeleteObjects
 * address: 0x021D9BD4
 * packet: pkt_ov131_021D9BD4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   P_STA_SKILL_DeleteSlotObjects 0x021DB7B8 thumb ov131
 *   func_0204B3B4 0x0204B3B4 arm
 */
#include "../include/Obj05396.h"
typedef unsigned char u8;
extern void P_STA_SKILL_DeleteSlotObjects(void *, void *, u8 *);
struct Obj;
extern void func_0204B3B4(struct Obj *p);
void P_STA_SKILL_DeleteObjects(void *a, u8 *p)
{
    u8 i;
    for (i = 0; i < p[0x2b]; i++)
        P_STA_SKILL_DeleteSlotObjects(a, p, p + 0xb0 + i * 24);
    func_0204B3B4(((struct Obj05396 *)p)->f90);
    func_0204B3B4(((struct Obj05396 *)p)->f94);
    func_0204B3B4(((struct Obj05396 *)p)->f98);
    func_0204B3B4(((struct Obj05396 *)p)->f9C);
    func_0204B3B4(((struct Obj05396 *)p)->fA0);
}
