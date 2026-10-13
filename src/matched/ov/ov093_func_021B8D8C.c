/*
 * function: BTL_MAIN_GetTrainerSlotOfPoke
 * address:  0x021B8D8C
 * packet:   pkt_ov093_021B8D8C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_PokeIdToClientId  0x021B8D08  thumb  ov093
 *   BTL_SIDE_FindPokeIndexInClient  0x021B9864  thumb  ov093
 *   BTL_MAIN_GetClientTrainerIndex  0x021B8BEC  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_MAIN_PokeIdToClientId(u32 x);
extern int BTL_SIDE_FindPokeIndexInClient(int a, int b, int c);
extern u8 BTL_MAIN_GetClientTrainerIndex(u8 *p, u32 k, u8 n);

int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b)
{
    u8 i = BTL_MAIN_PokeIdToClientId(b);
    int r = BTL_SIDE_FindPokeIndexInClient((int)a, i, b);

    if (r >= 0) {
        r = BTL_MAIN_GetClientTrainerIndex(p, i, r);
        if (r != 6) return r;
    }
    return 6;
}
