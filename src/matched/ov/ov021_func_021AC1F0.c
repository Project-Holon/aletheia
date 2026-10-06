/*
 * function: func_021AC1F0
 * address:  0x021AC1F0
 * packet:   pkt_ov021_021AC1F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02022040  0x02022040  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Res { u8 pad[0x30]; u16 h30; u16 pad32; u32 f34; u32 f38; } Res;
typedef struct X { u8 pad[0x24]; u32 f24; } X;

struct Tagged;
extern void *func_02046F48(struct Tagged *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_02022040(u16 *pal, int n, const u8 *table);

void func_021AC1F0(X *x, void *b)
{
    Res *p;

    if (x->f24 != 0) {
        p = (Res *)func_0206E964(func_02046F48(b));
        func_02022040((u16 *)((u8 *)p + p->f38), p->h30 * 8u / 2, (const u8 *)x->f24);
    }
}
