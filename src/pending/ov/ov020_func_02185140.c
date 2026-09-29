/*
 * function: func_02185140
 * address:  0x02185140
 * packet:   pkt_ov020_02185140
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  byte-correct (212/212). The bl at +00BA to 0x02014184 has no
 *           witness: an unlabelled arm9 Thumb leaf (printed as .word data
 *           after func_020140F8), Ilias's to file. Evidence class: label /
 *           sole-ref/code. Verified C for the leaf, per
 *           ov020_func_021852F0.c:
 *   typedef struct { int f0; s16 h4, h6, h8, ha; int fc, f10, f14, f18; } Obj;
 *   void func_02014184(Obj *o, s16 a, s16 b, int c, int d, int e)
 *   { o->f0 = 1; o->h4 = a; o->h6 = -1; o->h8 = b; o->ha = 0; o->fc = 0;
 *     o->f10 = c; o->f14 = d; o->f18 = e; }
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020128E4  0x020128E4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200BFA4  0x0200BFA4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_020142A4  0x020142A4  thumb
 *   func_02014184  0x02014184  thumb
 *   func_021852F0  0x021852F0  thumb  ov020
 *   func_02185BFC  0x02185BFC  thumb  ov020
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02158590  0x02158590  thumb  ov010
 *   func_02176230  0x02176230  thumb  ov011
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned long long u64;

typedef struct { int f0; int f4; int f8; } S3;
typedef struct { int f[7]; } S7;

int func_0201210C(void *p);
void *func_020120F4(void *p);
void func_020128E4(void *p, S7 *s);
void *func_02012EBC(void *p);
void *func_0200BE48(void *p);
void *func_02012FCC(void *p);
u64 func_0200BFA4(void *p, void *x, int n);
void *func_02012138(void *p);
int func_02012B58(void *p);
int func_020142A4(int v);
void func_02014184(S7 *out, int b, s16 c, int d, int e, int f);
void func_021852F0(S7 *s, int v);
void *func_02185BFC(void *p, int a1, S7 *a2, int a3, int a4);
u8 *func_02158344(void *p);
int func_02158590(void *p);
int func_02176230(u8 *a, u8 *b);

void *func_02185140(void *a, int b, S3 *c, int d)
{
    int h;
    void *r4;
    S3 t;
    S7 w;
    S7 out;
    int r6;
    int r5;
    int r2;
    void *q;
    u8 *r7;

    h = func_0201210C(a);
    r4 = func_020120F4(a);
    t = *c;
    r6 = 0;
    func_021852F0(&w, h);
    func_020128E4(r4, &w);
    q = func_0200BE48(func_02012EBC(r4));
    func_0200BFA4(q, func_02012FCC(r4), 0);
    r7 = func_02158344(func_02012138(a));
    if (r7 == 0 || func_02158590(r4) == 0) {
        r5 = 0;
        r2 = 0;
    } else {
        r5 = func_02176230(r7, r7 + 0x1AC);
        r2 = r5 - func_02012B58(r4);
        if (r2 < 0)
            r2 += r7[0x902];
        r6 = 0x10000;
    }
    t.f0 += r6 + (r2 << 22);
    func_02014184(&out, b, func_020142A4(0), t.f0, t.f4, t.f8);
    return func_02185BFC(a, h, &out, d, r5);
}
