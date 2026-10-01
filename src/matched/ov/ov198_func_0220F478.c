/*
 * function: func_0220F478
 * address: 0x0220F478
 * packet: pkt_ov198_0220F478
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02211944 0x02211944 thumb ov198
 *   func_02210420 0x02210420 thumb ov198
 *   func_020310C4 0x020310C4 arm
 *   func_0220F1A4 0x0220F1A4 thumb ov198
 *   func_0220B7AC 0x0220B7AC thumb ov198
 *   func_0220E22C 0x0220E22C thumb ov198
 *   d_0221221C 0x0221221C data a4
 */
typedef unsigned char u8;
extern int (*const d_0221221C[])(u8 *);
extern void func_02211944(u8 **);
extern int func_02210420(void *,u8 *);
extern void func_020310C4(void *);
extern void func_0220F1A4(u8 *);
extern void func_0220B7AC(u8 *);
extern void func_0220E22C(u8 *);
void func_0220F478(void *task,u8 *p)
{
    if (*(int *)(*(u8 **)p+0x34)==1) {
        func_02211944((u8 **)p);
        *(int *)(p+0x2178)=33;
    }
    if (*(int *)(p+0x2178)!=33)
        *(int *)(p+0x2178)=d_0221221C[*(int *)(p+0x2178)](p);
    if (*(int *)(p+0x2178)==33 && func_02210420(task,p)==1) return;
    func_020310C4(*(void **)(p+0x1d4));
    func_0220F1A4(p);
    func_0220B7AC(p);
    func_0220E22C(p);
}
