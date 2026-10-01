/*
 * function: func_021B7378
 * address: 0x021B7378
 * packet: pkt_ov173_021B7378
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_021B7438 0x021B7438 thumb ov173
 *   func_021B7448 0x021B7448 thumb ov173
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   d_021B8350 0x021B8350 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0201EEF4(void *, u32, u32);
extern void func_0201EF34(void *, u32, u32);
extern void func_0201F02C(void *, u32, u32);
extern u16 func_021B7438(char **);
extern u16 func_021B7448(char **);
extern void *func_02045EC0(void *, u32);
extern void func_0201F250(void *, void *, void *);
extern void func_02045808(void *);
extern const u32 d_021B8350[][11];
void func_021B7378(char *p, u32 kind)
{
    void *str;
    switch (kind) {
    case 0: func_0201EEF4(*(void **)(p + 0x48), 0, **(u32 **)p); break;
    case 1: func_0201EF34(*(void **)(p + 0x48), 1, func_021B7438((char **)p)); break;
    case 2: func_0201EEF4(*(void **)(p + 0x48), 0, **(u32 **)p); break;
    case 3:
        func_0201EEF4(*(void **)(p + 0x48), 0, **(u32 **)p);
        func_0201EF34(*(void **)(p + 0x48), 1, func_021B7438((char **)p)); break;
    case 4:
        func_0201EEF4(*(void **)(p + 0x48), 0, **(u32 **)p);
        func_0201EF34(*(void **)(p + 0x48), 1, func_021B7438((char **)p)); break;
    case 5:
        func_0201EEF4(*(void **)(p + 0x48), 0, **(u32 **)p);
        func_0201EF34(*(void **)(p + 0x48), 1, func_021B7448((char **)p)); break;
    case 6:
        func_0201EEF4(*(void **)(p + 0x48), 0, **(u32 **)p);
        func_0201EF34(*(void **)(p + 0x48), 1, func_021B7438((char **)p)); break;
    case 7: func_0201EF34(*(void **)(p + 0x48), 1, func_021B7438((char **)p)); break;
    case 8:
        func_0201EEF4(*(void **)(p + 0x48), 0, **(u32 **)p);
        func_0201EF34(*(void **)(p + 0x48), 1, func_021B7438((char **)p)); break;
    case 9: func_0201F02C(*(void **)(p + 0x48), 2, *(u32 *)(*(char **)p + 4)); break;
    case 10: func_0201EF34(*(void **)(p + 0x48), 0, func_021B7448((char **)p)); break;
    }
    str = func_02045EC0(*(void **)(p + 0x44), d_021B8350[*(u8 *)(*(char **)p + 0x19)][kind]);
    func_0201F250(*(void **)(p + 0x48), *(void **)(p + 0x4c), str);
    func_02045808(str);
}
