/*
 * function: func_021C0904
 * address:  0x021C0904
 * packet:   pkt_ov021_021C0904
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218C584  0x0218C584  thumb  ov021
 *   func_0218C6D0  0x0218C6D0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u16 func_02188C84(u8 *p);
extern u32 func_02188C98(u8 *p);
extern u32 func_0218DC6C(u32 a);
extern void *func_02188CB4(unsigned char *p);
extern void func_021A3038(void *a, int *pos);
extern u32 *func_0218C584(u32 a, int *rect, u32 n, int *cnt);
extern void func_0218C6D0(u32 a, u8 *dst);
extern void func_020307B0(void *p);

void func_021C0904(u8 *p, u32 a, u32 n)
{
    void *s;
    u32 w;
    u32 t;
    u32 *r;
    int pos[3];
    int rect[4];
    int cnt;

    s = func_0201210C((void *)a);
    w = func_02188C84(s);
    t = func_02188C98(s);
    *(u16 *)p = w;
    p[0x14] = n;
    *(void **)(p + 4) = s;
    p[0x15] = 0;
    *(u32 *)(p + 0x18) = func_0218DC6C(t);
    *(u32 *)(p + 0x34) = 0;
    if (p[0x14] > 6) {
        p[0x14] = 6;
    }
    func_021A3038(func_02188CB4(*(void **)(p + 4)), pos);
    rect[0] = pos[2] - 0x50000;
    rect[1] = pos[2] + 0x50000;
    rect[2] = pos[0] - 0x50000;
    rect[3] = pos[0] + 0x50000;
    r = func_0218C584(*(u32 *)(p + 0x18), rect, 3, &cnt);
    if (r) {
        *(u32 *)(p + 0x34) = *r;
        func_0218C6D0(*r, p + 8);
    }
    func_020307B0(r);
}
