/*
 * function: func_022023D0
 * address: 0x022023D0
 * packet: pkt_ov094_022023D0
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02205F64 0x02205F64 thumb ov094
 *   func_02205E30 0x02205E30 thumb ov094
 *   func_02205F40 0x02205F40 thumb ov094
 *   func_02205AB8 0x02205AB8 thumb ov094
 *   func_02205D34 0x02205D34 thumb ov094
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_020452E8 0x020452E8 arm
 *   func_02024DCC 0x02024DCC thumb
 *   func_022025B4 0x022025B4 thumb ov094
 *   func_02030EAC 0x02030EAC arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned int u32;
extern void func_02205F64(char *);
extern void func_02205E30(char *);
extern void func_02205F40(char *);
extern void func_02205AB8(char *);
extern void func_02205D34(char *);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern void func_0204B1CC(int);
extern void func_020452E8(void *);
extern int func_02024DCC(void);
extern void func_022025B4(void);
extern void func_02030EAC(void *);
extern void func_02049238(u32);
#define DROP_ID(k, f) if (*(int *)(p + (k)) != -1) { f(*(int *)(p + (k))); *(int *)(p + (k)) = -1; }
#define DROP_ZERO_ID(k, f) if (*(int *)(p + (k)) != 0) { f(*(int *)(p + (k))); *(int *)(p + (k)) = 0; }
#define DROP_PTR(k, f) if (*(void **)(p + (k)) != 0) { f(*(void **)(p + (k))); *(void **)(p + (k)) = 0; }
void func_022023D0(char *p)
{
    int i;
    func_02205F64(p);
    func_02205E30(p);
    func_02205F40(p);
    func_02205AB8(p);
    func_02205D34(p);
    DROP_ID(0x104, func_0204A8D4);
    DROP_ID(0x108, func_0204ADA4);
    DROP_ID(0x10c, func_0204AFD8);
    DROP_ID(0x110, func_0204A8D4);
    DROP_ID(0x114, func_0204AFD8);
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x1e0) != -1) {
            func_0204A8D4(*(int *)(p + i * 4 + 0x1e0));
            *(int *)(p + i * 4 + 0x1e0) = -1;
        }
    }
    DROP_ID(0x1f4, func_0204AFD8);
    DROP_ID(0x1f0, func_0204ADA4);
    DROP_ZERO_ID(0x1f8, func_0204B1CC);
    DROP_ZERO_ID(0x118, func_0204B1CC);
    DROP_ZERO_ID(0x17c, func_0204B1CC);
    DROP_ZERO_ID(0x1c4, func_0204B1CC);
    DROP_ZERO_ID(0x20c, func_0204B1CC);
    DROP_ZERO_ID(0x218, func_0204B1CC);
    DROP_PTR(0x228, func_020452E8);
    DROP_PTR(0x230, func_020452E8);
    func_02024DCC();
    func_022025B4();
    DROP_PTR(0x238, func_02030EAC);
    DROP_ZERO_ID(0x48, func_02049238);
    *(int *)(p + 0x58) = 0;
}
