/*
 * function: func_02201CBC
 * address: 0x02201CBC
 * packet: pkt_ov135_02201CBC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200ADE0 0x0200ADE0 thumb
 *   func_022022B8 0x022022B8 thumb ov135
 *   func_022024B0 0x022024B0 thumb ov135
 *   func_02201B44 0x02201B44 thumb ov135
 *   func_0220251C 0x0220251C thumb ov135
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0200ADE0(void *);
extern void func_022022B8(void *, void *, u32, int);
extern void func_022024B0(void *, void *);
extern void func_02201B44(void *, void *, void *, void *);
extern void func_0200AD94(void *, u16);
extern void func_0220251C(void *, u32, u32);
int func_02201CBC(u8 *p)
{
    func_022022B8(p, p + 0xe4, func_0200ADE0(**(void ***)p), *(s8 *)(p + 0x207));
    func_022024B0(*(void **)(*(u8 **)p + 0x18), p + 0xe4);
    func_02201B44(p, p + 0xe4, p + 0xe4, 0);
    func_0200AD94(**(void ***)p, 0);
    *(u32 *)(p + 0x28) = 0x22;
    func_0220251C(p, 0x17, 0xf);
    return 2;
}
