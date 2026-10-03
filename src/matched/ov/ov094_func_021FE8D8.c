/*
 * function: func_021FE8D8
 * address:  0x021FE8D8
 * packet:   pkt_ov094_021FE8D8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02006BD0  0x02006BD0  thumb
 *   func_021FE410  0x021FE410  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 */
typedef struct {
    unsigned int f0 : 10;
    unsigned int f10 : 1;
} Flags;
typedef struct {
    Flags fl;
    char pad04[0x268];
    int tbl[6];
} Obj;

typedef unsigned int   u32;
extern u32 func_02006BD0(u32 i);
extern void func_021FE410(Obj *o, int a, int b, int n);
extern void func_021F89BC(void *h);

void func_021FE8D8(void *h, Obj **pp)
{
    int i;

    for (i = 0; i < 6; i++) {
        if ((*pp)->tbl[i] != -1) {
            if (func_02006BD0((*pp)->tbl[i]) != 0)
                return;
            (*pp)->tbl[i] = -1;
        }
    }
    func_021FE410(*pp, 0x6b000, 0x7f000, 10);
    (*pp)->fl.f10 = 0;
    func_021F89BC(h);
}
