/*
 * function: OPTION_MENU_StateFadeIn
 * address:  0x021BB148
 * packet:   pkt_ov068_021BB148
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   OPTION_MENU_SetRunnerCallback  0x021BB138  thumb  ov068
 *   OPTION_MENU_StateMain  0x021BB1C4  thumb  ov068
 */

typedef unsigned int u32;

typedef signed int     s32;
typedef unsigned char  u8;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern void OPTION_MENU_SetRunnerCallback(void *p, int v);
extern void OPTION_MENU_StateMain(void *a, u32 *st, u8 *w);

void OPTION_MENU_StateFadeIn(void *unused, u32 *p)
{
    switch (*p) {
    case 0:
        FADE_Start(3, 16, 0, 0);
        *p = 1;
        break;
    case 1:
        if (FADE_IsActive() == 0) {
            *p = 2;
        }
        break;
    case 2:
        OPTION_MENU_SetRunnerCallback(unused, (int)OPTION_MENU_StateMain);
        break;
    }
}
