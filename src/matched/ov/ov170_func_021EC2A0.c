/*
 * function: func_021EC2A0
 * address: 0x021EC2A0
 * packet: pkt_ov170_021EC2A0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021EFD04 0x021EFD04 data a4
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021EBEE0 0x021EBEE0 thumb ov170
 */
typedef struct { short x, y; unsigned char pad4[2], b6, b7; int a, b, c; unsigned short e, d; } Desc;
extern const Desc d_021EFD04;
extern void *func_021EBEE0(char *, const Desc *);
void func_021EC2A0(char *p)
{
    Desc d;
    Desc base = d_021EFD04;
    unsigned i;
    for (i = 0; i < 0x25; i++) {
        d = base;
        d.x += (short)((i % 6) * 24);
        d.y += (short)((i / 6) * 24);
        d.b6 = 0x75 - i * 2;
        d.a = i;
        *(void **)(p + i * 4 + 0x9F40) = func_021EBEE0(p, &d);
        *(unsigned char *)(p + i + 0x3DD2) = i + 0x33;
    }
}
