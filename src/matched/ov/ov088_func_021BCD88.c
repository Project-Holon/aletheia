/*
 * function: STARTMENU_SaveEraseStepSetup
 * address:  0x021BCD88
 * packet:   pkt_ov088_021BCD88
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
 *   STARTMENU_SaveEraseClearVram  0x021BCF44  thumb  ov088
 *   STARTMENU_SaveEraseSetupGraphics  0x021BCF6C  thumb  ov088
 *   STARTMENU_SaveEraseAllocResources  0x021BCFEC  thumb  ov088
 *   STARTMENU_SaveEraseCreateWindow  0x021BD078  thumb  ov088
 *   STARTMENU_SaveEraseStartVblankTask  0x021BD0F4  thumb  ov088
 *   STARTMENU_SaveEraseStartFadeIn  0x021BD21C  thumb  ov088
 */

extern void STARTMENU_SaveEraseClearVram(void);
extern void STARTMENU_SaveEraseSetupGraphics(void);
typedef unsigned char  u8;
extern void STARTMENU_SaveEraseAllocResources(u8 *p);
extern void STARTMENU_SaveEraseCreateWindow(int *p);
extern void STARTMENU_SaveEraseStartVblankTask(void **p);
extern void STARTMENU_SaveEraseStartFadeIn(void);

void STARTMENU_SaveEraseStepSetup(void *p, int *st)
{
    STARTMENU_SaveEraseClearVram();
    STARTMENU_SaveEraseSetupGraphics();
    STARTMENU_SaveEraseAllocResources(p);
    STARTMENU_SaveEraseCreateWindow(p);
    STARTMENU_SaveEraseStartVblankTask(p);
    STARTMENU_SaveEraseStartFadeIn();
    *st = 1;
}
