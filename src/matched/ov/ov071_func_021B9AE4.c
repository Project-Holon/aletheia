/*
 * function: func_021B9AE4
 * address:  0x021B9AE4
 * packet:   pkt_ov071_021B9AE4
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02043678  0x02043678  arm
 *   func_020255A0  0x020255A0  thumb
 *   d_021BAB10     0x021BAB10  data  a4
 */

typedef unsigned char u8;

typedef struct {
    void *f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
} Tmpl;

typedef struct {
    u8 pad00[0x2a0];
    void *a2a0[7];
    void *a2bc[7];
} Work;

typedef struct {
    u8 pad00[0x2c];
    void *f2c;
    u8 pad30[0x5c - 0x30];
    int f5c;
} Src;

extern void *func_02043678(int, int, int, int);
extern void *func_020255A0(void *, Tmpl *);
extern const Tmpl d_021BAB10;

void func_021B9AE4(Work *p, Src *s)
{
    int i;
    Tmpl t;

    t = d_021BAB10;
    t.f08 = s->f5c;
    for (i = 0; i < 7; i++) {
        p->a2bc[i] = func_02043678(0x17, 2, 0x20, 0x61);
        t.f00 = p->a2bc[i];
        p->a2a0[i] = func_020255A0(s->f2c, &t);
    }
}
