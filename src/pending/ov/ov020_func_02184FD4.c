/*
 * function: func_02184FD4
 * address:  0x02184FD4
 * packet:   pkt_ov020_02184FD4
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
 *   func_02014204  0x02014204  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AA0  0x02012AA0  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_0201289C  0x0201289C  thumb
 *   func_02184AB4  0x02184AB4  thumb  ov020
 *   func_02184CEC  0x02184CEC  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short s16;

typedef struct { int w[7]; } V28;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
void func_02014184(void *d, int a, int b, int c, int e, int f);
void func_02014204(void *p, int id);
int func_020127A4(void *p);
int *func_02012AA0(void);
int func_02012AC8(int);
int func_02012AE4(int);
void func_0201289C(void *, V28 *);
void func_02184AB4(void);
void func_02184CEC(void *obj, void *p);

void *func_02184FD4(void *p, int id)
{
    V28 v;
    void *r0v = func_020122C0(p, 0, func_02184AB4, 0x9c);
    char *r5 = func_020124E8(r0v);
    int r6, r7;
    int *r4;

    func_02184CEC(r5, p);
    func_02014204(r5 + 0x10, id);
    *(int *)(r5 + 0x2c) = 0;
    *(u16 *)(r5 + 0x18) = 1;
    r6 = func_020127A4(*(void **)(r5 + 4));
    r4 = func_02012AA0();
    r7 = func_02012AC8(r6);
    func_02014184(&v, r7, (s16)func_02012AE4(r6), r4[0], r4[1], r4[2]);
    func_0201289C(*(void **)(r5 + 4), &v);
    return r0v;
}
