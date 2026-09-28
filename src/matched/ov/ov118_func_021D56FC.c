/*
 * function: func_021D56FC
 * address:  0x021D56FC
 * packet:   pkt_ov118_021D56FC
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5694  0x021D5694  thumb  ov118
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021E3034  0x021E3034  thumb  ov119
 *   func_021E2F2C  0x021E2F2C  thumb  ov119
 *   func_021DFDA0  0x021DFDA0  thumb  ov119
 *   func_020307B0  0x020307B0  arm
 *
 * Same body as ov118 func_021D6C78 (third copy of this module); the first
 * callee is this overlay's own copy at 0x021D5694.
 *
 * Addresses are Black-image addresses.
 */

extern void func_021D5694(void *);
extern void func_021E3034(void *, int);
extern void func_021E2F2C(void *);
extern void func_020307B0(void *);
extern void func_021D8E84(void *, int);
extern void func_021DFDA0(void);

void func_021D56FC(void *p)
{
    func_021D5694(p);
    func_021E3034(*(void **)((char *)p + 0xc), 6);
    func_021E2F2C(*(void **)((char *)p + 0xc));
    func_020307B0(*(void **)((char *)p + 0xc));
    *(void **)((char *)p + 0xc) = 0;
    func_021D8E84(p, (int)func_021DFDA0);
}
