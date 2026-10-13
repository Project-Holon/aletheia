/*
 * function: BTL_SERVER_FLOW_RecordDamageHit
 * address:  0x021C1828
 * packet:   pkt_ov093_021C1828
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The Rec build loads q[6] and q[0] first (ldrb, ldrh) only when both are
 * read into their own locals (c6 before a0), assigned after the second
 * BTL_POKEPARAM_GetPokeId call; reading them straight into the fields interleaves
 * loads and stores.
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_AddHitRecord  0x021D6848  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 */
#include "../include/Obj02778.h"
#include "../include/Obj21078.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct Rec { u16 a; u16 b; u8 c; u8 d; u8 e; };

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_POKEPARAM_AddHitRecord(u8 *c, struct Rec *r);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);

void BTL_SERVER_FLOW_RecordDamageHit(u8 *p, u8 b, u8 *x, u8 *c, u8 *q, u16 w)
{
    struct Rec r;
    u8 c6;
    u16 a0;
    u8 n = BTL_POKEPARAM_GetPokeId(x);
    u8 m = BTL_POKEPARAM_GetPokeId(c);
    c6 = q[6];
    a0 = ((struct Obj02778 *)q)->f0;
    r.a = a0;
    r.b = w;
    r.c = c6;
    r.d = n;
    r.e = b;
    BTL_POKEPARAM_AddHitRecord(c, &r);
    BTL_SERVER_CMD_Push(((struct Obj21078 *)p)->fC, 0x2d, m, n, b, q[6], ((struct Obj02778 *)q)->f0, w);
}
