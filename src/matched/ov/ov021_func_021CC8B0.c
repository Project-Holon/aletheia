/*
 * function: PARTY_SELECT_LIST_GetResult
 * address:  0x021CC8B0
 * packet:   pkt_ov021_021CC8B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (no lr save), filed as the blocker of PARTY_SELECT_LIST_Delete.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Obj {
    u8 pad0[0x10];
    u32 f10;
    u32 f14;
    u8 pad18[0xbc - 0x18];
    u32 fBC;
} Obj;

u32 PARTY_SELECT_LIST_GetResult(Obj *p, u32 *out)
{
    u32 m;

    *out = 0;
    m = p->fBC;
    if (m == 0 && p->f10 == 1)
        *out = 1;
    else if (m == 1 && p->f14 == 1)
        *out = 1;
    return p->fBC;
}
