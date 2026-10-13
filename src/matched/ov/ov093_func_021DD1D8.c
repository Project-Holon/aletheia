/*
 * function: HAND_ITEM_CheckHasSick
 * address:  0x021DD1D8
 * packet:   pkt_ov093_021DD1D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_CALC_FindMajorSick  0x021D7E10  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct Unk021D62A8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_CALC_FindMajorSick(struct Unk021D62A8 *p);

int HAND_ITEM_CheckHasSick(u8 *a, int b, int c)
{
    u8 *m = BTL_SERVER_FLOW_GetPokeParam((int *)a, b);
    switch (c) {
    case 0x25:
        if (BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)m) == 0 && BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)m, 6) == 0)
            break;
        return 1;
    case 0x24:
        if (BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)m) != 0)
            return 1;
        return 0;
    case 0x26:
        if (BTL_CALC_FindMajorSick((struct Unk021D62A8 *)m) != 0)
            return 1;
        return 0;
    default:
        return BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)m, c);
    }
    return 0;
}
