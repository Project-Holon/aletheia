/*
 * function: BEACON_VIEW_IconWaitTask
 * address:  0x021F1EAC
 * packet:   pkt_ov032_021F1EAC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_IconWaitTask 0x021F1EAC thumb
 *   BEACON_VIEW_PrintEntryFrames 0x021F1080 thumb
 *   BEACON_VIEW_SetEntryStatusVisible 0x021F0ED0 thumb
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj02113.h"
#include "../include/Obj20437.h"
#include "../include/Obj20438.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void BEACON_VIEW_PrintEntryFrames(char *p, char *q, int r, int t);
extern void BEACON_VIEW_SetEntryStatusVisible(char *q, int a);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *n);

void BEACON_VIEW_IconWaitTask(void *task, u8 *s)
{
    if (s[0] == 0) {
        u8 c = s[1];
        s[1] = c - 1;
        if (c != 0)
            return;
        if (((struct Obj02113 *)s)->fC == 1 || ((struct Obj02113 *)s)->fC == 0x18 || ((struct Obj02113 *)s)->fC == 0x31) {
            BEACON_VIEW_PrintEntryFrames((char *)(((struct Obj02113 *)s)->f10), (char *)(*(u32 *)&((struct Obj02113 *)s)->f8), 1, 0);
            s[0]++;
            return;
        }
    } else {
        if (((struct Obj20437 *)(*(char * *)&((struct Obj02113 *)s)->f8))->f2C != 0)
            return;
    }
    ((struct Obj20438 *)(*(char * *)&((struct Obj02113 *)s)->f8))->f30 = 0;
    BEACON_VIEW_SetEntryStatusVisible(*(char * *)&((struct Obj02113 *)s)->f8, 0);
    TCBL_DeleteTask(task);
}
