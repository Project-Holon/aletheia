/*
 * function: BOX2_MAIN_ResetBoxView
 * address:  0x021DF040
 * packet:   pkt_ov170_021DF040
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_ClearTextWin 0x021EB324 thumb
 *   BOX2_MAIN_HideSlots 0x021DF128 thumb
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 */

extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
extern void BOX2_SEQ_ClearTextWin(char *w);
extern void BOX2_MAIN_HideSlots(int p);
typedef unsigned int   u32;
extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_MAIN_ResetBoxView(char *p)
{
    unsigned i;
    if (*(int *)(WORK(p) + 0x9EA0) != 0)
        BOX2_SEQ_SetActorDrawEnable(WORK(p), 0xB, 0);
    if (*(int *)(WORK(p) + 0x9EA4) != 0)
        BOX2_SEQ_SetActorDrawEnable(WORK(p), 0xC, 0);
    for (i = 0x1C; i < 0x2D; i++)
        BOX2_SEQ_SetActorDrawEnable(WORK(p), i, 0);
    BOX2_SEQ_ClearTextWin(WORK(p));
    BOX2_MAIN_HideSlots((int)WORK(p));
    BOX2_SEQ_SetActorDrawEnable(WORK(p), 0x19, 0);
    BOX2_SEQ_SetActorDrawEnable(WORK(p), 0x1A, 0);
    BOX2_SEQ_SetActorDrawEnable(WORK(p), 0x1B, 0);
    BG_SYS_ResetSlot(5, 3, 0xC0);
}
