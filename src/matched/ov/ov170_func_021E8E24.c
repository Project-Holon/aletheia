/*
 * unit: yes
 * function: func_021E8E24, func_021E8F14
 * address: 0x021E8E24
 * packet: pkt_ov170_021E8E24
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_020216D4 0x020216D4 thumb
 *   func_020056BC 0x020056BC thumb
 *   func_0202173C 0x0202173C thumb
 *   func_021DED58 0x021DED58 thumb ov170
 *   func_02007838 0x02007838 thumb
 *   func_021EDAB0 0x021EDAB0 thumb ov170
 *   func_021E95CC 0x021E95CC thumb ov170
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021ED55C(char *, int);
extern void func_020216D4(void *, u32, u32, u32);
extern u32 func_020056BC(void);
extern int func_0202173C(void *, u16, u16, s16, u8, u8, u16, void *);
extern void func_021DED58(char *, int);
extern void func_02007838(void *, unsigned, unsigned);
extern void func_021EDAB0(char *, int);
extern int func_021E95CC(unsigned char *, unsigned char);
#define W (*(char **)(p + 0x2c))
#define S (*(int *)(W + 0xA194))
int func_021E8E24(char *p)
{
    switch (S) {
    case 0:
        func_021ED55C(p, 0);
        func_020216D4(*(void **)(W + 0x6c), 0, 0, 0x200);
        func_0202173C(*(void **)(W + 0x6c), 1, 0xc000, 0, 0, 16, 0x7fff, (void *)func_020056BC());
        *(int *)(p + 0x28) = 0x66;
        S++;
        return 3;
    case 1:
        func_021DED58(p, *(u8 *)(W + 0xA17B));
        func_02007838(*(void **)(*(char **)p + 4), *(u8 *)(p + 0x14), *(u8 *)(W + 0xA17B));
        func_021EDAB0(p, *(u8 *)(p + 0x14));
        S++;
        break;
    case 2:
        func_0202173C(*(void **)(W + 0x6c), 1, 0xc000, 0, 16, 0, 0x7fff, (void *)func_020056BC());
        *(int *)(p + 0x28) = 0x66;
        S++;
        return 3;
    case 3:
        func_021ED55C(p, 1);
        S = 0;
        return 0x65;
    }
    return 0x66;
}
int func_021E8F14(unsigned char *p)
{
    return func_021E95CC(p, 2);
}
