/*
 * function: BTL_POKEPARAM_AddHp
 * address:  0x021D5FA4
 * packet:   pkt_ov093_021D5FA4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D5FA4 { u8 pad[0xE]; u16 fE; u16 f10; };
void BTL_POKEPARAM_AddHp(struct Unk021D5FA4 *p, u16 n)
{
    p->f10 += n;
    if (p->f10 > p->fE) p->f10 = p->fE;
}
