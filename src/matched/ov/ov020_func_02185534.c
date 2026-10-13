/*
 * function: func_02185534
 * address:  0x02185534
 * packet:   pkt_ov020_02185534
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked (evidence class: none, unresolved callee site) by unlabelled arm9 leaf
 * 0x02014184 (the integrator's), verified EXACT in a scratch file with `one --region arm9 --thumb`:
 *   typedef short s16;
 *   typedef struct { int f0; s16 h4, h6, h8, ha; int fc, f10, f14, f18; } Obj;
 *   void func_02014184(Obj *o, s16 a, s16 b, int c, int d, int e)
 *   { o->f0 = 1; o->h4 = a; o->h6 = -1; o->h8 = b; o->ha = 0; o->fc = 0;
 *     o->f10 = c; o->f14 = d; o->f18 = e; }
 * Lever: `const S3 *a3` (as in ov020 func_02184E40) and the callee's third
 * parameter declared short.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02184CEC  0x02184CEC  thumb  ov020
 *   func_02184584  0x02184584  thumb  ov020
 *   func_020142A4  0x020142A4  thumb
 *   func_02014184  0x02014184  thumb
 */

typedef unsigned short u16;

typedef struct { int a, b, c; } S3;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void func_02184CEC(void **o, void *p);
int func_02184584(int ctx, int *state, u8 *p);
u32 func_020142A4(u32 idx);
void func_02014184(void *d, int a, short b, int c, int e, int f);

void *func_02185534(void *p, int a1, int a2, const S3 *a3, short a4)
{
    void *r0v = func_020122C0(p, 0, func_02184584, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    *(u16 *)&a4 = func_020142A4(*(u16 *)&a4);
    func_02014184(r4 + 0x10, a2, a4, a3->a, a3->b, a3->c);
    *(int *)(r4 + 0x2c) = 0;
    return r0v;
}
