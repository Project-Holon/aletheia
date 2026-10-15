/*
 * function: BEACON_VIEW_FadeTask
 * address:  0x021F1930
 * packet:   pkt_ov032_021F1930
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_FadeTask 0x021F1930 thumb
 *   BEACON_VIEW_ShowWindowText 0x021F0B80 thumb
 *   BEACON_VIEW_StartScrollStep 0x021F178C thumb
 *   BEACON_VIEW_CheckWindowTouch 0x021F0BA8 thumb
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj02751.h"
#include "../include/Obj20431.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void BEACON_VIEW_ShowWindowText(char *p, void *t, unsigned a);
extern void BEACON_VIEW_StartScrollStep(char *this, u8 a, int *p);
extern int BEACON_VIEW_CheckWindowTouch(u8 *s);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *n);

void BEACON_VIEW_FadeTask(void *task, u8 *s)
{
    if (((struct Obj02751 *)s)->f4 != 0)
        return;
    switch (s[0]) {
    case 0:
        BEACON_VIEW_ShowWindowText(*(char * *)&((struct Obj02751 *)s)->f8, (void *)(((struct Obj20431 *)(*(char * *)&((struct Obj02751 *)s)->f8))->f120), (unsigned int)(s + 4));
        s[0]++;
        return;
    case 1:
        BEACON_VIEW_StartScrollStep(*(char * *)&((struct Obj02751 *)s)->f8, 0, (int *)(s + 4));
        s[0]++;
        return;
    case 2:
        if (BEACON_VIEW_CheckWindowTouch(s + 1) != 0) {
            BEACON_VIEW_StartScrollStep(*(char * *)&((struct Obj02751 *)s)->f8, 1, (int *)(s + 4));
            s[0]++;
        }
        return;
    default:
        (**(int * *)&((struct Obj02751 *)s)->fC)--;
        TCBL_DeleteTask(task);
        return;
    }
}
