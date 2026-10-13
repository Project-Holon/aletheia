/*
 * function: FIELD_RAIL_IsLocationInLine
 * address:  0x021B95C0
 * packet:   pkt_021B95C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Guard chain separated by the abs() statement shares one return-0 exit
 * only through explicit goto labels; the early result==0 path is written
 * as a final `ok:` label so the compiler outlines that return block.
 *
 * symbols:
 *   FIELD_RAIL_CLOSED_ContainsLine  0x021B94D8  thumb
 *   FIELD_RAIL_GetNeighbourLimits  0x021B86A4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int FIELD_RAIL_CLOSED_ContainsLine(u16 *r, u8 *tbl, u8 *sr);
void FIELD_RAIL_GetNeighbourLimits(u8 *t, const u32 *q, int *out1, int *out2, u16 *a5, u32 a6);

int FIELD_RAIL_IsLocationInLine(u8 *p, u8 *q, int a3, int a4, u8 *sr, u32 a6)
{
    u32 c, d;

    if (FIELD_RAIL_CLOSED_ContainsLine((u16 *)p, q, sr) == 0)
        goto ok;
    FIELD_RAIL_GetNeighbourLimits(sr, (u32 *)q, (int *)(&c), (int *)(&d), (u16 *)((u32)p), a6);
    if (a3 > (int)c)
        goto fail;
    if (a4 < 0)
        a4 = -a4;
    if (a4 > (int)d)
        goto fail;
    return 1;
fail:
    return 0;
ok:
    return 1;
}
