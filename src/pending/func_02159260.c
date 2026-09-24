/*
 * function: func_02159260
 * address:  0x02159260
 * packet:   pkt_02159260
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  the ABS32 pool word +0x20 holds 0x02159255 (the thumb address of the
 *           handler at 0x02159254), an address inside the overlay range that no
 *           listing labels, and ov009/ov010 both overlap it.  Every other byte is
 *           right; the site caps at MATCH.  Promote when 0x02159254 gets a label.
 *
 * Registers the second argument under the key the first argument yields,
 * and installs the in-overlay handler the pool names.
 *
 * symbols:
 *   func_0215A684   0x0215A684  thumb  ov010
 *   func_02011330   0x02011330  thumb
 *   func_020113D0   0x020113D0  thumb
 *   func_02159254   0x02159254  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02011330(void *);
extern void func_0215A684(void *, void *);
extern void func_020113D0(void *, void (*)(void));
extern void func_02159254(void);

int func_02159260(void *a0, void *a1)
{
    func_0215A684(a1, func_02011330(a0));
    func_020113D0(a0, func_02159254);

    return 1;
}

