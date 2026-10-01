/*
 * unit: yes
 * function: func_021D4B74, func_021D4BDC, func_021D4BF0
 * address: 0x021D4B74
 * packet: pkt_ov122_021D4B74
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: unlabelled ov014 Thumb setter 0x02178118 is filed separately.
 * extent: unit includes tail-call stub 0x021D4BDC and return stub 0x021D4BF0;
 *   two zero padding bytes at 0x021D4BF2 follow the intended code.
 * symbols:
 *   func_021D4B74  0x021D4B74  thumb  ov122
 *   func_02178118 0x02178118 thumb ov014
 *   func_021D4B30 0x021D4B30 thumb ov122
 *   func_021D4244 0x021D4244 thumb ov122
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern void func_02178118(int, int);
extern void *func_02012138(void *);
extern int func_02026454(void *);
extern void func_02026400(void *);
extern void func_021D4244(char *, void *, int);
extern void func_021D4B30(void);
void func_021D4B74(char *p)
{
    *(int *)(p + 0x38c) = 1;
    func_0202208C(0, 0, 0, 0, 6, 1, *(u16 *)(p + 0xc));
    func_02178118(0, 0);
    if (*(int *)(p + 8) == 1 && func_02026454(func_02012138(*(void **)(p + 0x354))))
        func_02026400(func_02012138(*(void **)(p + 0x354)));
    func_021D4244(p, func_021D4B30, 0x35e);
}
void func_021D4BDC(char *p)
{
    func_021D4244(p, func_021D4B74, 0x36f);
}
void func_021D4BF0(void)
{
}
