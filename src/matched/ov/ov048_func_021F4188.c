/*
 * function: func_021F4188
 * address:  0x021F4188
 * packet:   pkt_ov048_021F4188
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02088864  0x02088864  arm
 *   func_021F3D38  0x021F3D38  thumb
 *   d_021F50C0     0x021F50C0  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02088864(void *);
extern void func_021F3D38(int *p, int unused, int b, int *c);
extern u8 d_021F50C0[];

void func_021F4188(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } s;
    int buf[4];

    func_02088864(buf);
    switch (buf[3]) {
    case 0: s.f = *(int *)(p[7] + 0x40); break;
    case 1: s.f = *(int *)(p[7] + 0x34); break;
    case 2: s.f = *(int *)(p[7] + 0x28); break;
    case 3: s.f = *(int *)(p[7] + 0x38); break;
    case 4: s.f = *(int *)(p[7] + 0x2c); break;
    case 5: s.f = *(int *)(p[7] + 0x3c); break;
    case 6: s.f = *(int *)(p[7] + 0x30); break;
    }
    s.a = *(u16 *)(d_021F50C0 + 0xc);
    s.b = *(int *)(d_021F50C0 + 0x3c);
    s.c = *(int *)(d_021F50C0 + 0x58);
    s.d = 2;
    s.e = 0x26;
    s.g = 0;
    func_021F3D38(p, (int)&s, 5, 0);
}
