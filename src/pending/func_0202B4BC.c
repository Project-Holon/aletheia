/*
 * function: func_0202B4BC
 * address:  0x0202B4BC
 * packet:   pkt_0202B4BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: call target func_0202B59C is not yet an EXACT manifest entry and
 * str_020A772C is named by one pool word only, inside this range. Every
 * concrete byte reproduces.
 * status:   MATCH
 * symbols:
 *   str_020A772C  0x020A772C  data
 *
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 str_020A772C[];

extern void  *func_02030734(int a, int b, int c, void *d, int e);
extern void   func_0202B584(void *p);
extern void   func_0202B59C(void *p, u32 a, u32 b);

void *func_0202B4BC(u32 a, u32 b)
{
    void *p = func_02030734(b, 0x28, 0, (void *)str_020A772C, 0xa3);

    func_0202B584(p);
    func_0202B59C(p, a, b);
    return p;
}
