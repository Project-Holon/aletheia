/*
 * function: func_0220CAF0
 * address:  0x0220CAF0
 * packet:   pkt_0220CAF0
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022110D4 0x022110D4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045738 0x02045738 arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int   func_022110D4(u8 *p, int i);
extern void *func_02045EC0(void *a, u32 b);
extern u32   func_02045770(void *a);
extern void  func_0201C724(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void  func_02045808(void *a);
extern u32   func_020457B0(u32 a, u32 b);
extern void  func_0201EFA4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void  func_0201F250(void *a, u32 b, void *c);
extern u32   func_0201D304(u32 a, u32 b, u32 c);
extern u32   func_02045738(void *a);

void func_0220CAF0(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + func_022110D4((u8 *)p, i) * 0x4c;
    t = func_02045EC0(*(void **)(p + 0x1ea0), 0x32);
    x = *(u32 *)(p + 0x1eac);
    y = func_02045770(*(void **)(p + 0x1ff0));
    func_0201C724(x, y, 0, 0, (u32)t, *(u32 *)(*(u32 *)p + 0xc), 0x3dc0);
    *(u8 *)(p + 0x1ff4) = 1;
    func_02045808(t);
    t2 = func_02045EC0(*(void **)(p + 0x1ea0), 0x33);
    h = func_020457B0(8, *(u16 *)(*(u32 *)p + 0x10));
    func_0201EFA4(*(void **)(p + 0x1ea4), 0, *(u16 *)(elem + 0xa), 3, 0, 1);
    func_0201F250(*(void **)(p + 0x1ea4), h, t2);
    b = func_0201D304(h, *(u32 *)(*(u32 *)p + 0xc), 0);
    c = (func_02045738(*(void **)(p + 0x1fa8)) << 3) - b;
    d = *(u32 *)(p + 0x1eac);
    e = func_02045770(*(void **)(p + 0x1fa8));
    func_0201C724(d, e, c, 0, h, *(u32 *)(*(u32 *)p + 0xc), 0x2120);
    *(u8 *)(p + 0x1fac) = 1;
    func_02045808(t2);
    func_02045808((void *)h);
}
