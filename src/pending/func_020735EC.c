/*
 * function: func_020735EC
 * address:  0x20735EC
 * packet:   pkt_02073548
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  0x02089330 has no witness outside this range: its only caller is 0x02073610, inside this function (0x020893D0 is witnessed from 0x020732E0 and 0x0207368C from 0x0207325C)
 *
 * The -0x2D3 argument is a plain pooled literal, not an address: it is a
 *  * signed 32-bit constant the original keeps in its own pool word.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct X { u8 pad00[0x2c]; u8 b2c; u8 pad2[0x3c - 0x2d]; u8 b3c; };
extern void func_020893D0(u32, int);
extern void func_02089330(u32);
extern void func_0207368C(struct X *);

void func_020735EC(struct X *x)
{
    if (x->b2c == 2) func_020893D0(x->b3c, 0xFFFFFD2D);
    func_02089330(x->b3c);
    func_0207368C(x);
}
