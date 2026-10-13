/*
 * function: FIELD_GIMMICK_GATE_LoadNewsList
 * address:  0x021F3BC0
 * packet:   pkt_ov048_021F3BC0
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_GetArchiveFileCount  0x02049030  arm
 *   func_02030734  0x02030734  arm
 *   GIMMICK_OBJ_ELBOARD_ReadGateEntry  0x021F4DE4  thumb  ov048
 *   gGateSourceFileName     0x021F5224  data  ov048  a1
 */
#include "../include/Obj00377.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const char gGateSourceFileName[];

extern u32 ARC_TOOL_GetArchiveFileCount(u32 a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int GIMMICK_OBJ_ELBOARD_ReadGateEntry(int a, int b, int c);

void FIELD_GIMMICK_GATE_LoadNewsList(u8 *p)
{
    int n;
    int i;

    if (*(u8 * *)&((struct Obj00377 *)p)->f20 == 0) {
        n = ARC_TOOL_GetArchiveFileCount(0xa6);
        ((struct Obj00377 *)p)->f20 = func_02030734(((struct Obj00377 *)p)->f0, n * 0x24, 0, gGateSourceFileName, 0x4cb);
        for (i = 0; i < n; i++) {
            GIMMICK_OBJ_ELBOARD_ReadGateEntry((int)(*(u8 * *)&((struct Obj00377 *)p)->f20 + i * 0x24), 0xa6, i);
        }
        p[0x24] = n;
    }
}
