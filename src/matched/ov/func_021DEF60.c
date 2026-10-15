/*
 * function: BOX2_MAIN_SetupSummary
 * address:  0x021DEF60
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_LoadMonIconActor  0x021ECCCC  thumb  ov170
 *   BOX2_SEQ_ShowHandSlotB  0x021ED028  thumb  ov170
 *   BOX2_SEQ_DeleteTextEntries  0x021EB2A4  thumb  ov170
 *   BOX2_MAIN_SetBodySlots  0x021DF11C  thumb  ov170
 *   BOX2_MAIN_SetupSummaryActors  0x021DF144  thumb  ov170
 *   BG_SYS_ResetSlot  0x02041EE4  arm  arm9
 *
 * Six-step handover: stage 0xb, rebuild, refresh, push the 0x10
 *   tag word, re-tag, then release handle 3.
 */
#include "../include/Obj00000.h"
#include "../include/Obj18457.h"


extern void BOX2_SEQ_LoadMonIconActor(char *p, void **mon, int index);
extern void BOX2_SEQ_ShowHandSlotB(char *p, unsigned char *q);
typedef unsigned char  u8;
extern void BOX2_SEQ_DeleteTextEntries(u8 *p, int a);
extern void BOX2_MAIN_SetBodySlots(char *, int);
extern void BOX2_MAIN_SetupSummaryActors(int, int);
typedef unsigned int   u32;
extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);
void BOX2_MAIN_SetupSummary(char *p, int a)
{
    BOX2_SEQ_LoadMonIconActor(p, (void **)a, 0xb);
    BOX2_SEQ_ShowHandSlotB((char *)(*(int *)&((struct Obj00000 *)p)->f2C), (unsigned char *)a);
    BOX2_SEQ_DeleteTextEntries((u8 *)p, a);
    BOX2_MAIN_SetBodySlots(p, ((struct Obj18457 *)a)->f10);
    BOX2_MAIN_SetupSummaryActors(*(int *)&((struct Obj00000 *)p)->f2C, a);
    BG_SYS_ResetSlot(5, 3, 0);
}
