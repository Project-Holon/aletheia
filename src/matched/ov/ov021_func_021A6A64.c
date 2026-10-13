/*
 * function: FIELD_PLAYER_NOGRID_ForcedSlideWarnDir3
 * address:  0x021A6A64
 * packet:   pkt_ov021_021A6A64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetDirMove  0x0216D608  thumb
 *   func_020061E4  0x020061E4  thumb
 *   FIELD_PLAYER_NOGRID_ForcedSlide  0x021A6908  thumb
 */

typedef unsigned short u16;

typedef struct {
    int pad[7];
    int f1c;
} S;

extern u16 FLDMMDL_GetDirMove(int a);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern int FIELD_PLAYER_NOGRID_ForcedSlide(S *a, int b, int c);

int FIELD_PLAYER_NOGRID_ForcedSlideWarnDir3(S *a, int b, int c)
{
    if (FLDMMDL_GetDirMove(a->f1c) == 3) {
        func_020061E4(0x55e);
    }
    return FIELD_PLAYER_NOGRID_ForcedSlide(a, b, c);
}
