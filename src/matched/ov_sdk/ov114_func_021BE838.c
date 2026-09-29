/*
 * function: func_021BE838
 * address:  0x021BE838
 * packet:   pkt_ov114_021BE838
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_GetHeaderAll (libnhttp.TWL.HYB.a(d_nhttp.o))
 *
 * symbols:
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BEF58 0x021BEF58 arm ov114
 *   func_021BEC2C 0x021BEC2C arm ov114
 *   func_021BBDFC 0x021BBDFC arm ov114
 */

extern void *func_021BEF08(void);
extern void *func_021BEF3C(void);
extern void *func_021BEF58(void *sysInfo_p);
extern void *func_021BEC2C(void *mutexInfo_p, void *handle_p);
extern int func_021BBDFC(void *bgnEndInfo_p, void *res_p, char **value_pp);

int func_021BE838(void *handle, char **value_pp)
{
    void *sysInfo_p = func_021BEF08();
    void *bgnEndInfo_p = func_021BEF3C();
    void *mutexInfo_p = func_021BEF58(sysInfo_p);
    void *res_p = func_021BEC2C(mutexInfo_p, handle);
    if (res_p == 0) {
        return -1;
    }
    return func_021BBDFC(bgnEndInfo_p, res_p, value_pp);
}
