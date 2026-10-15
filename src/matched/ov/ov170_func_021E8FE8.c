/*
 * function: BOX2_SEQ_OpenYesNo
 * address:  0x021E8FE8
 * packet:   pkt_ov170_021E8FE8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_OpenTaskMenu 0x021DCF58 thumb
 *   KEY_SetRepeatSpeed 0x02036270 arm
 *
 * Opens the yes/no menu with the cursor on sel and enters state 7.
 */

extern void BOX2_MAIN_OpenTaskMenu(unsigned char *p, int sel);
extern int KEY_SetRepeatSpeed(int a0, int a1);

#define WORK(p) (*(char **)((p) + 0x2C))

int BOX2_SEQ_OpenYesNo(unsigned char *p, int sel)
{
    *(unsigned short *)(WORK(p) + 0x1A4) = sel;
    if (sel == 1)
        BOX2_MAIN_OpenTaskMenu(p, 1);
    else
        BOX2_MAIN_OpenTaskMenu(p, 0);
    KEY_SetRepeatSpeed(*(unsigned *)(WORK(p) + 0x4C), *(unsigned *)(WORK(p) + 0x50));
    return 7;
}
