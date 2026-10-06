/*
 * function: func_021C0D3C
 * address:  0x021C0D3C
 * packet:   pkt_021C0D3C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C0C14 0x021C0C14  thumb  ov208
 *   func_021C0CCC 0x021C0CCC  thumb  ov208

 * Stores the byte result of func_021C0C14 at +0x79 of the second argument then calls func_021C0CCC.
 */


extern char func_021C0C14(int, char *, int);
typedef unsigned short u16;
typedef unsigned char  u8;
extern void func_021C0CCC(u16 *heap, u8 *p, int key);

void func_021C0D3C(int a, char *b, int c)
{
    b[0x79] = func_021C0C14(a, b, c);
    func_021C0CCC((u16 *)a, (u8 *)b, c);
}

