/*
 * function: func_02185080
 * address: 0x02185080
 * packet: pkt_ov023_02185080
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021864C4 0x021864C4 thumb ov023
 */
typedef unsigned short u16;
typedef struct { u16 n, a, b, pad; } Ent;
typedef struct { unsigned char b[4]; unsigned char lo:3, mid:3, hi:2; } Rec;
extern void func_021864C4(Rec *d, Ent *s, int a, int c);
void func_02185080(Rec *d, int a, int c)
{
    unsigned char buffer[0x44];
    ((Ent *)buffer)[0].n = 0;
    ((Ent *)buffer)[0].a = 0;
    ((Ent *)buffer)[0].b = 0;
    func_021864C4(d, (Ent *)buffer, a, c);
}
