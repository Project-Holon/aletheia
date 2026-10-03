/*
 * function: func_021BA9D0
 * address: 0x021BA9D0
 * packet: pkt_ov110_021BA9D0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   func_021BF7A0 0x021BF7A0 thumb ov110
 *   func_021BFCA4 0x021BFCA4 thumb ov110
 *   func_021BFD60 0x021BFD60 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BF7A0(u8 *);
extern void func_021BFCA4(u8 *, int);
extern int func_021BFD60(u8 *);
extern void func_021B9CBC(u8 *);
void func_021BA9D0(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 **)p;
    switch (*(int *)(p + 0x14)) {
    case 0:
        func_021BFCA4(*(u8 **)(q + 0x5c), func_021BF7A0(*(u8 **)(q + 0x18)));
        (*(int *)(p + 0x14))++;
        break;
    case 1:
        if (func_021BFD60(*(u8 **)(q + 0x5c))) func_021B9CBC(p);
        break;
    }
}
