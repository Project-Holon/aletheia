/*
 * function: func_0216A420
 * address:  0x0216A420
 * packet:   pkt_0216A420
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  listing 32 compiled 30 wild=4
 *
 * Overlay index, then the record's handle and one arm9 probe go to the
 * overlay's own pair call.
 *
 * symbols:
 *   func_0215A5DC   0x0215A5DC  thumb  ov010
 *   func_020120F4   0x020120F4  thumb
 *   func_02012F50   0x02012F50  thumb
 *   func_021D0A48   0x021D0A48  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(void *);
extern void *func_02012F50(void *base);
extern void func_021D0A48(void *, void *);

int func_0216A420(void *a0, void *a1)
{
    void *p = func_0215A5DC(a1);

    func_021D0A48(p, func_02012F50(func_020120F4(p)));

    return 0;
}

