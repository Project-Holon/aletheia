/*
 * function: func_021F1218
 * address:  0x021F1218
 * packet:   pkt_ov032_021F1218
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F1218 0x021F1218 thumb
 *   func_021F0DE0 0x021F0DE0 thumb
 *   func_0202590C 0x0202590C thumb
 */

extern void func_021F0DE0(void *, short, short);
extern void func_0202590C(void *, short, short);

void func_021F1218(char *p, short x, short y)
{
    *(short *)(p + 8) = x;
    *(short *)(p + 0xa) = y;
    func_021F0DE0(*(void **)(p + 0xc), x, y);
    func_021F0DE0(*(void **)(p + 0x10), x + 0x20, y + 0x18);
    func_021F0DE0(*(void **)(p + 0x14), x + 0x3c, y + 0x18);
    func_0202590C(*(void **)(p + 0x18), x + 0x48, y + 0x10);
}
