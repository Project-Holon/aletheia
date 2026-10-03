/*
 * function: func_021E9D04
 * address: 0x021E9D04
 * packet: pkt_ov093_021E9D04
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B90E8 0x021B90E8 thumb ov093
 *   func_021B90F0 0x021B90F0 thumb ov093
 *   func_021E9E60 0x021E9E60 thumb ov093
 *   func_021BA1E4 0x021BA1E4 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_021B9B04 0x021B9B04 thumb ov093
 *   func_021E9984 0x021E9984 thumb ov093
 *   func_021D3D7C 0x021D3D7C thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021B90E8(void *);
extern void *func_021B90F0(void *);
extern int func_021E9E60(void *);
extern char *func_021BA1E4(char **);
extern void *func_021B86B8(void ***);
extern int func_021BA1A8(void *, int);
extern u32 func_021B9B04(int, int);
extern void func_021E9984(u8 *, u8 *, int, u8, int);
extern void *func_021D3D7C(void *);
extern u8 func_021B9B94(void *);
extern u8 *func_021B9C00(void *p, u32 i);
extern int func_021D62C4(void *, int);

void func_021E9D04(u8 *p, int x, u8 a, u8 b, u8 c, u8 d)
{
    u32 i;
    u32 n;
    void *list;
    int flag;
    if (p[0x174]) return;
    *(void **)(p + 0xc8) = func_021B90E8(*(void **)p);
    *(void **)(p + 0xe4) = func_021B90F0(*(void **)p);
    *(int *)(p + 0xd0) = x;
    *(u32 *)(p + 0xcc) = *(u32 *)(p + 0xb0);
    *(u16 *)(p + 0xd4) = *(u16 *)(p + 0x184);
    p[0xdc] = a;
    p[0xdd] = b;
    *(u16 *)(p + 0xde) = 0;
    *(int *)(p + 0xf4) = func_021E9E60(*(void **)(p + 0x180));
    *(int *)(p + 0xe8) = 0;
    *(char **)(p + 0xd8) = func_021BA1E4(*(char ***)p);
    flag = 0;
    if ((int)func_021B86B8(*(void ****)p) != 3) flag = 1;
    *(int *)(p + 0x108) = flag;
    *(int *)(p + 0xec) = 0;
    flag = 0;
    if (func_021B86B8(*(void ****)p) == 0) flag = 1;
    p[0xf1] = flag;
    p[0xe1] = 0;
    flag = 0;
    if (c == 0) flag = 3;
    else if (func_021BA1A8(*(void **)p, 0x40)) flag = 1;
    else if (func_021B86B8(*(void ****)p) == 0) {
        if (func_021B9B04(*(int *)(p + 8), 1) > 1) flag = 2;
        else if (d) flag = 4;
    }
    p[0xf0] = flag;
    func_021E9984(p, p + 0x10c, 3, 0, 0);
    list = func_021D3D7C(*(void **)(p + 4));
    n = func_021B9B94(list);
    for (i = 0; i < n; i++)
        p[0x144 + i] = func_021D62C4(func_021B9C00(list, (u8)i), 0x13);
    for (; i < 6; i++) p[0x144 + i] = 0;
    p[0x174] = 1;
}
