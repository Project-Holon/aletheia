/*
 * function: func_021D61F0
 * address:  0x021D61F0
 * packet:   pkt_ov093_021D61F0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8918  0x021E8918  thumb  ov093
 *   func_021D621C  0x021D621C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
struct Slot { u32 a : 3; u32 rest : 29; };
extern struct Slot func_021E8918(void);
struct UtilSlots { u8 pad[0x1c]; struct Slot s[16]; u8 pad5C[0x50]; u8 b[16]; };
extern void func_021D621C(struct UtilSlots *p, int k);

void func_021D61F0(struct UtilSlots *p)
{
    u32 i;
    for (i = 1; i < 6; i++) {
        p->s[i] = func_021E8918();
        p->b[i] = 0;
        func_021D621C(p, i);
    }
}
