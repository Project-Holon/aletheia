/*
 * function: STARTMENU_SaveEraseMain
 * address:  0x021BCCF4
 * packet:   pkt_ov088_021BCCF4
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the extent runs two bytes long (trailing padding pair).
 *
 * symbols:
 *   STARTMENU_SaveEraseStepSetup  0x021BCD88  thumb  ov088
 *   STARTMENU_SaveEraseStepShowPrompt  0x021BCDB4  thumb  ov088
 *   STARTMENU_SaveEraseStepOpenFirstYesNo  0x021BCDD0  thumb  ov088
 *   STARTMENU_SaveEraseStepFirstConfirm  0x021BCDEC  thumb  ov088
 *   STARTMENU_SaveEraseStepOpenSecondYesNo  0x021BCE20  thumb  ov088
 *   STARTMENU_SaveEraseStepSecondConfirm  0x021BCE3C  thumb  ov088
 *   STARTMENU_SaveEraseStepErase  0x021BCE80  thumb  ov088
 *   STARTMENU_SaveEraseStepTeardown  0x021BCF18  thumb  ov088
 */

extern void STARTMENU_SaveEraseStepSetup(void *, int *);
extern void STARTMENU_SaveEraseStepShowPrompt(void *, int *);
extern void STARTMENU_SaveEraseStepOpenFirstYesNo(void *, int *);
extern void STARTMENU_SaveEraseStepFirstConfirm(void *, int *);
extern void STARTMENU_SaveEraseStepOpenSecondYesNo(void *, int *);
extern void STARTMENU_SaveEraseStepSecondConfirm(char *p, int *out);
typedef unsigned char  u8;
extern void STARTMENU_SaveEraseStepErase(u8 *p, int *a1);
extern void STARTMENU_SaveEraseStepTeardown(void *, int *);

int STARTMENU_SaveEraseMain(int a, int *st, int c, void *p)
{
    switch (*st) {
    case 0:
        STARTMENU_SaveEraseStepSetup(p, st);
        break;
    case 1:
        STARTMENU_SaveEraseStepShowPrompt(p, st);
        break;
    case 2:
        STARTMENU_SaveEraseStepOpenFirstYesNo(p, st);
        break;
    case 3:
        STARTMENU_SaveEraseStepFirstConfirm(p, st);
        break;
    case 4:
        STARTMENU_SaveEraseStepOpenSecondYesNo(p, st);
        break;
    case 5:
        STARTMENU_SaveEraseStepSecondConfirm(p, st);
        break;
    case 6:
        STARTMENU_SaveEraseStepErase(p, st);
        break;
    case 7:
        STARTMENU_SaveEraseStepTeardown(p, st);
        break;
    case 8:
        return 1;
    }
    return 0;
}
