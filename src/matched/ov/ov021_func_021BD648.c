/*
 * function: func_021BD648
 * address:  0x021BD648
 * packet:   pkt_ov021_021BD648
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_021D9BB0     0x021D9BB0  data  ov021  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 */

typedef struct {
    void *f[6];
} Tbl;

typedef struct {
    int f00;
    void *f04;
    char pad08[8];
    unsigned int f10;
} Arg;

typedef struct {
    int f00;
    int f04;
    Arg *f08;
} Work;

extern Tbl d_021D9BB0;
extern void *func_020122C0(void *a, int b, void *cb, int size);
extern Work *func_020124E8(void *task);

void *func_021BD648(Arg *p)
{
    Tbl t = d_021D9BB0;
    int i;
    void *task;
    Work *w;

    switch (p->f10) {
    case 0:
        i = 0;
        break;
    case 1:
        i = 0;
        break;
    case 2:
        i = 2;
        break;
    case 3:
        i = 1;
        break;
    case 4:
        i = 2;
        break;
    case 5:
        i = 3;
        break;
    case 6:
        i = 5;
        break;
    default:
        i = 4;
        break;
    }
    task = func_020122C0(p->f04, p->f00, t.f[i], 12);
    w = func_020124E8(task);
    w->f04 = 0;
    w->f08 = p;
    return task;
}
