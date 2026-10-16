/*
 * unit: yes
 * function: ZUKAN_INFO_ClearDisplay
 * address: 0x021BA4CC
 * packet: pkt_ov206_021BA4CC
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_INFO_ClearSlotWindows 0x021BAF50 thumb ov206
 *   ZUKAN_INFO_DeleteWindows 0x021BA934 thumb ov206
 *   ZUKAN_INFO_DeleteActorPair 0x021BBBD8 thumb ov206
 *   ZUKAN_INFO_DeleteRow 0x021BB92C thumb ov206
 */
#include "../include/Obj00173.h"
extern void ZUKAN_INFO_ClearSlotWindows(char *p);
extern void ZUKAN_INFO_DeleteWindows(char *p);
struct S;
extern void ZUKAN_INFO_DeleteActorPair(struct S *p, int i);
extern void ZUKAN_INFO_DeleteRow(char *p, int index);
void ZUKAN_INFO_ClearDisplay(char *p)
{
    ZUKAN_INFO_ClearSlotWindows(p);
    ZUKAN_INFO_DeleteWindows(p);
    ZUKAN_INFO_DeleteActorPair((struct S *)p,((struct Obj00173 *)p)->f190);
    ZUKAN_INFO_DeleteRow(p,((struct Obj00173 *)p)->fE0);
}
