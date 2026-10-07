/*
 * file:     c_gear_p03.c
 * unit:     yes
 * function: func_021F0B7C, func_021F0B88, func_021F0C00, func_021F0C68, func_021F0C70, func_021F0CA0, func_021F0CB8
 * address:  0x021F0B7C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _s32_div_f     0x0209C0A4  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021F0D14  0x021F0D14  thumb  ov029
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   d_021F323C     0x021F323C  data  a1
 *   func_021F2BB8 0x021F2BB8 thumb ov029
 *   d_021F32B3 0x021F32B3 data a1
 */
struct S021F0B7C {
    unsigned short f0 : 1;
};

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    u16 on  : 1;
    u16 cnt : 15;
    u16 f2;
    u8  f4;
    u8  f5;
    u8  f6;
    u8  f7;
} Ent;

typedef struct { unsigned short f0, f2, f4, f6; unsigned char f8, f9; } Record;

typedef enum { Zero } ZeroValue;

extern void func_021F0D14(int a, int b, int *x, int *y);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(unsigned int index);
extern int func_021F2BB8(u8 *p, int row, int col);
void func_021F0B7C(struct S021F0B7C *p);
void func_021F0B88(Ent *p);
void func_021F0C00(Ent *p, int idx);
int func_021F0C68(unsigned short *p);
int func_021F0C70(void *p, int i, int j, int k);
void func_021F0CA0(Record *p, unsigned short a, unsigned char b, unsigned char c);
void func_021F0CB8(unsigned char *p);
extern const u8 d_021F323C[];
extern const unsigned char d_021F32B3[][9];


void func_021F0B7C(struct S021F0B7C *p)
{
    p->f0 = 0;
}


void func_021F0B88(Ent *p)
{
    unsigned int q;
    int t;

    if (p->on) {
        p->cnt = p->cnt + 1;
        q = p->cnt / p->f2;
        t = 0;
        if (q >= 5) {
            q = 4 - q % 5;
            if (q == p->f5)
                p->on = 0;
        }
        if (q < 5) {
            if (p->cnt % p->f2 == 0)
                t = 1;
        }
        if (t)
            func_021F0C00(p, q);
    }
}


void func_021F0C00(Ent *p, int idx)
{
    int x, y, w;
    int pal;

    pal = (d_021F323C + p->f4 * 5)[idx];
    func_021F0D14(p->f6, p->f7, &x, &y);
    w = 4;
    if (x < 0) {
        w = x + 4;
        x = 0;
    } else if (x + 4 > 0x20) {
        w = 0x20 - x;
    }
    func_020413B0(4, x, y, w, 4, pal);
    func_020409B4(4);
}

int func_021F0C68(unsigned short *p)
{
    return (int)((unsigned)(*p << 31) >> 31);
}

int func_021F0C70(void *p, int i, int j, int k)
{
    if (func_021F2BB8(p, j, k)) return d_021F32B3[i][4];
    return d_021F32B3[i][j];
}

/*
 * lever: enum zero and f2,f4,f0,f6 logical store order recover the
 * original scheduling; the previous f2,f0,f4,f6 order differed at two stores.
 */
void func_021F0CA0(Record *p, unsigned short a, unsigned char b, unsigned char c)
{
    ZeroValue z;
    z = Zero;
    p->f2 = b;
    p->f4 = z;
    p->f0 = b * 2;
    p->f6 = a;
    p->f8 = c;
    p->f9 = 1;
}

void func_021F0CB8(unsigned char *p)
{
    int i;
    if (p[9]) {
        for (i = 0; i < 3; i++) {
            if (((unsigned short *)p)[i] < ((unsigned short *)p)[3])
                ((unsigned short *)p)[i]++;
        }
    }
}
