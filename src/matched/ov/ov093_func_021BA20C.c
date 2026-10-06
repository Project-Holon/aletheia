/*
 * function: func_021BA20C
 * address: 0x021BA20C
 * packet: pkt_ov093_021BA20C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: switch preserves two equality tests; logical OR folds to a range check.
 * symbols:
 *   func_021B6818 0x021B6818 thumb ov093
 *   func_021BA1EC 0x021BA1EC thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 */
extern unsigned int func_021B6818(unsigned int *p);
typedef enum { FALSE = 0, TRUE = 1 } BOOL;
extern BOOL func_021BA1EC(char **);
extern void *func_021B86B8(void ***);
int func_021BA20C(char **p)
{
    int v;
    if (func_021B6818((unsigned int *)((int *)*p)) == 1) return func_021BA1EC(p);
    v = (int)func_021B86B8((void ***)p);
    switch (v) {
    case 0:
    case 1: return 1;
    default: return 0;
    }
}
