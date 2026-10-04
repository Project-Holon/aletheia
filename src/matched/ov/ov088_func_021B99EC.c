/*
 * function: func_021B99EC
 * address:  0x021B99EC
 * packet:   pkt_ov088_021B99EC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02031140  0x02031140  arm
 *   func_02046788  0x02046788  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 */

typedef unsigned int   u32;
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
struct Node;
struct S02031140;
extern void func_02030EAC(struct Node *n);
extern void func_02031140(struct S02031140 *p);
extern void func_02046788(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);

void func_021B99EC(int *p)
{
    func_0204363C(1);
    func_0204361C();
    func_02030EAC((struct Node *)p[1]);
    func_02031140((struct S02031140 *)p[0]);
    func_02046788();
    func_020450C8();
    func_0203F9B4();
}
