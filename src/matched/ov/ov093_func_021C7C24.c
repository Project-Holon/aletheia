/*
 * function: BTL_SERVER_FLOW_RecordEffectivenessHit
 * address:  0x021C7C24
 * packet:   pkt_ov093_021C7C24
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern int BTL_MAIN_IsPokeSamePair(unsigned int a, unsigned int b);

void BTL_SERVER_FLOW_RecordEffectivenessHit(u16 *p, int unused, u8 *b, u8 *c, int e)
{
    u8 x = BTL_POKEPARAM_GetPokeId(b);
    u8 y = BTL_POKEPARAM_GetPokeId(c);
    int mx = BTL_MAIN_PokeIdToClientIdThunk(x);
    int my = BTL_MAIN_PokeIdToClientIdThunk(y);
    u8 same = (BTL_MAIN_IsPokeSamePair(x, y) == 0);
    u16 *q = 0;
    if (mx == 0) {
        if (same) {
            if (e == 0) {
                q = p;
            } else if (e > 3) {
                q = p + 1;
            } else if (e < 3) {
                q = p + 2;
            }
        }
    } else if (my == 0) {
        if (same) {
            if (e == 0) {
                q = p + 3;
            } else if (e > 3) {
                q = p + 4;
            } else if (e < 3) {
                q = p + 5;
            }
        }
    }
    if (q != 0) {
        if (*q < 9999) {
            *q += 1;
        }
    }
}
