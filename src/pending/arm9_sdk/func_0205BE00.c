/*
 * function: DWC_AC_GetApSpotInfo
 * address:  0x0205BE00
 * packet:   pkt_0205A2DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * symbols:
 *   s_ac_work  0x02146AC0  data  a4
 *
 * TwlDWC libdwcac dwc_ac.o.
 */
extern unsigned char DWCi_AC_GetPhase(void);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned long size);

typedef struct {
    unsigned char pad[12];
    unsigned char *fieldC;
} ACWORK;

static ACWORK s_ac_work;

int func_0205BE00(unsigned char *apSpotInfo)
{
    int result = 0;
    unsigned char phase = DWCi_AC_GetPhase();

    if (phase >= 10 && phase <= 16) {
        if (s_ac_work.fieldC[23] == 4 || s_ac_work.fieldC[23] == 8) {
            MI_CpuCopy8(s_ac_work.fieldC + 24, apSpotInfo, 10);
            result = 1;
        }
    }
    return result;
}
