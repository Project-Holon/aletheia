/*
 * file:     unit_02183B60_p09.c
 * unit:     yes
 * function: func_02185848, func_021858BC, func_02185934
 * address:  0x02185848
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207AF1C 0x0207AF1C thumb
 *   func_0207AF00 0x0207AF00 thumb
 *   func_0207AF38 0x0207AF38 thumb
 *   func_0207B388 0x0207B388 arm
 *   d_020A1B38 0x020A1B38 data a2
 */
#define W(o) (*(int *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
typedef unsigned short u16;

typedef struct {int words[9];} Matrix;

typedef unsigned char u8;

typedef unsigned int u32;

extern void func_0207AF1C(Matrix *,int,int),func_0207AF00(Matrix *,int,int),func_0207AF38(Matrix *,int,int);
extern void func_0207B388(const Matrix *,const Matrix *,Matrix *);
void func_02185848(Matrix *p,int *angles);
void func_021858BC(Matrix *p,int *angles);
int func_02185934(u8 *p, u32 a, u32 b);
extern short d_020A1B38[];

static inline int sine(u16 a) {return d_020A1B38[(a>>4)*2];}

static inline int cosine(u16 a) {return d_020A1B38[(a>>4)*2+1];}

void func_02185848(Matrix *p,int *angles)
{
    Matrix temp;
    func_0207AF1C(p,sine(angles[1]),cosine(angles[1]));
    func_0207AF00(&temp,sine(angles[0]),cosine(angles[0]));
    func_0207B388(p,&temp,p);
    func_0207AF38(&temp,sine(angles[2]),cosine(angles[2]));
    func_0207B388(p,&temp,p);
}

void func_021858BC(Matrix *p,int *angles)
{
    Matrix temp;
    func_0207AF1C(p,sine(angles[0]),cosine(angles[0]));
    func_0207AF00(&temp,sine(-angles[1]),cosine(-angles[1]));
    func_0207B388(p,&temp,p);
    func_0207AF38(&temp,cosine(angles[2]),sine(angles[2]));
    func_0207B388(p,&temp,p);
}


int func_02185934(u8 *p, u32 a, u32 b)
{
    int d0, d1;
    int res = 0;
    int x = (short)W(0xC2F4);
    int y = (short)W(0xC2F8);

    if ((a & 1) || (W(0xC320) & 1)) {
        if (H(0xC31C) == 1) {
            if (H(0xC30C) == 0)
                H(0xC30C) = 1;
            else
                H(0xC30C) = 0;
        }
        return 1;
    }
    if (H(0xC30C) == 0) {
        if (W(0xC330) != 0 || W(0xC334) != 0) {
            d0 = (u16)(0x55 * W(0xC330));
            d1 = (u16)(0x55 * W(0xC334));
        } else {
            d0 = 0x200;
            d1 = 0x200;
        }
    } else {
        if (W(0xC330) != 0 || W(0xC334) != 0) {
            d0 = (u16)(0xa * W(0xC330));
            d1 = (u16)(0xa * W(0xC334));
        } else {
            d0 = 0x20;
            d1 = 0x20;
        }
    }
    if ((b & 0x20) || (W(0xC320) & 0x20)) {
        if (H(0xC31C) == 1) {
            W(0xC2F8) += d0;
        } else if (y < -10208) {
            W(0xC2F8) += d0;
        }
        res = 1;
    }
    if ((b & 0x10) || (W(0xC320) & 0x10)) {
        if (H(0xC31C) == 1) {
            W(0xC2F8) -= d0;
        } else if (y > -13184) {
            W(0xC2F8) -= d0;
        }
        res = 1;
    }
    if ((b & 0x40) || (W(0xC320) & 0x40)) {
        if (H(0xC31C) == 1) {
            if (x + d1 < 0x3E00)
                W(0xC2F4) += d1;
            else
                W(0xC2F4) = 0x3E00;
        } else if (x < 0x2020) {
            W(0xC2F4) += d1;
        }
        res = 1;
    }
    if ((b & 0x80) || (W(0xC320) & 0x80)) {
        if (H(0xC31C) == 1) {
            if (x - d1 > -15872)
                W(0xC2F4) -= d1;
            else
                W(0xC2F4) = -15872;
        } else if (x > 0x1300) {
            W(0xC2F4) -= d1;
        }
        res = 1;
    }
    return res;
}
