/*
 * function: BTL_SERVER_FLOW_GetActionWordByPokeId
 * address:  0x021C804C
 * packet:   pkt_ov093_021C804C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Levers: the record array read as p->e[i] of the twins' S (BTL_SERVER_FLOW_FindActionByPokeId,
 * BTL_SERVER_FLOW_FindPendingActionByMove), which keeps i*16 live and recomputes p+i*16 for the second
 * load; the second word as a union of u32 and a 4-bit bitfield read in place
 * (a union local takes a stack slot); key as a u8 parameter, which puts its
 * spill ahead of the count load (int/u32 key leave it after).
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);

typedef struct { u32 lo : 4; u32 hi : 28; } W;
typedef union { u32 u; W w; } U;
typedef struct { u8 *a; U b; u32 c; u32 d; } E;
typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[4]; } S;

int BTL_SERVER_FLOW_GetActionWordByPokeId(S *p, u8 key, u32 *out)
{
    u32 i;
    for (i = 0; i < p->n; i++) {
        if (key == BTL_POKEPARAM_GetPokeId(p->e[i].a)) {
            if (p->e[i].b.w.lo != 6) {
                *out = p->e[i].b.u;
                return 1;
            }
        }
    }
    return 0;
}
