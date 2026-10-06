/*
 * function: func_0219E968
 * address:  0x0219E968
 * packet:   pkt_ov021_0219E968
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02164380  0x02164380  thumb  ov010
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0219EA5C  0x0219EA5C  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern int func_02164380(void *a, u16 *b);
extern void *func_0216D684(u32, u32);
extern int func_0219EA5C(void *a, u32 b);
extern void func_02082BCC(void *, int, int);
extern void func_0219E2C0(void *a, void *r);

void *func_0219E968(u32 a, u32 size)
{
    u8 buf[8];
    int ok = func_02164380((void *)a, (u16 *)buf);
    void *q = func_0216D684(a, size);
    func_0219EA5C(q, a);
    if (ok) {
        func_0219E2C0((void *)a, buf);
    } else {
        func_02082BCC(buf, 0, 8);
        func_0219E2C0((void *)a, buf);
    }
    return q;
}
