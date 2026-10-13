/*
 * function: PDW_POSTMAN_GetMysteryGiftType
 * address:  0x021B7864
 * packet:   pkt_ov021_021B7864
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PDW_POSTMAN_FindMysteryCard  0x021B7834  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *PDW_POSTMAN_FindMysteryCard(void *a, int *out, void *buf);

u8 PDW_POSTMAN_GetMysteryGiftType(void *a)
{
    int idx;
    u8 buf[0xCC];
    u8 *p;

    p = PDW_POSTMAN_FindMysteryCard(a, &idx, buf);
    if (p == 0) {
        return 0;
    }
    return p[0xB3];
}
