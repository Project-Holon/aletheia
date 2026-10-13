/*
 * function: STARTMENU_SaveEraseStepTeardown
 * address:  0x021BCF18
 * packet:   pkt_ov088_021BCF18
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
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   STARTMENU_SaveEraseStopVblankTask  0x021BD10C  thumb  ov088
 *   STARTMENU_SaveEraseDeleteWindow  0x021BD0C8  thumb  ov088
 *   STARTMENU_SaveEraseFreeResources  0x021BD04C  thumb  ov088
 *   STARTMENU_SaveEraseExitGraphics  0x021BCFD4  thumb  ov088
 */

typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
extern void STARTMENU_SaveEraseStopVblankTask(int *p);
extern void STARTMENU_SaveEraseDeleteWindow(unsigned char *p);
extern void STARTMENU_SaveEraseFreeResources(unsigned char *p);
extern void STARTMENU_SaveEraseExitGraphics(void);

void STARTMENU_SaveEraseStepTeardown(void *p, int *st)
{
    if (WIPE_SYS_EndCheck() == 1) {
        STARTMENU_SaveEraseStopVblankTask(p);
        STARTMENU_SaveEraseDeleteWindow(p);
        STARTMENU_SaveEraseFreeResources(p);
        STARTMENU_SaveEraseExitGraphics();
        *st = 8;
    }
}
