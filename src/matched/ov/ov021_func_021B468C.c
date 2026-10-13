/*
 * function: SCRCMD_PROC_FLD_OnListCursorMove
 * address:  0x021B468C
 * packet:   pkt_ov021_021B468C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENULIST_GetUserData 0x02020D0C thumb
 *   BMP_MENULIST_GetPos 0x020202FC thumb
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   SCRCMD_PROC_FLD_PrintItemDescription 0x021B4264 thumb ov021
 *   SCRCMD_PROC_FLD_UpdateItemIcon 0x021B3D60 thumb ov021
 */
#include "../include/Obj03132.h"

typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned char  u8;
struct Obj;
struct Vec2;
extern u32 BMP_MENULIST_GetUserData(u8 *p);
extern void BMP_MENULIST_GetPos(struct Obj *obj, u16 *a, u16 *b);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void SCRCMD_PROC_FLD_PrintItemDescription(char *w, u32 a);
extern void SCRCMD_PROC_FLD_UpdateItemIcon(char *w, u32 a);

void SCRCMD_PROC_FLD_OnListCursorMove(u32 a, u32 idx)
{
    u16 v[4];
    char *w;
    char *t;

    w = (char *)BMP_MENULIST_GetUserData((void *)a);
    BMP_MENULIST_GetPos((struct Obj *)a, &v[1], &v[0]);
    v[2] = 0xAC;
    v[3] = v[0] * 16 + 0x16;
    CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj03132 *)w)->f1C0), (const struct Vec2 *)(&v[2]), 0);
    if (idx < 0x28) {
        t = w + 0x20;
        SCRCMD_PROC_FLD_PrintItemDescription(w, *(u16 *)(t + idx * 8));
        SCRCMD_PROC_FLD_UpdateItemIcon(w, *(u16 *)(t + idx * 8));
    } else {
        SCRCMD_PROC_FLD_PrintItemDescription(w, 0xFFFF);
        SCRCMD_PROC_FLD_UpdateItemIcon(w, 0xFFFF);
    }
}
