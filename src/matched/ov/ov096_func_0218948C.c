/*
 * unit:     yes
 * function: func_0218948C
 * function: func_021894B4
 * function: func_021894C4
 * address:  0x0218948C
 * packet:   pkt_ov096_0218948C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021894B4 and func_021894C4 are the unlabelled store-and-return stubs
 * after the lead function (function_starts seeds).
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D69AC  0x021D69AC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0x38];
    int f38;
    u8 pad3C[0x98 - 0x3c];
    int f98;
    int f9c;
    u8 padA0[0xc4 - 0xa0];
    int fc4;
} Conn;

extern int func_0201134C(int);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern unsigned char func_021D69AC(unsigned char *base, int idx);

int func_0218948C(int a, Conn *b)
{
    b->f38 = func_021D69AC(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, func_0201134C(a))), 0);
    return b->fc4;
}

int func_021894B4(int a, Conn *b)
{
    b->f38 = b->f98;
    return b->fc4;
}

int func_021894C4(int a, Conn *b)
{
    b->f38 = b->f9c;
    return b->fc4;
}
