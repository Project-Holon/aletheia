/*
 * function: FIELD_MSGBG_GetMenuItemsMaxWidth
 * address:  0x02190A74
 * packet:   pkt_ov021_02190A74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201D304  0x0201D304  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);

u32 FIELD_MSGBG_GetMenuItemsMaxWidth(u32 *obj, u32 *tab, u32 *out, u32 key)
{
    u32 k;
    u32 bestIdx;
    u32 best;
    u32 i;

    best = 0;
    bestIdx = 0;
    i = 0;
    if (tab[0] != -1) {
        k = (u16)key;
        do {
            u32 r;
            if (tab[0] == 0) {
                break;
            }
            r = func_0201D304((struct StrObj *)tab[0], obj[2], k);
            if (r > best) {
                best = r;
                bestIdx = i;
            }
            tab += 2;
            i++;
        } while (tab[0] != -1);
    }
    *out = bestIdx;
    return best;
}
