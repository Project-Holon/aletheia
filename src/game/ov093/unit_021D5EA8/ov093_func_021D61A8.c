/*
 * function: func_021D61A8
 * address:  0x021D61A8
 * packet:   pkt_ov093_021D61A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8AFC  0x021E8AFC  thumb  ov093
 *   func_021E8918  0x021E8918  thumb  ov093
 *   func_021D6238  0x021D6238  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
union Slot {
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
    struct { u32 kind : 3; u32 pad : 6; u32 v : 16; u32 rest : 7; } w;
};
struct UtilSlots { u8 pad[0x1C]; union Slot e[16]; u8 pad5C[0x50]; u8 b[16]; u8 padBC[0x80]; u16 f13C; };
extern u8 func_021E8AFC(union Slot s);
extern union Slot func_021E8918(void);
extern void func_021D6238(struct UtilSlots *p, int k);
int func_021D61A8(struct UtilSlots *p)
{
    union Slot *s = &p->e[6];
    u8 max;
    if (s->s.kind != 0) {
        max = func_021E8AFC(*s);
        if (max != 0) {
            p->b[6]++;
            if (p->b[6] >= max) {
                *s = func_021E8918();
                func_021D6238(p, 6);
                return 1;
            }
        }
    }
    return 0;
}
