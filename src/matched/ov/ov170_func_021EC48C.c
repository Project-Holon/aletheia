/*
 * function: BOX2_SEQ_ShowSlotIcon
 * address:  0x021EC48C
 * packet:   pkt_ov170_021EC48C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb
 *   BOX2_SEQ_LoadIconResource 0x021EC45C thumb
 *
 * Hides window win, and when slot (box, pos) holds something shows its icon
 * there again.  The image narrows both the slot and the box to 16 bits
 * before BOX2_MAIN_GetPartyValueAt, so its box parameter is declared unsigned short here;
 * the callee body only forwards it and cannot show the width.
 */

extern void BOX2_SEQ_SetActorDrawEnable(char *w, int i, int v);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
extern void BOX2_SEQ_LoadIconResource(unsigned char *p, void *a, int i);

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_SEQ_ShowSlotIcon(unsigned char *p, int box, int pos, int win)
{
    char *w = WORK(p);
    BOX2_SEQ_SetActorDrawEnable(WORK(p), win, 0);
    if (BOX2_MAIN_GetPartyValueAt((void ***)p, pos, (unsigned short)box, 0xA9, 0)) {
        BOX2_SEQ_LoadIconResource(p, (void *)BOX2_MAIN_GetMonAt((void ***)p, box, pos), win);
        BOX2_SEQ_SetActorDrawEnable(w, win, 1);
    }
}
