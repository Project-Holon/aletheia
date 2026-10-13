/*
 * function: FIELD_LIGHT_FADE_Update
 * address:  0x021A0C74
 * packet:   pkt_ov021_021A0C74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_LIGHT_BeginColorBlend  0x021A0A50  thumb  ov021
 *   FIELD_LIGHT_IsBlending  0x021A0B34  thumb  ov021
 *   FIELD_LIGHT_BeginBlend  0x021A0980  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void FIELD_LIGHT_BeginColorBlend(u8 *a, u8 *b, u32 c, u32 d);
extern int FIELD_LIGHT_IsBlending(u32 a);
extern void FIELD_LIGHT_BeginBlend(u8 *a, u8 *b, u8 *c, u32 d);

s32 FIELD_LIGHT_FADE_Update(u16 *a, void *b, void *c, void *d)
{
    switch (a[0]) {
    case 1:
        FIELD_LIGHT_BeginColorBlend(b, c, a[3], a[1]);
        a[0] = 2;
        break;
    case 2:
        if (FIELD_LIGHT_IsBlending((u32)b) == 0) {
            if (a[2] != 0xFFFF) {
                FIELD_LIGHT_BeginBlend(b, c, d, a[2]);
            }
            a[0] = 3;
        }
        break;
    case 3:
        if (FIELD_LIGHT_IsBlending((u32)b) == 0) {
            a[0] = 0;
        }
        break;
    case 0:
        return 1;
    }
    return 0;
}
