/*
 * function: func_021D9248
 * address:  0x021D9248
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   func_02008564  0x02008564  thumb
 *   func_02008574  0x02008574  thumb
 *   func_02025C1C  0x02025C1C  thumb
 *   func_02025C30  0x02025C30  thumb
 *   func_0202EB7C  0x0202EB7C  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
struct Big;
struct Sub02009470Obj;
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern void func_02082D44(void *dst, const void *src, int n);
extern u8 func_0200856C(void *p);
extern u8 func_02008570(void *p);
extern u8 func_02008564(void *p);
extern void func_02008574(void *p, u8 a, u8 b);
extern u32 func_02025C1C(u32 a, u32 b, u32 c);
extern u32 func_02025C30(u32 a, u32 b, u32 c);
extern u32 func_0202EB7C(u32 a0, u32 a1);

void func_021D9248(void *p, int a1, void *a2, char *a3, int a4)
{
    u8 buf[0x28];
    u8 x, y;
    u32 r1, r2;
    void *saved;

    if (a4 != (int)func_020399A8())
        return;
    if (p == (void *)func_0203D1A4((struct Link *)((u32)func_020399A8())))
        return;
    saved = func_02009470(func_02012EBC(*(void **)(a3 + 0x82c)));
    func_02082D44(a2, buf, 0x28);
    x = func_0200856C(buf);
    y = func_02008570(buf);
    r1 = func_02025C1C(x, y, func_02008564(buf));
    r2 = func_02025C30(x, y, func_02008564(buf));
    if (x == r1 && y == r2)
        func_02008574(buf, x, y);
    else
        func_02008574(buf, 0, 0);
    func_0202EB7C((u32)saved, (u32)buf);
}
