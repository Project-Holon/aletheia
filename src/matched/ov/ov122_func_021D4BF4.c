/*
 * function: func_021D4BF4
 * address: 0x021D4BF4
 * packet: pkt_ov122_021D4BF4
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: unit pkt_ov122_021D4B74 attests callbacks 0x021D4BDC and 0x021D4BF0.
 * symbols:
 *   func_0204B92C 0x0204B92C arm
 *   func_0204BA00 0x0204BA00 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_021D4BDC 0x021D4BDC thumb ov122
 *   func_021D4BF0 0x021D4BF0 thumb ov122
 *   func_021D4244 0x021D4244 thumb ov122
 */
typedef unsigned short u16;
typedef struct { u16 f00; char *f04; void (*f08)(void); } Params;
extern void func_0204B92C(void *, int);
extern void func_0204BA00(void *, Params *);
extern void func_0204B9A0(void *);
extern void func_021D4BDC(void);
extern void func_021D4BF0(void);
extern void func_021D4244(char *, void *, int);
void func_021D4BF4(char *p)
{
    int i;
    Params args;
    void **base;
    i = *(int *)(p + 0x35c);
    args.f00 = 0;
    args.f04 = p;
    args.f08 = func_021D4BDC;
    if (i == 3) i = 0;
    else if (i == 4) i = 1;
    base = (void **)(p + 0x390);
    func_0204B92C(base[i], 1);
    func_0204BA00(base[i], &args);
    func_0204B9A0(base[i]);
    func_021D4244(p, func_021D4BF0, 0x390);
}
