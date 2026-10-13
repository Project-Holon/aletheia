/*
 * function: BTL_SERVER_FLOW_FindActionByPokeId
 * address:  0x021BCA08
 * packet:   pkt_ov093_021BCA08
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u8 *a; u32 b, c, d; } E;
typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[4]; } S;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);

E *BTL_SERVER_FLOW_FindActionByPokeId(S *p, u8 x)
{
    u32 i;
    u32 y = x;
    for (i = 0; i < p->n; i++) {
        if (y == BTL_POKEPARAM_GetPokeId(p->e[i].a))
            return &p->e[i];
    }
    return 0;
}
