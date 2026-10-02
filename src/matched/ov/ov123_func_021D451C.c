/*
 * function: func_021D451C
 * address: 0x021D451C
 * packet: pkt_ov123_021D451C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: follower 021D45F0 already filed separately.
 * symbols:
 *   func_0204BA10 0x0204BA10 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020452E8 0x020452E8 arm
 *   func_02085D3C 0x02085D3C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021D4EF0 0x021D4EF0 thumb ov123
 *   func_021D4D40 0x021D4D40 thumb ov123
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D4FAC 0x021D4FAC thumb ov123
 *   func_021D4AFC 0x021D4AFC thumb ov123
 *   func_021D44F4 0x021D44F4 thumb ov123
 *   func_021D4FB8 0x021D4FB8 thumb ov123
 *   func_021D4440 0x021D4440 thumb ov123
 */
typedef unsigned int u32;
extern void func_0204BA10(void *);
extern void func_0204B92C(void *, int);
extern void func_020452E8(void *);
extern int func_02085D3C(void);
extern void func_02045CAC(void *, int, void *);
extern void func_021D4EF0(char *, int, int);
extern void func_021D4D40(char *, int);
extern void func_021D4244(char *, void *, int);
extern void func_021D4FAC(char *);
extern void func_021D4AFC(void);
extern void func_021D44F4(void);
extern void func_021D4FB8(void);
extern void func_021D4440(void);
void func_021D451C(char *p)
{
    func_0204BA10(*(void **)(p + *(u32 *)(p + 0x270) * 4 + 0x2a0));
    func_0204B92C(*(void **)(p + *(u32 *)(p + 0x270) * 4 + 0x2a0), 0);
    if (*(int *)(p + 8) == 3) {
        if (*(void **)(p + 0x224)) {
            func_020452E8(*(void **)(p + 0x224));
            *(void **)(p + 0x224) = 0;
        }
        if (func_02085D3C()) {
            func_02045CAC(*(void **)(p + 0x28), 0x20, *(void **)(p + 0x38));
            func_021D4EF0(p, 10, 0);
            func_021D4D40(p, 1);
            func_021D4244(p, func_021D4AFC, 0x1df);
        } else {
            func_02045CAC(*(void **)(p + 0x24), 7, *(void **)(p + 0x38));
            func_021D4FAC(p);
            func_021D4D40(p, 1);
            func_021D4244(p, func_021D44F4, 0x1e6);
        }
    } else if (*(int *)(p + 8) == 2 || *(int *)(p + 8) == 3) {
        func_021D4244(p, func_021D4FB8, 0x1f2);
    } else {
        func_021D4244(p, func_021D4440, 0x1f5);
    }
}
