/*
 * function: func_021B7B8C
 * address: 0x021B7B8C
 * packet: pkt_ov173_021B7B8C
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   k_83 0x00000083 data a1
 *   func_021B6460 0x021B6460 thumb ov173
 *   func_021B7438 0x021B7438 thumb ov173
 *   func_020120F4 0x020120F4 thumb
 *   func_020120B4 0x020120B4 thumb
 *   d_021DC800 0x021DC800 data a4 ov131
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B6460(char *);
extern u16 func_021B7438(char **);
extern void *func_020120F4(void *);
extern void func_020120B4(void *, u32, void *, void *);
extern char d_021DC800[];
extern char k_83[];
int func_021B7B8C(char *p)
{
    char *q;
    u32 zero;
    func_021B6460(p);
    q = *(char **)p;
    *(u32 *)(p + 0x180) = *(u32 *)q;
    *(u32 *)(p + 0x184) = *(u32 *)(q + 8);
    *(void **)(p + 0x188) = func_020120F4(*(void **)(q + 0xc));
    zero = 0;
    *(u8 *)(p + 0x18c) = zero;
    *(u8 *)(p + 0x18f) = zero;
    *(u8 *)(p + 0x18e) = 1;
    *(u16 *)(p + 0x194) = func_021B7438((char **)p);
    *(u8 *)(p + 0x18d) = 2;
    *(u8 *)(p + 0x190) = zero;
    *(u32 *)(p + 0x198) = zero;
    func_020120B4(*(void **)(*(char **)p + 0xc), (u32)k_83, d_021DC800, p + 0x180);
    return 12;
}
