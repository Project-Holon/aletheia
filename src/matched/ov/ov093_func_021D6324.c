/*
 * function: func_021D6324
 * address:  0x021D6324
 * packet:   pkt_ov093_021D6324
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021E8A78  0x021E8A78  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
struct Slot { u32 a : 3; u32 rest : 29; };
struct UtilSlots { u8 pad[0x1c]; struct Slot s[16]; u8 pad5C[0x50]; u8 b[16]; };
extern int func_021D62C4(struct UtilSlots *p, int i);
extern int func_021E8A78(struct Slot s);
extern int func_021D7B74(u8 *p, u32 k);

int func_021D6324(struct UtilSlots *p, int k)
{
    if (func_021D62C4(p, k) != 0) {
        switch (k) {
        case 5:
            if (func_021E8A78(p->s[k]) != 0)
                return func_021D7B74((u8 *)p, 0x10) * p->b[k];
            return func_021D7B74((u8 *)p, 8);
        case 4:
            return func_021D7B74((u8 *)p, 8);
        case 9:
            if (func_021D62C4(p, 2) != 0)
                return func_021D7B74((u8 *)p, 4);
            break;
        case 10:
            return func_021D7B74((u8 *)p, 4);
        default:
            return 0;
        }
    }
    return 0;
}
