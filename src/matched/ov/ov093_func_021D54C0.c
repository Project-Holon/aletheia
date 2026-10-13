/*
 * function: BTL_POKEPARAM_GetMoveId
 * address:  0x021D54C0
 * packet:   pkt_ov093_021D54C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * lever: the halfword is the first member of a 14-byte record in the array
 * at +0x10a; the image's `adds r2,#0xfc` is the constant 0x10a folded with
 * the stride, not a +0xa field.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 a; u8 b; u8 c; u8 pad[10]; } Ent;

u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i)
{
    return ((Ent *)(p + 0x10a))[i].a;
}
