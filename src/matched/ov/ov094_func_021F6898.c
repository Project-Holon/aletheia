/*
 * function: func_021F6898
 * address:  0x021F6898
 * packet:   pkt_ov094_021F6898
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204762C  0x0204762C  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 */
typedef struct {
    void *f0;           /* 0x00 */
    int n;              /* 0x04 */
    void *f8[2];        /* 0x08 */
    void **f10;         /* 0x10 */
    void **f14[2];      /* 0x14 */
    void *f1c[2];       /* 0x1c */
    void *f24[2];       /* 0x24 */
    char pad2c[0xa4 - 0x2c];
    void *fa4;          /* 0xa4 */
    void **fa8;         /* 0xa8 */
} Obj;

extern void func_0204762C(void *p);
extern void func_02046EFC(void *p);
extern void func_020307B0(void *p);
extern void func_02047738(void *p);
extern void func_02047504(void *p);

void func_021F6898(Obj *o)
{
    int i;
    int j;

    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            for (j = 0; j < 2; j++)
                func_0204762C(o->f14[j][i]);
            func_02046EFC(o->f10[i]);
        }
        for (j = 0; j < 2; j++) {
            func_020307B0(o->f14[j]);
            func_020307B0(o->f8[j]);
        }
        func_020307B0(o->f10);
    }
    for (j = 0; j < 2; j++) {
        func_02047738(o->f24[j]);
        func_02047504(o->f1c[j]);
    }
    func_02046EFC(o->f0);
    func_020307B0(*o->fa8);
    func_020307B0(o->fa8);
    func_020307B0(o->fa4);
    func_020307B0(o);
}
