/*
 * function: FIELD_BUILDMODEL_GetEntryWorldPos
 * address:  0x0218C6D0
 * packet:   pkt_ov021_0218C6D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3D_MAP_GetPos  0x02169510  thumb  ov010
 *   VEC_Add  0x0207C9D0  arm
 */

typedef unsigned char  u8;
struct V3;
void FIELD_G3D_MAP_GetPos(u8 *src, struct V3 *dst);
void VEC_Add(unsigned char *a, int *buf, int b);

void FIELD_BUILDMODEL_GetEntryWorldPos(int *p, int b)
{
    int buf[3];
    FIELD_G3D_MAP_GetPos((u8 *)p[0], (struct V3 *)buf);
    VEC_Add((unsigned char *)p[3] + 4, buf, b);
}
