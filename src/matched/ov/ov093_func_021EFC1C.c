/*
 * function: func_021EFC1C
 * address:  0x021EFC1C
 * packet:   pkt_ov093_021EFC1C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The u8 result of BTL_POKEPARAM_GetPokeId and the u16 id parameter (the real types
 * of the matched callees) set the prologue order: the y home store comes
 * before the x home store.
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_SIDE_GetPokeById  0x021B9940  thumb  ov093
 *   BTL_POKEPARAM_HasMove  0x021D5750  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_MAIN_IsPokeSamePair(u8 a, u8 b);
extern u8 *BTL_SIDE_GetPokeById(char *p, u8 i);
extern int BTL_POKEPARAM_HasMove(u8 *p, u16 id);

typedef struct {
    u8 pad00[0xB0];
    u32 id[0x4D - 0x2C];    /* 0x0B0 */
    u32 count;              /* 0x134 */
} S;

int func_021EFC1C(S *a, char *x, void *m, u16 y)
{
    u8 mon;
    u8 c;
    u32 i;
    u32 n;

    mon = BTL_POKEPARAM_GetPokeId(m);
    n = a->count;
    for (i = 0; i < n; i++) {
        c = a->id[i];
        if (BTL_MAIN_IsPokeSamePair(mon, c) == 0) {
            if (BTL_POKEPARAM_HasMove(BTL_SIDE_GetPokeById(x, c), y) != 0)
                return 1;
        }
    }
    return 0;
}
