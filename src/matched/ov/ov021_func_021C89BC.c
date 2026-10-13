/*
 * function: FIELD_TILE_MOVE_SpinTaskMain
 * address:  0x021C89BC
 * packet:   pkt_ov021_021C89BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_TILE_MOVE_GetSpinTileAttr  0x021C8AAC  thumb  ov021
 *   FIELD_TILE_MOVE_HasSpinEntry  0x021C89A8  thumb  ov021
 *   FIELD_TILE_MOVE_SpinTick  0x021C8AD0  thumb  ov021
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FIELD_TILE_MOVE_SpinSelectEntry  0x021C8B48  thumb  ov021
 *   FIELD_TILE_MOVE_SpinIsBlocked  0x021C8B5C  thumb  ov021
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   FIELD_TILE_MOVE_SpinStartStep  0x021C8B14  thumb  ov021
 *   FIELD_TILE_MOVE_SpinFinish  0x021C8B78  thumb  ov021
 */

extern int FIELD_TILE_MOVE_GetSpinTileAttr(int *p);
typedef unsigned int   u32;
extern int FIELD_TILE_MOVE_HasSpinEntry(u32 a);
extern void FIELD_TILE_MOVE_SpinTick(int *p);
extern int FLDMMDL_CheckEndAcmd(int a);
extern void FIELD_TILE_MOVE_SpinSelectEntry(int *p);
extern int FIELD_TILE_MOVE_SpinIsBlocked(u32 a);
extern int GFL_USE_GetSeSlot(u32 a0);
extern void func_020061F8(int a);
extern void FIELD_TILE_MOVE_SpinStartStep(int *p);
extern void FIELD_TILE_MOVE_SpinFinish(int *p);

int FIELD_TILE_MOVE_SpinTaskMain(int a, int *st, int *p)
{
    switch (*st) {
    case 0:
        if (FIELD_TILE_MOVE_HasSpinEntry(FIELD_TILE_MOVE_GetSpinTileAttr(p)) == 0) {
            *st = 2;
        } else {
            *st = 1;
        }
        break;
    case 1:
        FIELD_TILE_MOVE_SpinTick(p);
        if (FLDMMDL_CheckEndAcmd(p[3])) {
            FIELD_TILE_MOVE_SpinSelectEntry(p);
            if (FIELD_TILE_MOVE_SpinIsBlocked((u32)p)) {
                func_020061F8(GFL_USE_GetSeSlot(0x694));
                *st = 2;
            } else {
                FIELD_TILE_MOVE_SpinStartStep(p);
            }
        }
        break;
    case 2:
        FIELD_TILE_MOVE_SpinFinish(p);
        return 1;
    }
    return 0;
}
