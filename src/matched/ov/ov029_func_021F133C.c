/*
 * function: C_GEAR_FindCellOfKind
 * address:  0x021F133C
 * packet:   pkt_ov029_021F133C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   C_GEAR_GetCellKind  0x021F2B9C  thumb  ov029
 *   C_GEAR_IsCellMarked  0x021F2BB8  thumb  ov029
 *   C_GEAR_IsCellKind  0x021F2BD4  thumb  ov029
 *   C_GEAR_TileToScreen  0x021F0D14  thumb  ov029
 *   C_GEAR_DrawTile  0x021F1290  thumb  ov029
 *   func_020091AC  0x020091AC  thumb
 *   BG_SYS_PushTile  0x020409B4  arm
 */
#include "../include/Obj00042.h"

extern unsigned int C_GEAR_GetCellKind(unsigned char *p, int row, int col);
extern int C_GEAR_IsCellMarked(unsigned char *p, int row, int col);
typedef unsigned char  u8;
extern int C_GEAR_IsCellKind(u8 *p, int row, int col, int kind);
extern void C_GEAR_TileToScreen(int, int, int *, int *);
extern void C_GEAR_DrawTile(void *, int, int, int);
struct Sub020090B0Obj;
extern void func_020091AC(struct Sub020090B0Obj *obj, int row, int col, int kind, int marked, int flagged);
typedef unsigned int   u32;
extern void BG_SYS_PushTile(u32 index);

int C_GEAR_FindCellOfKind(char *p, int v, int *o1, int *o2)
{
    int a = 0;
    int b = 0;
    int found = 0;
    int i;
    int j;

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 9; i++) {
            if (v == C_GEAR_GetCellKind((unsigned char *)p, i, j)) {
                if (found == 0) {
                    a = i;
                    b = j;
                    found = 1;
                }
                if (C_GEAR_IsCellMarked((unsigned char *)p, i, j)) {
                    C_GEAR_TileToScreen(i, j, o1, o2);
                    return 1;
                }
                if (C_GEAR_IsCellKind((u8 *)p, i, j, v)) {
                    a = i;
                    b = j;
                    found = 1;
                }
            }
        }
    }
    if (found) {
        C_GEAR_TileToScreen(a, b, o1, o2);
        func_020091AC((struct Sub020090B0Obj *)(*(int *)&((struct Obj00042 *)p)->f20), a, b, v, 1, 0);
        C_GEAR_DrawTile(p, a, b, v);
        BG_SYS_PushTile(4);
        return 1;
    }
    return 0;
}
