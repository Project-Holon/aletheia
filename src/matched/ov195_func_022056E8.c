/*
 * function: func_022056E8
 * address:  0x022056E8
 * packet:   pkt_022056E8
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_020A7370 0x020A7370 data a4
 *   d_02208F40 0x02208F40 data a4
 *   func_0201292C 0x0201292C thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AA14 0x0201AA14 thumb
 *   func_02007F68 0x02007F68 thumb
 *   func_02007F1C 0x02007F1C thumb
 *   func_020173EC 0x020173EC thumb
 *   func_02019CE0 0x02019CE0 thumb
 *   func_020178D8 0x020178D8 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02008F08 0x02008F08 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 *   func_02012F2C 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_02030734 0x02030734 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 d_020A7370;
extern u32 d_02208F40[];
extern u32 func_0201292C(u32);
extern int func_0201AA18(u32);
extern int func_0201AA14(u32);
extern int func_02007F68(u32, int, int, u16);
extern void func_02007F1C(u32, int, int, u16);
extern u32 func_020173EC(void);
extern u32 func_02030734(u16, u32, int, void *, u32);
extern void func_02019CE0(u32, u32);
extern void func_020178D8(u32, int);
extern void func_02017E40(u32, int, u32);
extern u32 func_02017E1C(u32, int, int);
extern u32 func_02045EC0(u32, u32);
extern void func_02045808(u32);
extern u32 func_02008F08(u16);
extern void func_020307B0(u32);
extern void func_0201A98C(u32, u32);
extern u32 func_0200CA1C(u32);
extern void func_0200CFA0(u32, u32);
extern void func_0200CDE0(u32, u32);
extern u32 func_02012F2C(u32);
extern void func_02008DF0(u32, int);

void func_022056E8(u32 *a, char *b)
{
    u32 save, p, q, v;
    int i;

    save = func_0201292C(a[0]);
    if (func_0201AA18(a[1]) >= func_0201AA14(a[1]))
        return;
    if (func_02007F68(save, 4, 1, *(u16 *)b) == 0)
        return;
    p = func_02030734(*(u16 *)b, func_020173EC(), 1, d_02208F40, 0xaf5);
    func_02019CE0(*(u32 *)(b + 0x10), p);
    func_020178D8(p, 0x124);
    func_02017E40(p, 0x98, 4);
    func_02017E40(p, 6, 0);
    func_02017E40(p, 0xb, 0);
    for (i = 0x19; i < 0x36; i++)
        func_02017E40(p, i, 0);
    for (i = 0x4d; i < 0x6d; i++)
        func_02017E40(p, i, 0);
    for (i = 0x78; i < 0x8d; i++)
        func_02017E40(p, i, 0);
    v = func_02045EC0(d_020A7370, func_02017E1C(p, 5, 0));
    func_02017E40(p, 0x73, v);
    func_02045808(v);
    func_02017E40(p, 0x9d, 0);
    v = func_02008F08(*(u16 *)b);
    func_02017E40(p, 0xa7, v);
    func_020307B0(v);
    func_02017E40(p, 0x9f, 0);
    func_0201A98C(a[1], p);
    func_02007F1C(save, 4, 1, *(u16 *)b);
    func_020307B0(p);
    q = func_0200CA1C(a[0]);
    func_0200CFA0(q, p);
    func_0200CDE0(q, p);
    q = func_02012F2C(a[0]);
    func_02008DF0(q, 10);
    func_02008DF0(q, 0x58);
}
