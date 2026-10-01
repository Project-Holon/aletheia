/*
 * function: func_021B6B0C
 * address: 0x021B6B0C
 * packet: pkt_ov173_021B6B0C
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7438 0x021B7438 thumb ov173
 *   func_02017E40 0x02017E40 thumb
 *   func_0201C158 0x0201C158 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021B7438(char **);
extern void func_02017E40(void *, u32, u32);
extern u32 func_0201C158(u16, u8);
int func_021B6B0C(char **p)
{
    char *q;
    u32 zero;
    q = *p;
    func_02017E40(*(void **)q, *(u8 *)(q + 0x1b) + 0x36, func_021B7438(p));
    q = *p;
    zero = 0;
    func_02017E40(*(void **)q, *(u8 *)(q + 0x1b) + 0x3e, 0);
    q = *p;
    func_02017E40(*(void **)q, *(u8 *)(q + 0x1b) + 0x3a, func_0201C158(func_021B7438(p), 0));
    *(u8 *)(*p + 0x1a) = zero;
    return 8;
}
