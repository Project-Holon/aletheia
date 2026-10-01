/*
 * function: func_021BB504
 * address:  0x021BB504
 * packet:   pkt_ov021_021BB504
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    int pad0;
    void *a4[4];
    void *a14[4];
    void *a24[4];
} Obj;

extern void func_02047738(void *a);
extern void func_02047504(void *a);
extern void func_02046EFC(void *a);

void func_021BB504(Obj *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        func_02047738(p->a24[i]);
        func_02047504(p->a14[i]);
        func_02046EFC(p->a4[i]);
    }
}
