/*
 * function: BTL_SLOT_Rotate
 * address:  0x021B9C50
 * packet:   pkt_ov093_021B9C50
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SLOT_GetRotateSrcIndex  0x021B9AB0  thumb  ov093
 *   BTL_SLOT_GetRotateDstIndex  0x021B9AC8  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_SLOT_GetRotateSrcIndex(int k);
extern int BTL_SLOT_GetRotateDstIndex(int k);

void BTL_SLOT_Rotate(u8 **p, int k, u8 **o1, u8 **o2)
{
    u8 *t;
    int a;
    int b;

    if (k != 0) {
        if (k != 1) {
            t = p[0];
            a = BTL_SLOT_GetRotateSrcIndex(k);
            b = BTL_SLOT_GetRotateDstIndex(k);
            p[0] = p[a];
            p[a] = p[b];
            p[b] = t;
            if (o1)
                *o1 = t;
            if (o2)
                *o2 = p[0];
        }
    }
}
