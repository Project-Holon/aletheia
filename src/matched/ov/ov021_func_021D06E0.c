/*
 * function: func_021D06E0
 * address:  0x021D06E0
 * packet:   pkt_ov021_021D06E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_02046F50  0x02046F50  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 */

typedef struct S {
    int f0;
    int a[3];
    int f10;
    int b[2];
    int f1c;
} S;

typedef unsigned int   u32;
struct Rec;
struct Tagged;
extern void func_02047738(struct Rec *p);
extern void func_0204762C(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern u32 func_02046F50(struct Tagged *p, u32 sel);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);

void func_021D06E0(S *p)
{
    int i;

    func_02047738((struct Rec *)p->f1c);
    for (i = 0; i < 2; i++) {
        func_0204762C((struct Rec *)p->b[i]);
    }
    func_02047504((struct Rec *)p->f10);
    for (i = 0; i < 3; i++) {
        if (func_02046F50((struct Tagged *)p->a[i], 2)) {
            func_020470D0((u32 *)p->a[i]);
        }
        func_02046EFC((struct Tagged *)p->a[i]);
    }
}
