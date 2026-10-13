/*
 * function: APP_TASKMENU_UpdateTouch
 * address:  0x02027E3C
 * packet:   pkt_02027D44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * app_taskmenu.c: the touch handler.  Builds a stack table of one
 * eight-pixel-tall hit rectangle per menu entry (0xff-terminated), hands it
 * to TOUCHPANEL_HitTrg, and on a hit moves the cursor, repaints the old and the
 * new entry, and raises the confirm notification.
 *
 * symbols:
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   func_020355D8  0x020355D8  arm
 *   APP_TASKMENU_SetWinActive  0x02027B30  thumb
 *   func_020061E4  0x020061E4  thumb
 */
#include "../include/Obj00104.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int  TOUCHPANEL_HitTrg(const void *key);
extern void func_020355D8(u8 v);
struct S;
extern void APP_TASKMENU_SetWinActive(u32 a0, struct S *s, int mode);
extern void func_020061E4(u32 id);

void APP_TASKMENU_UpdateTouch(u8 *m)
{
    u8  rect[0x24];
    u32 top;
    u8  left;
    u8  i;
    int hit;
    int one;

    if (((struct Obj00104 *)m)->f2C == 0) {
        top  = m[0x30];
        left = m[0x31];
    } else {
        top = (u8)(m[0x30] - m[0x32]);
        left = (u8)(m[0x31] - m[0x33] * m[0x24]);
    }

    for (i = 0; i < m[0x24]; i++) {
        rect[i * 4 + 0] = (u8)((left << 3) + m[0x33] * 8 * i);
        rect[i * 4 + 1] = (u8)((left << 3) + m[0x33] * 8 * (i + 1));
        rect[i * 4 + 2] = (u8)(top << 3);
        rect[i * 4 + 3] = (u8)(((top + m[0x32]) << 3) - 1);
    }
    rect[i * 4] = 0xff;

    hit = TOUCHPANEL_HitTrg(rect);
    if (hit == ~0) {
        return;
    }
    one = 1;
    func_020355D8(one);
    APP_TASKMENU_SetWinActive(((u32 *)*(u32 * *)&((struct Obj00104 *)m)->f18)[m[0]], (struct S *)(*(u32 *)&((struct Obj00104 *)m)->f34), 0);
    m[0] = (u8)hit;
    *(int *)&((struct Obj00104 *)m)->fC = one;
    APP_TASKMENU_SetWinActive(((u32 *)*(u32 * *)&((struct Obj00104 *)m)->f18)[m[0]], (struct S *)(*(u32 *)&((struct Obj00104 *)m)->f34), one);
    if (m[0] == 0) {
        func_020061E4(0x54C);
        return;
    }
    if (*(int *)(*(u8 * *)&((struct Obj00104 *)m)->f1C + m[0] * 0xC + 8) == 1) {
        func_020061E4(0x551);
        return;
    }
    func_020061E4(0x54C);
}
