/*
 * function: func_02156DFC
 * address:  0x02156DFC
 * packet:   pkt_ov009_02156DFC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The pooled 0x11 is the overlay id of ov017 (absolute linker symbol, see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md): load
 * ov017, run func_021B6100 there, unload it.
 *
 * symbols:
 *   abs_id_11  0x00000011  data
 *   func_02157108  0x02157108  thumb  ov009
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021B6100  0x021B6100  thumb  ov017
 */

typedef unsigned short u16;

extern unsigned char abs_id_11[];
extern int func_02157108(u16 a);
extern void func_02034AC4(const void *id);
extern void func_02034A5C(const void *id);
extern void func_021B6100(void);

void func_02156DFC(int a)
{
    if (func_02157108(a) == 3) {
        func_02034AC4(abs_id_11);
        func_021B6100();
        func_02034A5C(abs_id_11);
    }
}
