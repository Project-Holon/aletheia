/*
 * function: func_021BE748
 * address:  0x021BE748
 * packet:   pkt_ov114_021BE748
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_AddPostDataAscii (libnhttp.TWL.HYB.a(d_nhttp.o))
 *
 * symbols:
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BEF58 0x021BEF58 arm ov114
 *   func_021BEC10 0x021BEC10 arm ov114
 *   func_021BAC58 0x021BAC58 arm ov114
 */

typedef unsigned char  u8;
extern u8 *func_021BEF08(void);
extern void *func_021BEF3C(void);
extern void *func_021BEF58(void *sysInfo_p);
extern void *func_021BEC10(void *mutexInfo_p, void *handle_p);
extern int func_021BAC58(void *req_p, void *bgnEndInfo_p, char *label_p, char *value_p);

int func_021BE748(void *handle, char *label_p, char *value_p)
{
    void *sysInfo_p = func_021BEF08();
    void *bgnEndInfo_p = func_021BEF3C();
    void *mutexInfo_p = func_021BEF58(sysInfo_p);
    void *req_p = func_021BEC10(mutexInfo_p, handle);
    return -(func_021BAC58(req_p, bgnEndInfo_p, label_p, value_p) == 0);
}
