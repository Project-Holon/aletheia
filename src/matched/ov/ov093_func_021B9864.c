/*
 * function: BTL_SIDE_FindPokeIndexInClient
 * address:  0x021B9864
 * packet:   pkt_ov093_021B9864
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: inferred extent runs two bytes long; the follower is an unlabelled
 * padding pair that disasm.py did not label.
 *
 * symbols:
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 */

typedef unsigned char u8;

struct Q1;
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
typedef unsigned int u32;
struct S2;
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);

int BTL_SIDE_FindPokeIndexInClient(int a, int b, int c)
{
    char *p = (char *)(a + 4) + b * 0x1c;
    unsigned int n = BTL_SLOT_GetCount((struct Q1 *)p);
    unsigned int i;
    for (i = 0; i < n; i++) {
        if (c == BTL_POKEPARAM_GetPokeId((u8 *)BTL_SLOT_GetPokeParam((struct S2 *)p, (unsigned char)i)))
            return i;
    }
    return -1;
}
