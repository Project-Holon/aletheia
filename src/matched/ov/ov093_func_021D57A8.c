/*
 * function: BTL_POKEPARAM_GetTypes
 * address:  0x021D57A8
 * packet:   pkt_ov093_021D57A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);

void BTL_POKEPARAM_GetTypes(u8 *p, u8 *a, u8 *b)
{
    int r = BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)p, 0x18);
    u8 v;
    v = p[0xF8];
    if (v == 2 && r) *a = 0x11;
    else *a = v;
    v = p[0xF9];
    if (v == 2 && r) *b = 0x11;
    else *b = v;
    if (*a == 0x11) {
        if (*b == 0x11) *b = 0;
        *a = *b;
    } else if (*b == 0x11) {
        *b = *a;
    }
}
