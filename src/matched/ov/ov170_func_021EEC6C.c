/*
 * function: func_021EEC6C
 * address: 0x021EEC6C
 * packet: pkt_ov170_021EEC6C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE008 0x021EE008 thumb ov170
 *   func_021EEF74 0x021EEF74 thumb ov170
 *   func_021DC9B4 0x021DC9B4 thumb ov170
 *   func_021E066C 0x021E066C thumb ov170
 */
extern void func_021EE008(char *, int, int);
extern void func_021EEF74(char *, int, int);
extern void func_021DC9B4(char *, void *);
extern void func_021E066C(void);
#define WORK(p) (*(char **)((p)+0x2c))
void func_021EEC6C(char *p, int k, int v)
{
    if (k >= 1 && k <= 4) func_021EE008(p, k-1, 1);
    else func_021EE008(p, 0, 0);
    func_021EEF74(WORK(p), k, v);
    func_021DC9B4(WORK(p), func_021E066C);
    *(int *)(WORK(p)+0xa168) = k;
}
