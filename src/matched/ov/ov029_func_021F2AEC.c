/*
 * function: C_GEAR_SetCellKind
 * address:  0x021F2AEC
 * packet:   pkt_ov029_021F2AEC
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   C_GEAR_GetCellKind  0x021F2B9C  thumb  ov029
 *   C_GEAR_IsCellMarked  0x021F2BB8  thumb  ov029
 *   C_GEAR_IsCellKind  0x021F2BD4  thumb  ov029
 *   C_GEAR_DrawTile  0x021F1290  thumb  ov029
 *   func_020091AC  0x020091AC  thumb
 *   func_020409B4  0x020409B4  arm
 *   C_GEAR_UpdateTileMarkers  0x021F20AC  thumb  ov029
 */

extern unsigned int C_GEAR_GetCellKind(unsigned char *p, int row, int col);
typedef unsigned char  u8;
struct Sub020090B0Obj;
extern int C_GEAR_IsCellMarked(u8 *p, int row, int col);
extern int C_GEAR_IsCellKind(u8 *p, int row, int col, int kind);
extern void C_GEAR_DrawTile(void *q, int a, int b, int c);
extern void func_020091AC(struct Sub020090B0Obj *obj, int row, int col, int kind, int marked, int flagged);
typedef unsigned int   u32;
extern void func_020409B4(u32 index);
extern void C_GEAR_UpdateTileMarkers(char *p);

void C_GEAR_SetCellKind(unsigned char *p, int a1, int a2, int a3, int k)
{
    int j;
    int i;

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 9; i++) {
            if (k == C_GEAR_GetCellKind(p, i, j)) {
                if (C_GEAR_IsCellMarked((u8 *)p, i, j) != 0) {
                    func_020091AC((struct Sub020090B0Obj *)a1, i, j, k, 0, 1);
                    C_GEAR_DrawTile((void *)p, i, j, k);
                } else if (C_GEAR_IsCellKind((u8 *)p, i, j, k) != 0) {
                    func_020091AC((struct Sub020090B0Obj *)a1, i, j, k, 0, 0);
                }
            }
        }
    }
    func_020091AC((struct Sub020090B0Obj *)a1, a2, a3, k, 1, 0);
    C_GEAR_DrawTile((void *)p, a2, a3, k);
    func_020409B4(4);
    C_GEAR_UpdateTileMarkers((char *)p);
}
