/*
 * function: PDW_POSTMAN_GetMysteryCard
 * address:  0x021B77E4
 * packet:   pkt_ov021_021B77E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MYSTERY_DATA_IsCardExist  0x0200A0E4  thumb
 *   MYSTERY_DATA_IsCardReceived  0x0200A104  thumb
 *   MYSTERY_DATA_GetCard  0x0200A000  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

struct Ent { u8 pad00[0xB3]; u8 fB3; };

typedef unsigned int   u32;
extern u32 MYSTERY_DATA_IsCardExist(u8 *p, u32 a);
extern int MYSTERY_DATA_IsCardReceived(char *p, unsigned int idx);
extern int MYSTERY_DATA_GetCard(char *p, int idx, void *buf);

struct Ent *PDW_POSTMAN_GetMysteryCard(void *a, void *b, struct Ent *c)
{
    u8 v;

    if (MYSTERY_DATA_IsCardExist(a, (u32)b) == 0)
        return 0;
    if (MYSTERY_DATA_IsCardReceived(a, (unsigned int)b) == 1)
        return 0;
    if (MYSTERY_DATA_GetCard(a, (int)b, c) == 0)
        return 0;
    v = c->fB3;
    if (v == 0)
        return 0;
    if (v > 3)
        c = 0;
    return c;
}
