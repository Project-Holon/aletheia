/*
 * function: func_021B6E74
 * address: 0x021B6E74
 * packet: pkt_ov133_021B6E74
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F5164 0x021F5164 thumb ov112
 *   func_021F5438 0x021F5438 thumb ov112
 *   func_021F5444 0x021F5444 thumb ov112
 *   func_021F5204 0x021F5204 thumb ov112
 *   func_021F51E8 0x021F51E8 thumb ov112
 *   func_021F51F4 0x021F51F4 thumb ov112
 *   func_021F545C 0x021F545C thumb ov112
 *   func_021F5350 0x021F5350 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021F5164(u32);
extern void func_021F5438(u8 *, int);
extern void func_021F5444(u8 *, int);
extern u8 *func_021F5204(u8 *, void *, int);
extern void func_021F51E8(u8 *);
extern void func_021F51F4(u8 *);
extern int *func_021F545C(u8 *);
extern void func_021F5350(u8 *, int *);
void func_021B6E74(u8 *p)
{
    int v[3];
    int *q;
    *(u8 **)(p + 0x187c) = func_021F5164(*(u16 *)p);
    func_021F5438(*(u8 **)(p + 0x187c), 0x50000);
    func_021F5444(*(u8 **)(p + 0x187c), 0x3fe0);
    *(u8 **)(p + 0x1880) = func_021F5204(*(u8 **)(p + 0x187c), (*(void ***)(p + 4))[1], 0);
    func_021F51E8(*(u8 **)(p + 0x187c));
    func_021F51F4(*(u8 **)(p + 0x187c));
    q = func_021F545C(*(u8 **)(p + 0x1880));
    v[0] = (0x80000 - q[0]) / 16;
    v[1] = (0xc0000 - (0x70000 - q[1])) / 16;
    v[2] = 0x28000;
    func_021F5350(*(u8 **)(p + 0x1880), v);
}
