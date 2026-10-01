/*
 * function: func_021F4AE4
 * address: 0x021F4AE4
 * packet: pkt_ov194_021F4AE4
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware 0x04000050, 0x04001050, 0x04000000, 0x04001000.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   sub_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   sub_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021F4C0C 0x021F4C0C thumb ov194
 *   func_021F4CB0 0x021F4CB0 thumb ov194
 *   sub_020056A0 0x020056A0 thumb
 *   d_021F5784 0x021F5784 data a1
 *   d_021F55D0 0x021F55D0 data a4
 *   func_021F4BF8 0x021F4BF8 thumb ov194
 */
struct DispVram;
extern const char d_021F5784[];
extern const struct DispVram d_021F55D0;
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void sub_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void sub_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021F4C0C(void *, unsigned short);
extern void func_021F4CB0(unsigned char *, int, int);
extern void *sub_020056A0(unsigned, unsigned, unsigned);
extern void func_021F4BF8(void);
static inline void G2_BlendNone(void) { *(volatile unsigned short *)0x04000050 = 0; }
static inline void G2S_BlendNone(void) { *(volatile unsigned short *)0x04001050 = 0; }
static inline void GX_SetVisibleWnd(int window) { *(volatile unsigned *)0x04000000 = (*(volatile unsigned *)0x04000000 & ~0xE000) | (window << 13); }
static inline void GXS_SetVisibleWnd(int window) { *(volatile unsigned *)0x04001000 = (*(volatile unsigned *)0x04001000 & ~0xE000) | (window << 13); }
unsigned char *func_021F4AE4(unsigned swap, unsigned short heap)
{
    unsigned char *p;
    p = func_02030734(heap, 0x10, 0, d_021F5784, 0x1BB);
    func_02082BCC(p, 0, 0x10);
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    sub_0204335C(0);
    func_020433E0(&d_021F55D0);
    func_0204363C(swap);
    func_0204361C();
    sub_020434CC();
    func_02043588();
    func_0201DD60();
    func_021F4C0C(p, heap);
    func_021F4CB0(p + 4, (int)&d_021F55D0, heap);
    *(void **)(p + 0xC) = sub_020056A0((unsigned)func_021F4BF8, (unsigned)p, 0);
    return p;
}
