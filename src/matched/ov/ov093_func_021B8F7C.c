/*
 * function: BTL_MAIN_SyncPartnerSideParty
 * address:  0x021B8F7C
 * packet:   pkt_ov093_021B8F7C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_IsMultiMode  0x021B86C8  thumb  ov093
 *   BTL_MAIN_IsClientUsed  0x021B8B9C  thumb  ov093
 *   BTL_SIDE_WriteBackParty  0x021B969C  thumb  ov093
 *   BTL_SIDE_GetParty  0x021B985C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_MAIN_IsMultiMode(unsigned char **p);
extern int BTL_MAIN_IsClientUsed(u8 *p, u32 k);
extern void BTL_SIDE_WriteBackParty(char *a, char *b, int k, int flag);
extern int BTL_SIDE_GetParty(char *p, int i);

int BTL_MAIN_SyncPartnerSideParty(u8 *p, u32 k)
{
    if (BTL_MAIN_IsMultiMode((unsigned char **)p)) {
        k = (u8)((k + 2) & 3);
        if (BTL_MAIN_IsClientUsed(p, k)) {
            BTL_SIDE_WriteBackParty((char *)(p + 0xc8), (char *)p, k, 0);
            return BTL_SIDE_GetParty((char *)(p + 0xc8), k);
        }
    }
    return 0;
}
