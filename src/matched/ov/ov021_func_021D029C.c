/*
 * function: func_021D029C
 * address:  0x021D029C
 * packet:   pkt_ov021_021D029C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477D4  0x020477D4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int pad[9];
    int a24[4];
    int a34[1];
} Tbl;

typedef struct {
    Tbl *tbl;
    int cnt;
} Src;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    Src src;
    int obj;
    int sub[4];
} Dst;

extern Src *func_021AC1AC(void *p);
extern int func_02047564(int a, int b, int c);
extern int func_0204767C(int a, int *b, int c);
extern void func_020477D4(int a, u16 b);

void func_021D029C(void *p, Dst *d)
{
    Src *s;
    Tbl *tbl;
    int cnt;
    int j;
    int i;

    s = func_021AC1AC(p);
    d->src = *s;
    tbl = d->src.tbl;
    cnt = d->src.cnt;
    for (i = 0; i < 4; i++)
        d->sub[i] = func_02047564(tbl->a34[cnt], tbl->a24[i], 0);
    d->f2 = 4;
    d->obj = func_0204767C(tbl->a34[cnt], d->sub, 4);
    for (j = 0; j < 4; j++)
        func_020477D4(d->obj, j);
}
