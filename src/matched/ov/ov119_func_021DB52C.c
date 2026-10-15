/*
 * function: POKETRADE_PROC_PollGridKeys
 * address: 0x021DB52C
 * packet: pkt_ov119_021DB52C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetRepeat 0x0203633C arm
 *   func_020355D8 0x020355D8 arm
 *   POKETRADE_PROC_ClampScrollColumn 0x021DD018 thumb ov119
 *   POKETRADE_2D_GetVisibleColumnRange 0x021E4E0C thumb ov119
 *   POKETRADE_PROC_IsSlotVisible 0x021DB4EC thumb ov119
 *   POKETRADE_PROC_GetSlotPosition 0x021DB4B4 thumb ov119
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   POKETRADE_PROC_RedrawAndSyncGrid 0x021DB7AC thumb ov119
 *   gScrollSnapPos 0x021E7FE0 data a4
 */
#include "../include/Obj00130.h"
extern unsigned int KEY_GetRepeat(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_020355D8(u8 v);
extern void POKETRADE_PROC_ClampScrollColumn(char *, int);
extern int POKETRADE_2D_GetVisibleColumnRange(char *, int *);
extern int POKETRADE_PROC_IsSlotVisible(char *, int);
extern int POKETRADE_PROC_GetSlotPosition(int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void POKETRADE_PROC_RedrawAndSyncGrid(char *, int, int);
extern const int gScrollSnapPos[];
void POKETRADE_PROC_PollGridKeys(char *p)
{
    int changed = 0;
    int i, v;
    unsigned int k = KEY_GetRepeat();
    if (((struct Obj00130 *)p)->fF60 != 0)
        return;
    if (k & 0x100) {
        func_020355D8(0);
        for (i = 0; i < ((struct Obj00130 *)p)->f630 + 1; i++) {
            if (gScrollSnapPos[i] > ((struct Obj00130 *)p)->f107C) {
                ((struct Obj00130 *)p)->f107C = gScrollSnapPos[i];
                changed = 1;
                break;
            }
        }
        if (!changed) {
            changed = 1;
            ((struct Obj00130 *)p)->f107C = gScrollSnapPos[0];
        }
        POKETRADE_PROC_ClampScrollColumn(p, changed);
    } else if (k & 0x200) {
        func_020355D8(0);
        for (i = ((struct Obj00130 *)p)->f630; i >= 0; i--) {
            if (gScrollSnapPos[i] < ((struct Obj00130 *)p)->f107C) {
                ((struct Obj00130 *)p)->f107C = gScrollSnapPos[i];
                changed = 1;
                break;
            }
        }
        if (!changed) {
            changed = 1;
            ((struct Obj00130 *)p)->f107C = gScrollSnapPos[((struct Obj00130 *)p)->f630];
        }
        POKETRADE_PROC_ClampScrollColumn(p, changed);
    } else if (KEY_GetRepeat() == 0x40) {
        func_020355D8(0);
        if (POKETRADE_2D_GetVisibleColumnRange(p, &v) == 0)
            ((struct Obj00130 *)p)->fF74 = v;
        if (--((struct Obj00130 *)p)->fF78 < 0) {
            if (((struct Obj00130 *)p)->fF74 < 2)
                ((struct Obj00130 *)p)->fF78 = 2;
            else
                ((struct Obj00130 *)p)->fF78 = 4;
        }
        ((struct Obj00130 *)p)->f1080 = ((struct Obj00130 *)p)->f1080 - 1;
        changed = 1;
    } else if (KEY_GetRepeat() == 0x80) {
        int x;
        func_020355D8(0);
        if (POKETRADE_2D_GetVisibleColumnRange(p, &v) == 0)
            ((struct Obj00130 *)p)->fF74 = v;
        x = ++((struct Obj00130 *)p)->fF78;
        if (((struct Obj00130 *)p)->fF74 < 2) {
            if (x >= 3)
                ((struct Obj00130 *)p)->fF78 = 0;
        } else if (x >= 5)
            ((struct Obj00130 *)p)->fF78 = 0;
        ((struct Obj00130 *)p)->f1080 = ((struct Obj00130 *)p)->f1080 - 1;
        changed = 1;
    } else if (KEY_GetRepeat() == 0x10) {
        func_020355D8(0);
        ((struct Obj00130 *)p)->f1080 = ((struct Obj00130 *)p)->f1080 - 1;
        changed = 1;
        if (POKETRADE_2D_GetVisibleColumnRange(p, &v) == 0) {
            ((struct Obj00130 *)p)->fF74 = v;
        } else {
            ((struct Obj00130 *)p)->fF74 = ((struct Obj00130 *)p)->fF74 + 1;
            if (POKETRADE_PROC_IsSlotVisible(p, ((struct Obj00130 *)p)->fF74) == 0) {
                ((struct Obj00130 *)p)->f107C = POKETRADE_PROC_GetSlotPosition(((struct Obj00130 *)p)->fF74 + 1) - 0x100;
                ((struct Obj00130 *)p)->f1080 = -1;
            }
        }
        if (((struct Obj00130 *)p)->fF74 >= ((struct Obj00130 *)p)->f634)
            ((struct Obj00130 *)p)->fF74 = 0;
        if (((struct Obj00130 *)p)->fF74 < 2 && ((struct Obj00130 *)p)->fF78 >= 3)
            ((struct Obj00130 *)p)->fF78 = 2;
    } else if (KEY_GetRepeat() == 0x20) {
        func_020355D8(0);
        ((struct Obj00130 *)p)->f1080 = ((struct Obj00130 *)p)->f1080 + 1;
        changed = 1;
        if (POKETRADE_2D_GetVisibleColumnRange(p, &v) == 0) {
            ((struct Obj00130 *)p)->fF74 = v;
        } else {
            ((struct Obj00130 *)p)->fF74 = ((struct Obj00130 *)p)->fF74 - 1;
            if (((struct Obj00130 *)p)->fF74 < 0)
                ((struct Obj00130 *)p)->fF74 = ((struct Obj00130 *)p)->f634 - 1;
            if (POKETRADE_PROC_IsSlotVisible(p, ((struct Obj00130 *)p)->fF74) == 0) {
                ((struct Obj00130 *)p)->f107C = POKETRADE_PROC_GetSlotPosition(((struct Obj00130 *)p)->fF74);
                ((struct Obj00130 *)p)->f1080 = -1;
            }
        }
        if (((struct Obj00130 *)p)->fF74 < 0)
            ((struct Obj00130 *)p)->fF74 = ((struct Obj00130 *)p)->f634 - 1;
        if (((struct Obj00130 *)p)->fF74 < 2 && ((struct Obj00130 *)p)->fF78 >= 3)
            ((struct Obj00130 *)p)->fF78 = 2;
    }
    if (changed) {
        ((struct Obj00130 *)p)->f1084 = 1;
        GFL_USE_PlaySeDefaultVolume(0x548);
        POKETRADE_PROC_RedrawAndSyncGrid(p, 0, 1);
    }
}
