/*
 * function: DWC_AC_GetApType
 * address:  0x0205BDD0
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
 * File-local .bss work object; fieldC is ACHOLD*, type at offset 0x17.
 */
extern unsigned char DWCi_AC_GetPhase(void);

typedef struct {
    unsigned char pad[12];
    unsigned char *fieldC;
} ACWORK;

static ACWORK s_ac_work;

unsigned char func_0205BDD0(void)
{
    unsigned char type = 0xff;
    unsigned char phase = DWCi_AC_GetPhase();

    if (phase >= 10 && phase <= 16) {
        type = s_ac_work.fieldC[23];
    }
    return type;
}
