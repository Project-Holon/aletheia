/*
 * file:     field_effect_p23.c
 * unit:     yes
 * function: func_021AAFA0, func_021AAFC0
 * address:  0x021AAFA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012A38  0x02012A38  thumb
 *   func_021AAFFC  0x021AAFFC  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_021ADAAC  0x021ADAAC  thumb
 */
struct BigObj;
typedef unsigned char u8;

typedef struct {
    u8 b[0x10];
} Sub;

typedef struct {
    u8 pad[0x10];
    Sub sub;
} T;

typedef struct {
    int pad[2];
    int f8;
} S;

typedef struct D_021AAFA0 D_021AAFA0;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct {
    u16 h0;
    u16 h2;
    u16 h4;
    u16 h6;
    int f8;
    u8 bc;
    u8 pad[3];
} R;

typedef struct {
    int f0;
    char pad[0x5b0];
    int f5b4;
} D_021AAFC0;

extern u32 func_02012A38(const struct BigObj *p);
extern void func_021AAFFC(D_021AAFA0 *d);
extern void func_02082BCC(void *p, int v, int n);
extern u8 func_021ADAAC(int a, u8 *b, int c, int d, int e, int f);
void func_021AAFA0(S *s, D_021AAFA0 *d);
void func_021AAFC0(int a, D_021AAFC0 *d, R *r);


void func_021AAFA0(S *s, D_021AAFA0 *d)
{
    T *t = (T *)func_02012A38((const struct BigObj *)s->f8);
    func_021AAFFC(d);
    func_02082BCC(&t->sub, 0, 0x10);
}


void func_021AAFC0(int a, D_021AAFC0 *d, R *r)
{
    if (d->f5b4 == 0) {
        d->f5b4 = func_021ADAAC(a, (u8 *)d->f0, r->h2, r->h6, r->f8, r->bc);
        if (d->f5b4 == 0) {
            func_02082BCC(r, 0, 0x10);
        }
    }
}
