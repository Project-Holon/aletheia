/*
 * function: func_021D503C
 * address: 0x021D503C
 * packet: pkt_ov122_021D503C
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: zero padding at 0x021D50B2; next function at 0x021D50B4.
 * symbols:
 *   func_02158630 0x02158630 thumb ov010
 *   func_0204B898 0x0204B898 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 */
extern void *func_02012138(void *);
extern int func_02158630(void *);
extern int func_0204B898(void *);
extern void func_0204B92C(void *, int);
extern void func_0204B878(void *, int);
void func_021D503C(char *p)
{
    switch (func_02158630(func_02012138(*(void **)(p + 0x354)))) {
    case 0:
    case 1:
        if (func_0204B898(*(void **)(p + 0x390)) == 20) {
            func_0204B92C(*(void **)(p + 0x390), 0);
            func_0204B878(*(void **)(p + 0x390), 12);
        }
        break;
    case 2:
    case 3:
        if (func_0204B898(*(void **)(p + 0x390)) == 12) {
            func_0204B92C(*(void **)(p + 0x390), 1);
            func_0204B878(*(void **)(p + 0x390), 20);
        }
        break;
    }
}
