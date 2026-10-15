/*
 * function: BOX2_MAIN_SetBoxForm
 * address: 0x021DEFF8
 * packet: pkt_ov170_021DEFF8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are zero alignment padding.
 * symbols:
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb ov170
 *   POKE_TOOL_DecodeBoxParam 0x02017DBC thumb
 *   BOX2_MAIN_CreateSummary 0x021DEDD8 thumb ov170
 *   BOX2_SEQ_LoadMonIconActor 0x021ECCCC thumb ov170
 *   BOX2_SEQ_ShowHandSlotB 0x021ED028 thumb ov170
 *   BOX2_SEQ_DeleteTextEntries 0x021EB2A4 thumb ov170
 *   BOX2_MAIN_DeleteHandle 0x021DEF58 thumb ov170
 *   POKE_TOOL_EncodeBoxParam 0x02017DE4 thumb
 */
#include "../include/Obj00000.h"
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
typedef unsigned int   u32;
struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern void *BOX2_MAIN_CreateSummary(void *p);
extern void BOX2_SEQ_LoadMonIconActor(char *p, void **mon, int index);
extern void BOX2_SEQ_ShowHandSlotB(char *p, unsigned char *q);
typedef unsigned char  u8;
extern void BOX2_SEQ_DeleteTextEntries(u8 *p, int a);
extern void BOX2_MAIN_DeleteHandle(void *s);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
void BOX2_MAIN_SetBoxForm(char *p, unsigned b)
{
    void *mon;
    void *s;
    int state;
    mon = (void *)BOX2_MAIN_GetMonAt((void ***)p, ((struct Obj00000 *)p)->f14, b);
    state = POKE_TOOL_DecodeBoxParam(mon);
    s = BOX2_MAIN_CreateSummary(mon);
    BOX2_SEQ_LoadMonIconActor(p, s, 11);
    BOX2_SEQ_ShowHandSlotB(((struct Obj00000 *)p)->f2C, s);
    BOX2_SEQ_DeleteTextEntries((u8 *)p, (int)s);
    BOX2_MAIN_DeleteHandle(s);
    POKE_TOOL_EncodeBoxParam(mon, state);
}
