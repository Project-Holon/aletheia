/*
 * function: NHTTPi_GetStaticResource
 * address:  0x021BEA20
 * packet:   pkt_ov114_021BEA20
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_GetStaticResource (libnhttp.TWL.HYB.a(d_nhttp_common.o))
 *
 * symbols:
 *   NHTTPi_InitMutex 0x021B9B4C arm ov114
 *   gNHTTPModuleGlobals 0x021CF984 data
 *   gNHTTPStaticResource 0x021CF98C data
 */

typedef struct {
    int unique;
    int mutex[6];
    int f1c;
    int f20;
} Res;

extern int gNHTTPModuleGlobals[];
extern Res gNHTTPStaticResource;

extern void NHTTPi_InitMutex(int *mutex_p);

Res *NHTTPi_GetStaticResource(void)
{
    Res *r = &gNHTTPStaticResource;
    if (gNHTTPModuleGlobals[2] == 0) {
        NHTTPi_InitMutex(&r->mutex[0]);
        r->f20 = 0;
        r->f1c = 0;
        r->unique = 1;
    }
    return r;
}
