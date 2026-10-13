/*
 * function: STARTMENU_StateSelectRow
 * address:  0x021BA338
 * packet:   pkt_ov088_021BA338
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BLINK_PALANM_Update  0x0202EA40  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   STARTMENU_BeginSelectAnim  0x021BC0AC  thumb  ov088
 *   func_0200C2F0  0x0200C2F0  thumb
 *   STARTMENU_BeginFadeIn  0x021BC080  thumb  ov088
 *   KEY_GetRepeat  0x0203633C  arm
 *   STARTMENU_MoveCursor  0x021BB890  thumb  ov088
 */
#include "../include/Obj00271.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Row;
typedef signed int     s32;
extern s32 BLINK_PALANM_Update(struct Row *p);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern int STARTMENU_BeginSelectAnim(char *p, int v);
struct Blk34;
extern void func_0200C2F0(struct Blk34 *p, u32 i, u8 v);
extern int STARTMENU_BeginFadeIn(char *p, int v);
extern unsigned int KEY_GetRepeat(void);
extern int STARTMENU_MoveCursor(char *p, int d);

int STARTMENU_StateSelectRow(char *p)
{
    BLINK_PALANM_Update(((struct Obj00271 *)p)->f11C);
    if (KEY_GetTrg() & 1) {
        GFL_USE_PlaySeDefaultVolume(0x54c);
        switch (*(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120)) {
        case 0:
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return STARTMENU_BeginSelectAnim(p, 7);
        case 1:
            return STARTMENU_BeginSelectAnim(p, 8);
        case 2:
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return STARTMENU_BeginSelectAnim(p, 11);
        case 3:
            func_0200C2F0((struct Blk34 *)(((struct Obj00271 *)p)->f8), 1, 2);
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return STARTMENU_BeginSelectAnim(p, 11);
        case 4:
            func_0200C2F0((struct Blk34 *)(((struct Obj00271 *)p)->f8), 2, 2);
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return STARTMENU_BeginSelectAnim(p, 11);
        case 7:
            func_0200C2F0((struct Blk34 *)(((struct Obj00271 *)p)->f8), 3, 2);
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return STARTMENU_BeginSelectAnim(p, 11);
        case 5:
            return STARTMENU_BeginSelectAnim(p, 9);
        case 6:
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return STARTMENU_BeginSelectAnim(p, 11);
        }
    }
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        ((struct Obj00271 *)p)->f129 = 8;
        return STARTMENU_BeginFadeIn(p, 1);
    }
    if (KEY_GetRepeat() & 0x40) {
        if (STARTMENU_MoveCursor(p, -1) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            return 6;
        }
    }
    if (KEY_GetRepeat() & 0x80) {
        if (STARTMENU_MoveCursor(p, 1) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            return 6;
        }
    }
    return 5;
}
