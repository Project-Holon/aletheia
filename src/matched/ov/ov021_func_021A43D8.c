/*
 * function: func_021A43D8
 * address:  0x021A43D8
 * packet:   pkt_ov021_021A43D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0202E83C  0x0202E83C  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021A428C  0x021A428C  thumb  ov021
 *   func_02164208  0x02164208  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021A3960(unsigned char *p);
extern u32 func_02188C80(u32);
extern u32 func_0202E83C(u32);
extern void func_0216D88C(void *, u32 *);
extern int func_021A428C(u8 *, int, u32 *, int, u32);
extern void func_02164208(int, u32 *, int);

void func_021A43D8(u8 *p, int k, int dir)
{
    u32 buf[3];
    void *a;
    u32 r;

    if (k != 2) {
        *(u16 *)(p + 0x18) = 0x546;
        *(u16 *)(p + 0x1a) = 0;
        return;
    }
    a = func_021A3960(*(void **)(p + 0xc));
    r = func_0202E83C(func_02188C80(*(u32 *)(p + 0x10)));
    func_0216D88C(a, buf);
    if (func_021A428C(p, k, buf, 0, r) == 0) {
        func_02164208(dir, buf, 0x10000);
        func_021A428C(p, k, buf, 1, r);
    }
}
