/*
 * unit:     yes
 * function: func_02188E90
 * function: func_02188F08
 * address:  0x02188E90
 * packet:   pkt_ov096_02188E90
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_02188F08 is the unlabelled store-and-return stub at 0x02188F08
 * (function_starts seed).
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A308  0x0218A308  thumb  ov096
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B99B8  0x021B99B8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[2];
    u16 f2;
    u8 pad04[0x38 - 4];
    int f38;
    u8 pad3C[0xb0 - 0x3c];
    int fb0;
    u8 padB4[4];
    int fb8;
    u8 padBC[8];
    int fc4;
} Conn;

extern int func_0201134C(int);
extern int func_0218A160(Conn *, int);
extern int func_0218A308(int, u8);
extern int func_021B8DE4(int, int);
extern int func_021B9AF8(int, int);
extern int func_021B99B8(int, int);
extern int func_021B9B94(int);
extern int func_021D5B7C(int);

int func_02188E90(int a, Conn *b)
{
    int x;
    int p;
    int n;

    x = func_021B8DE4(b->fb0, func_0218A160(b, func_0201134C(a)));
    p = func_021B9AF8(b->fb8, x);
    n = func_021B99B8(b->fb0, x);
    b->f38 = 0;
    for (; n < func_021B9B94(p); n++) {
        if (func_021D5B7C(func_0218A308(p, n)) != 0)
            b->f38++;
    }
    return b->fc4;
}

int func_02188F08(int a, Conn *b)
{
    b->f38 = b->f2;
    return b->fc4;
}
