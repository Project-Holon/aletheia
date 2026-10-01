/*
 * function: func_021D072C
 * address:  0x021D072C
 * packet:   pkt_ov021_021D072C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char s8;

typedef struct S {
    int *f0;
    int f4;
    u8 f8;
    s8 f9;
    s8 fA;
    u8 padB;
    u8 rows[6][0x14];
} S;

typedef struct Src021D072C {
    int *f0;
    int f4;
} Src021D072C;

extern Src021D072C *func_021AC1AC(void *a);
extern int func_0216D3CC(int p);

void func_021D072C(void *a, S *s)
{
    Src021D072C *r = func_021AC1AC(a);

    *(Src021D072C *)s = *r;
    s->fA = 0x78;
    s->f8 = func_0216D3CC(s->f4);
    s->f9 = 5;
}
