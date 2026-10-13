/*
 * function: STARTMENU_SaveEraseStepOpenSecondYesNo
 * address:  0x021BCE20
 * packet:   pkt_ov088_021BCE20
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the extent runs two bytes long (trailing padding pair).
 *
 * symbols:
 *   STARTMENU_SaveEraseUpdateMessage  0x021BD188  thumb  ov088
 *   STARTMENU_SaveEraseOpenYesNo  0x021BD1EC  thumb  ov088
 */

extern int STARTMENU_SaveEraseUpdateMessage(char *p);
extern void STARTMENU_SaveEraseOpenYesNo(unsigned char *p);

void STARTMENU_SaveEraseStepOpenSecondYesNo(void *p, int *st)
{
    if (STARTMENU_SaveEraseUpdateMessage(p) == 0) {
        STARTMENU_SaveEraseOpenYesNo(p);
        *st = 5;
    }
}
