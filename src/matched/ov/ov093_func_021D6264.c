/*
 * function: func_021D6264
 * address:  0x021D6264
 * packet:   pkt_ov093_021D6264
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E8928  0x021E8928  thumb  ov093
 *   func_021E8A98  0x021E8A98  thumb  ov093
 *   func_021E8918  0x021E8918  thumb  ov093
 *   func_021D621C  0x021D621C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
struct Slot { u32 a : 3; u32 rest : 29; };
struct UtilSlots { u8 pad[0x1c]; struct Slot s[36]; };
extern int func_021E8928(struct Slot s);
extern int func_021E8A98(struct Slot s);
extern struct Slot func_021E8918(void);
struct Unk021D621C;
extern void func_021D621C(struct Unk021D621C *p, int k);

void func_021D6264(struct UtilSlots *p, int v)
{
    u32 i;
    if (v != 0x1f) {
        for (i = 0; i < 0x24; i++) {
            if (func_021E8928(p->s[i]) == 0 && v == func_021E8A98(p->s[i])) {
                p->s[i] = func_021E8918();
                func_021D621C((struct Unk021D621C *)p, i);
            }
        }
    }
}
