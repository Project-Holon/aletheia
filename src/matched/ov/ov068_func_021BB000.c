/*
 * function: OPTION_MENU_StepSetting
 * address:  0x021BB000
 * packet:   pkt_ov068_021BB000
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The three 0x021BB57x pool words and the two 0x021BB70x words are separate
 * pool entries in the original, so each is its own extern.
 *
 * symbols:
 *   gOptionMenuSettingRows     0x021BB570  data  a2
 *   gOptionMenuSettingRowChoiceCount     0x021BB572  data  a2
 *   gOptionMenuSettingRowChoices     0x021BB574  data  a4
 *   gOptionMenuChoices     0x021BB704  data  a4
 *   gOptionMenuChoiceValues     0x021BB708  data  a4
 *   OPTION_MENU_WriteSettings  0x021BAFA8  thumb  ov068
 */

#include "../include/G__anon_Entry.h"

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 cnt;
    u8  list[4];
} Tab;

typedef struct {
    u32 f0;
    u32 f4;
    u32 pad[4];
} Ent;

extern Tab gOptionMenuSettingRows[];
extern u16 gOptionMenuSettingRowChoiceCount[];
extern u8  gOptionMenuSettingRowChoices[];
extern struct _anon_Entry gOptionMenuChoices[];
extern Ent gOptionMenuChoiceValues[];
extern void OPTION_MENU_WriteSettings(u8 *p);

void OPTION_MENU_StepSetting(u8 *p, int i, int delta)
{
    int j;
    int k;
    int n;
    Tab *t;
    int off = i << 3;
    s8 idx;
    int t2;
    int v = -1;

    n = *(u16 *)((u8 *)gOptionMenuSettingRowChoiceCount + off);
    j = 0;
    if (n > 0) {
        do {
            u8 cur;
            u32 f;

            t = (Tab *)((u8 *)gOptionMenuSettingRows + off);
            cur = p[i];

            v = t->list[j];
            f = gOptionMenuChoices[v].value;
            if (f == cur) {
                break;
            }
            j++;
        } while (j < t->cnt);
    }
    t2 = (s8)(v - gOptionMenuSettingRowChoices[(u32)i << 3]);
    t2 = (s8)(t2 + delta);
    idx = (s8)(t2 > n - 1 ? n - 1 : (t2 < 0 ? 0 : t2));
    k = (gOptionMenuSettingRowChoices + off)[idx];
    if (p[i] != gOptionMenuChoiceValues[k].f0) {
        p[i] = gOptionMenuChoiceValues[k].f0;
        p[5] = k;
        OPTION_MENU_WriteSettings(p);
    }
}
