/*
 * function: FLDMMDL_ACMD_GetDrawPos
 * address:  0x02197CCC
 * packet:   pkt_ov021_02197CCC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Sums five 12-byte records fetched from the actor at p into out.
 *
 * symbols:
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetDrawOffset  0x0216D8B0  thumb  ov010
 *   FLDMMDL_GetDrawOffsetOutside  0x0216D8D0  thumb  ov010
 *   FLDMMDL_GetAttrOffset  0x0216D8F0  thumb  ov010
 *   FLDMMDL_GetModelOffset  0x0216D92C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern void FLDMMDL_GetDrawOffset(u8 *p, u8 *q);
extern void FLDMMDL_GetDrawOffsetOutside(u8 *p, u8 *q);
extern void FLDMMDL_GetAttrOffset(u8 *p, u8 *q);
extern void FLDMMDL_GetModelOffset(u8 *, s32 *);

void FLDMMDL_ACMD_GetDrawPos(u8 *p, s32 *out)
{
    s32 a[3];
    s32 b[3];
    s32 c[3];
    s32 d[3];
    s32 e[3];

    FLDMMDL_GetPos((const struct Actor *)p, (struct VecFx32 *)a);
    FLDMMDL_GetDrawOffset(p, (u8 *)b);
    FLDMMDL_GetDrawOffsetOutside(p, (u8 *)c);
    FLDMMDL_GetAttrOffset(p, (u8 *)d);
    FLDMMDL_GetModelOffset(p, e);
    out[0] = a[0] + b[0] + c[0] + d[0] + e[0];
    out[1] = a[1] + b[1] + c[1] + d[1] + e[1];
    out[2] = a[2] + b[2] + c[2] + d[2] + e[2];
}
