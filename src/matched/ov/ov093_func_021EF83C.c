/*
 * function: BTL_FIELD_ResetSlot
 * address:  0x021EF83C
 * packet:   pkt_ov093_021EF83C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_GetZeroMasked  0x021E8918  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 v; } Slot;

typedef struct {
    u32 pad00[2];       /* 0x000 */
    u32 t[8];           /* 0x008 */
    Slot c[8];          /* 0x028 */
    u32 z48[8];         /* 0x048 */
    u32 w[8][6];        /* 0x068 */
    u32 z128[8];        /* 0x128 */
    u32 used[8];        /* 0x148 */
} S;

extern Slot BTLV_CORE_GetZeroMasked(void);

void BTL_FIELD_ResetSlot(S *a, u32 i)
{
    u32 j;

    a->t[i] = 0;
    a->c[i] = BTLV_CORE_GetZeroMasked();
    a->z48[i] = 0;
    a->z128[i] = 0;
    a->used[i] = 0;
    for (j = 0; j < 6; j++)
        a->w[i][j] = 0x1f;
}
