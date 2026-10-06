/*
 * function: func_021EDB3C
 * address:  0x021EDB3C
 * packet:   pkt_ov093_021EDB3C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049DB4  0x02049DB4  arm
 *   func_02043678  0x02043678  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct X {
    u8 pad00[0x14];
    char *f14;
};

struct E {
    struct S *f00;
    int f04;
    u16 f08;
    u8 f0a;
    u8 f0b;
    u8 f0c;
    u8 pad0d[3];
    char *f10;
    u8 pad14[8];
    char *f1c;
    u8 pad20[2];
    u8 f22_0 : 1;
};

struct S {
    u8 pad00[0x90];
    struct E e[2];
    int fd8;
    struct X *fdc;
    u8 pade0[0x13c - 0xe0];
    u16 f13c;
};

struct Bmp;
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);

void func_021EDB3C(struct S *s, char *a1)
{
    u32 i;

    s->fd8 = (int)func_02049DB4(0xb, 0xd5, 0, (u32)(&s->fdc), s->f13c);
    for (i = 0; i < 2; i++) {
        s->e[i].f00 = s;
        s->e[i].f0a = i;
        s->e[i].f0b = (i == 0) ? 2 : 3;
        s->e[i].f10 = s->fdc->f14 + i * 0x900;
        s->e[i].f04 = (int)func_02043678(0x12, 4, 0x20, s->f13c);
        s->e[i].f08 = 0;
        s->e[i].f0c = 0x1f;
        s->e[i].f1c = a1 + i * 0x48;
        s->e[i].f22_0 = 0;
    }
}
