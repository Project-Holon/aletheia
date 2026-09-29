/*
 * function: func_02185458
 * address:  0x02185458
 * packet:   pkt_ov020_02185458
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 *
 * blocker: byte-correct; the bl to 0x02014184 has no witness (unlabelled ARM9
 * Thumb leaf, sole caller in range). Evidence class: label / sole-ref/code.
 * Leaf 0x02014184 (arm9, Thumb, EXACT with match.py one, Ilias's to file):
 *   typedef short s16;
 *   typedef struct { int f0; s16 h4, h6, h8, ha; int fc, f10, f14, f18; } Obj;
 *   void func_02014184(Obj *o, s16 a, s16 b, int c, int d, int e)
 *   { o->f0 = 1; o->h4 = a; o->h6 = -1; o->h8 = b; o->ha = 0; o->fc = 0;
 *     o->f10 = c; o->f14 = d; o->f18 = e; }
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02014184  0x02014184  thumb
 *   func_020142A4  0x020142A4  thumb
 *   func_02184504  0x02184504  thumb  ov020
 *   func_02184CEC  0x02184CEC  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short s16;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
void func_02014184(void *d, s16 a, s16 b, int c, int e, int f);
int func_020142A4(int x);
void func_02184504(void);
void func_02184CEC(void *obj, void *p);

void *func_02185458(void *p, int u, int b, s16 a, const int *s, u16 x)
{
    void *r0v = func_020122C0(p, 0, func_02184504, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC(r4, p);
    x = func_020142A4(x);
    func_02014184(r4 + 0x10, a, x, s[0], s[1], s[2]);
    *(int *)(r4 + 0x2c) = 0;
    *(u8 *)(r4 + 0x30) = b;
    return r0v;
}
