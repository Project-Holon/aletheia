/*
 * function: func_021F7048
 * address: 0x021F7048
 * packet: pkt_ov112_021F7048
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding before 021F7098.
 * symbols:
 *   func_02047738 0x02047738 arm
 *   func_0204762C 0x0204762C arm
 *   func_02047504 0x02047504 arm
 *   func_02046EFC 0x02046EFC arm
 *   func_020470D0 0x020470D0 arm
 */
typedef unsigned char u8;
typedef struct { int pad[7]; int single; int a[3]; int b; int c[3]; int d; } Cleanup;
extern void func_02047738(int);
extern void func_0204762C(int);
extern void func_02047504(int);
extern void func_02046EFC(int);
extern void func_020470D0(int);
void func_021F7048(Cleanup *p) {
    u8 i;
    func_02047738(p->d);
    for (i = 0; i < 3; i++) func_0204762C(p->c[i]);
    func_02047504(p->b);
    for (i = 0; i < 3; i++) func_02046EFC(p->a[i]);
    func_020470D0(p->single);
    func_02046EFC(p->single);
    p->single = 0;
}
