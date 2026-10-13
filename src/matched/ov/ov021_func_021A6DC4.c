/*
 * function: FIELDMAP_CTRL_HYBRID_ReplacePlayer
 * address:  0x021A6DC4
 * packet:   pkt_ov021_021A6DC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb
 *   FIELDMAP_CTRL_HYBRID_FindRailLocation  0x021A71E4  thumb
 *   FIELDMAP_CTRL_HYBRID_SwitchToNogrid  0x021A70D0  thumb
 *   FIELDMAP_CTRL_HYBRID_FindGridPos  0x021A7198  thumb
 *   FIELDMAP_CTRL_HYBRID_SwitchToGrid  0x021A712C  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u32 FLDMMDL_GetDirDisp(void *a);
struct V;
extern int FIELDMAP_CTRL_HYBRID_FindRailLocation(u32 a, u32 *b, u16 *c, u32 d);
extern void FIELDMAP_CTRL_HYBRID_SwitchToNogrid(u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern int FIELDMAP_CTRL_HYBRID_FindGridPos(u32 a, u32 *b, struct V *c, u32 d);
extern void FIELDMAP_CTRL_HYBRID_SwitchToGrid(u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f, u32 g);

void FIELDMAP_CTRL_HYBRID_ReplacePlayer(u32 *b, void *a)
{
    u16 out2[6];
    u16 out1[4];
    u32 k = FLDMMDL_GetDirDisp(FIELD_PLAYER_GetMmdl(((unsigned char **)b)[1]));
    if (b[0] == 0) {
        if (FIELDMAP_CTRL_HYBRID_FindRailLocation((u32)a, b, out1, k) != 0) {
            FIELDMAP_CTRL_HYBRID_SwitchToNogrid((u32)a, b, k, 0, (u32)out1, 0, 0);
        }
    } else {
        if (FIELDMAP_CTRL_HYBRID_FindGridPos((u32)a, b, (struct V *)out2, k) != 0) {
            FIELDMAP_CTRL_HYBRID_SwitchToGrid((u32)a, b, k, 0, (u32)out2, 0, 0);
        }
    }
    b[2] = 0;
}
