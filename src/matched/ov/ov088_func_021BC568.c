/*
 * function: STARTMENU_ConfigPromptMain
 * address:  0x021BC568
 * packet:   pkt_ov088_021BC568
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STARTMENU_ConfigPromptReadInput  0x021BC8AC  thumb  ov088
 *   CONFIG_SetAppliedFlag  0x020083EC  thumb
 *   STARTMENU_ConfigPromptDeleteWindows  0x021BC84C  thumb  ov088
 *   STARTMENU_ConfigPromptDrawQuestion  0x021BC75C  thumb  ov088
 *   func_0200854C  0x0200854C  thumb
 *   CONFIG_SetBattleFlag  0x02008450  thumb
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   STARTMENU_ConfigPromptPulseColor  0x021BC944  thumb  ov088
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int STARTMENU_ConfigPromptReadInput(u8 *p);
struct Flags02008450;
extern void CONFIG_SetAppliedFlag(unsigned short *p, unsigned int v);
extern void STARTMENU_ConfigPromptDeleteWindows(u8 *p);
extern void STARTMENU_ConfigPromptDrawQuestion(u8 *p);
struct Sub0200852CObj;
extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);
extern void CONFIG_SetBattleFlag(struct Flags02008450 *p, int on);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);
typedef signed int     s32;
struct W;
extern s32 STARTMENU_ConfigPromptPulseColor(struct W *w);

int STARTMENU_ConfigPromptMain(int a, int b, int *s, int *q)
{
    int r;

    switch (q[1]) {
    case 0:
        r = STARTMENU_ConfigPromptReadInput((u8 *)q);
        if (r != 0) {
            if (r == 1)
                CONFIG_SetAppliedFlag((void *)s[1], 0);
            else
                CONFIG_SetAppliedFlag((void *)s[1], 1);
            STARTMENU_ConfigPromptDeleteWindows((u8 *)q);
            q[1] = 1;
            STARTMENU_ConfigPromptDrawQuestion((u8 *)q);
        }
        break;
    case 1:
        r = STARTMENU_ConfigPromptReadInput((u8 *)q);
        if (r != 0) {
            if (r == 1)
                func_0200854C((struct Sub0200852CObj *)s[2], 0);
            else
                func_0200854C((struct Sub0200852CObj *)s[2], 1);
            STARTMENU_ConfigPromptDeleteWindows((u8 *)q);
            q[1] = 2;
            STARTMENU_ConfigPromptDrawQuestion((u8 *)q);
        }
        break;
    case 2:
        r = STARTMENU_ConfigPromptReadInput((u8 *)q);
        if (r != 0) {
            if (r == 1)
                CONFIG_SetBattleFlag((void *)s[1], 1);
            else
                CONFIG_SetBattleFlag((void *)s[1], 0);
            WIPE_SYS_Start(0, 0, 0, 0, 0xc, 1, 0x39);
            q[1] = 3;
        }
        break;
    case 3:
        if (WIPE_SYS_EndCheck() == 1)
            return 1;
        break;
    }
    STARTMENU_ConfigPromptPulseColor((struct W *)q);
    return 0;
}
