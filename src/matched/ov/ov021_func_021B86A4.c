/*
 * function: FIELD_RAIL_GetNeighbourLimits
 * address:  0x021B86A4
 * packet:   pkt_ov021_021B86A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Scores three neighbouring cells (row from FIELD_RAIL_SETTING_GetPoint, then one
 * FIELD_RAIL_POINT_FindLine lookup per direction) against the start cell q.
 * q is read through a const pointer: with a plain `u32 *q` the outgoing
 * flag store `str r6, [sp]` lands before `adds r2, r5` in the first two
 * FIELD_RAIL_POINT_FindLine calls (8 bytes).  Declaration order of row/best1 sets their
 * stack slots (best1 at sp+0xc, row at sp+0x10).
 *
 * symbols:
 *   FIELD_RAIL_SETTING_GetPoint  0x021B87D8  thumb
 *   FIELD_RAIL_POINT_FindLine  0x021B8514  thumb
 *   FIELD_RAIL_KEY_Opposite  0x021B93D4  thumb
 *   FIELD_RAIL_KEY_TurnLeft  0x021B9434  thumb
 *   FIELD_RAIL_KEY_TurnRight  0x021B9404  thumb
 *   FIELD_RAIL_LINE_GetLength  0x021B9278  thumb
 *   FIELD_RAIL_LINE_GetWidthAt  0x021B9280  thumb
 *   FIELD_RAIL_LINE_StartsAtPoint  0x021B8674  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 *FIELD_RAIL_SETTING_GetPoint(u8 *p, u32 idx);
u8 *FIELD_RAIL_POINT_FindLine(u8 *p, u32 v, u8 *q, u16 *r, int flag);
int FIELD_RAIL_KEY_Opposite(int dir);
int FIELD_RAIL_KEY_TurnLeft(int dir);
int FIELD_RAIL_KEY_TurnRight(int dir);
int FIELD_RAIL_LINE_GetLength(const u32 *p, u32 b, u8 *t);
int FIELD_RAIL_LINE_GetWidthAt(u8 *a, u32 arg2, u32 arg3, u8 *tbl);
int FIELD_RAIL_LINE_StartsAtPoint(u8 *p, u32 *q, u32 v);

void FIELD_RAIL_GetNeighbourLimits(u8 *t, const u32 *q, int *out1, int *out2, u16 *a5, u32 a6)
{
    u32 *row;
    int best1;
    u32 *res1;
    u32 *res2;
    u32 *res3;
    int best2;
    int m;
    int r;

    best1 = 0;
    row = (u32 *)FIELD_RAIL_SETTING_GetPoint(t, q[0]);
    res1 = (u32 *)FIELD_RAIL_POINT_FindLine((u8 *)row, FIELD_RAIL_KEY_Opposite(q[2]), t, a5, 1);
    res2 = (u32 *)FIELD_RAIL_POINT_FindLine((u8 *)row, FIELD_RAIL_KEY_TurnLeft(q[2]), t, a5, 1);
    res3 = (u32 *)FIELD_RAIL_POINT_FindLine((u8 *)row, FIELD_RAIL_KEY_TurnRight(q[2]), t, a5, 1);
    best2 = FIELD_RAIL_LINE_GetWidthAt((u8 *)q, 0, FIELD_RAIL_LINE_GetLength(q, a6, t), t);
    if (res1) {
        m = FIELD_RAIL_LINE_GetLength(res1, a6, t);
        r = FIELD_RAIL_LINE_GetWidthAt((u8 *)res1, m, m, t);
        if (r > best2)
            best2 = r;
    }
    if (res2) {
        m = FIELD_RAIL_LINE_GetLength(res2, a6, t);
        if (FIELD_RAIL_LINE_StartsAtPoint(t, res2, (u32)row))
            r = FIELD_RAIL_LINE_GetWidthAt((u8 *)res2, 0, m, t);
        else
            r = FIELD_RAIL_LINE_GetWidthAt((u8 *)res2, m, m, t);
        if (r > best1)
            best1 = r;
    }
    if (res3) {
        m = FIELD_RAIL_LINE_GetLength(res3, a6, t);
        if (FIELD_RAIL_LINE_StartsAtPoint(t, res3, (u32)row))
            r = FIELD_RAIL_LINE_GetWidthAt((u8 *)res3, 0, m, t);
        else
            r = FIELD_RAIL_LINE_GetWidthAt((u8 *)res3, m, m, t);
        if (r > best1)
            best1 = r;
    }
    *out1 = best1;
    *out2 = best2;
}
