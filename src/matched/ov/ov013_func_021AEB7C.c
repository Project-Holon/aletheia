/*
 * function: func_021AEB7C
 * address:  0x021AEB7C
 * packet:   pkt_ov013_021AEB7C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Microphone sampling step: with mode 0 clears the n buffers; otherwise
 * stops the pending auto-sampling (param block at G+0x1A20, busy flag
 * G+0x1A4B), picks the sample window, processes each buffer and, unless
 * G+0x19B0 is set, analyses the window. Callback is the empty leaf
 * func_021AEB78.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_0208B2BC  0x0208B2BC  arm
 *   func_0208B4C8  0x0208B4C8  arm
 *   func_0208B4B8  0x0208B4B8  arm
 *   func_021B0B48  0x021B0B48  arm  ov013
 *   func_021B07F8  0x021B07F8  arm  ov013
 *   func_021AEB78  0x021AEB78  thumb  ov013
 *   d_021B3C80     0x021B3C80  data  ov013
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *d_021B3C80;

extern void func_02082BCC(void *p, int v, u32 n);
extern u32 func_0202EB0C(void);
extern int func_0208B2BC(void *param, void (*cb)(void), void *arg);
extern int func_0208B4C8(void *param, void (*cb)(void), void *arg);
extern u32 func_0208B4B8(void);
extern int func_021B0B48(void *a, u32 b, int *out);
extern void func_021B07F8(u8 *addr, u32 size);
extern void func_021AEB78(void);

void func_021AEB7C(int mode, u32 n, void **bufs, u32 size, int unused, u32 arg6)
{
    u8 *addr;
    u32 i;

    addr = (u8 *)arg6;

    if (mode == 0) {
        for (i = 0; i < n; i++) {
            func_02082BCC(bufs[i], 0, size);
        }
        return;
    }
    if (func_0202EB0C() == 0) {
        if (d_021B3C80[0x1A4B] != 0) {
            func_0208B2BC(d_021B3C80 + 0x1A20, func_021AEB78, 0);
            d_021B3C80[0x1A4B] = 0;
        }
    } else {
        if (d_021B3C80[0x1A4B] != 0) {
            func_0208B4C8(d_021B3C80 + 0x1A20, func_021AEB78, 0);
            d_021B3C80[0x1A4B] = 0;
        }
    }
    if ((u32)(func_0208B4B8() - (u32)addr) < size) {
        addr = addr + size;
    }
    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0
        || *(u16 *)(d_021B3C80 + 0x19B2) != 0) {
        addr = d_021B3C80 + 0x1104;
    }
    for (i = 0; i < n; i++) {
        func_021B0B48(bufs[i], size, 0);
    }
    if (*(u16 *)(d_021B3C80 + 0x19B0) == 0) {
        func_021B07F8(addr, size);
    }
    d_021B3C80[0x1A4A] = 2;
}
