/*
 * function: FLDMMDL_RAIL_MOVE_GetDirByAngle
 * address:  0x0219D738
 * packet:   pkt_ov021_0219D738
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_RAIL_GetDrawOffsetByDir  0x0219E784  thumb  ov021
 *   VEC_Fx16Normalize  0x0207CDB8  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   d_021D80E4     0x021D80E4  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void FLDMMDL_RAIL_GetDrawOffsetByDir(u32, u32, s16 *);
extern void VEC_Fx16Normalize(s16 *, s16 *);
extern int func_0207CFB8(int, int);
extern u8 d_021D80E4[];

u32 FLDMMDL_RAIL_MOVE_GetDirByAngle(u32 a, int b)
{
    s16 v[4];
    int r;
    FLDMMDL_RAIL_GetDrawOffsetByDir(a, FLDMMDL_GetDirDisp((void *)a), v);
    v[1] = 0;
    VEC_Fx16Normalize(v, v);
    r = func_0207CFB8(v[0], v[2]) - b;
    if (r < 0) {
        r += 0x10000;
    }
    return d_021D80E4[r >> 12];
}
