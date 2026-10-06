/*
 * function: func_021BB90C
 * address:  0x021BB90C
 * packet:   pkt_ov021_021BB90C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BBA1C  0x021BBA1C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */

typedef struct {
    char b[0x18];
} E18;

typedef struct {
    int f0;
    int f4;
    int n;
    E18 *arr;
    void *f10;
    void *f14;
} Obj;

extern void func_021BBA1C(int *p);
extern void func_020307B0(void *p);

void func_021BB90C(Obj *p)
{
    int i;

    for (i = 0; i < p->n; i++) {
        func_021BBA1C((int *)(&p->arr[i]));
    }
    func_020307B0(p->arr);
    func_020307B0(p->f10);
    func_020307B0(p->f14);
    func_020307B0(p);
}
