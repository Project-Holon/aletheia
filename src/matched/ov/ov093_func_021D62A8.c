/*
 * function: BTL_POKEPARAM_GetMajorStatusIndex
 * address:  0x021D62A8
 * packet:   pkt_ov093_021D62A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Slot { u32 a : 3; u32 rest : 29; };
struct Unk021D62A8 { u8 pad[0x1C]; struct Slot e[6]; };
int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p)
{
    u32 i;
    for (i = 1; i < 6; i++) {
        if (p->e[i].a) return i;
    }
    return 0;
}
