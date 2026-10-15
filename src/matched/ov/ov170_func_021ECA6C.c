/*
 * function: BOX2_SEQ_SetSlotActorsMode
 * address: 0x021ECA6C
 * packet: pkt_ov170_021ECA6C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_GetBoxValue 0x021DD908 thumb ov170
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb ov170
 *   BOX2_SEQ_SetActorObjMode 0x021EC060 thumb ov170
 */
#include "../include/Obj06551.h"
#include "../include/Obj24017.h"
typedef unsigned int   u32;
extern int BOX2_MAIN_GetBoxValue(char *p, u32 a);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***, unsigned short, int, unsigned, unsigned);
extern void BOX2_SEQ_SetActorObjMode(char *p, unsigned i, int b);
#define WORK(p) (*(char **)((p) + 0x2C))
#define WIN(p, i) (*(unsigned char *)(WORK(p) + (i) + 0x3DD2))
void BOX2_SEQ_SetSlotActorsMode(unsigned char *p, int flag, int i, unsigned end, int mode)
{
    if (mode == 1) {
        if (((struct Obj24017 *)(*(char * *)&((struct Obj06551 *)p)->f0))->f24 == 5) {
            for (; i < end; i++) {
                if (BOX2_MAIN_GetBoxValue((char *)p, i) == 1 && BOX2_MAIN_GetPartyValueAt((void ***)p, i, p[0x14], 0x4C, 0) == 0)
                    BOX2_SEQ_SetActorObjMode(WORK(p), WIN(p, i), 0);
                else
                    BOX2_SEQ_SetActorObjMode(WORK(p), WIN(p, i), 1);
            }
        } else {
            for (; i < end; i++) {
                if (BOX2_MAIN_GetPartyValueAt((void ***)p, i, p[0x14], 6, 0) == 0)
                    BOX2_SEQ_SetActorObjMode(WORK(p), WIN(p, i), 1);
                else
                    BOX2_SEQ_SetActorObjMode(WORK(p), WIN(p, i), 0);
            }
        }
    } else {
        for (; i < end; i++)
            BOX2_SEQ_SetActorObjMode(WORK(p), WIN(p, i), flag);
    }
}
