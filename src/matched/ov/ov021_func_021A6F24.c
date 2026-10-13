/*
 * function: FIELDMAP_CTRL_HYBRID_Main
 * address:  0x021A6F24
 * packet:   pkt_ov021_021A6F24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetCtrlWork  0x02188CA4  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb
 *   gFieldMapCtrlHybridModeTable  0x021DDF38  data  a4
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern u32 FIELDMAP_GetCtrlWork(u8 *p);
extern void (*const gFieldMapCtrlHybridModeTable[])(u32 a, u32 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *a, struct VecFx32 *v);

void FIELDMAP_CTRL_HYBRID_Main(u32 a, int *v)
{
    u32 *p = (u32 *)FIELDMAP_GetCtrlWork((u8 *)a);
    gFieldMapCtrlHybridModeTable[p[0]](a, p);
    FIELD_PLAYER_GetPos((unsigned char *)p[1], (struct VecFx32 *)v);
}
