/*
 * function: APP_TASKMENU_UpdateMenu
 * address:  0x02027974
 * packet:   pkt_02027974
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_sound_system.c.  EXACT: all seven relocations resolve.  The calls to
 * APP_TASKMENU_UpdateKey and APP_TASKMENU_UpdateTouch carry on class sole-ref/code (each is the
 * only branch anywhere in the image to its target, and each target is exactly
 * a traced Thumb function start); APP_TASKMENU_UpdateTouch was additionally filed EXACT
 * in src/matched/ on 2026-09-21, which would carry that site on class matched
 * as well.
 * symbols:
 *   APP_TASKMENU_TransWinAfterPrint  0x020278F4  thumb
 *   APP_TASKMENU_UpdateKey  0x02027D44  thumb
 *   APP_TASKMENU_UpdateTouch  0x02027E3C  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   APP_TASKMENU_SetWinActive  0x02027B30  thumb
 *   APP_TASKMENU_UpdateCursorColor  0x02027B60  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct S;

typedef struct {
    u8   f00;
    u8   f01;
    u16  f02;
    u16  f04;
    u8   pad06[0x0c - 0x06];
    u32  f0c;
    u8   pad10[0x14 - 0x10];
    u32  f14;
    u32 *f18;
    u8   pad1c[0x34 - 0x1c];
    struct S *f34;
} Obj;

struct Menu;
extern void APP_TASKMENU_TransWinAfterPrint(u8 *p);
extern void APP_TASKMENU_UpdateKey(struct Menu *m);
extern void APP_TASKMENU_UpdateTouch(u8 *m);
extern u32  _u32_div_f(u32 a, u32 b);
extern void APP_TASKMENU_SetWinActive(u32 a, struct S *s, int mode);
extern void APP_TASKMENU_UpdateCursorColor(u16 *phase, u16 *out, u32 mode, u32 slot);

void APP_TASKMENU_UpdateMenu(Obj *p)
{
    u32 step;
    u16 *q;

    APP_TASKMENU_TransWinAfterPrint((u8 *)p);
    if (p->f0c == 0) {
        APP_TASKMENU_UpdateKey((struct Menu *)p);
        if (p->f0c == 0) {
            APP_TASKMENU_UpdateTouch((u8 *)p);
        }
    } else {
        step = _u32_div_f(4, p->f14);
        if ((u8)(_u32_div_f(p->f01, step) & 1) == 0) {
            APP_TASKMENU_SetWinActive(p->f18[p->f00], p->f34, 1);
        } else {
            APP_TASKMENU_SetWinActive(p->f18[p->f00], p->f34, 0);
        }
        p->f01 = (u8)(p->f01 + 1);
    }
    q = (u16 *)p->f34;
    APP_TASKMENU_UpdateCursorColor(&p->f02, &p->f04, (u8)q[0], (u8)q[1]);
}
