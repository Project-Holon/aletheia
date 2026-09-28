/*
 * function: DWCi_AC_GetPhase
 * address:  0x0205C2C4
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   s_ac_work  0x02146AC0  data  a4
 *
 * TwlDWC libdwcac dwc_ac.o.
 * Same work object as DWCi_AC_GetError.
 */
typedef struct {
    unsigned char pad[12];
    unsigned char *fieldC;
} ACWORK;

static ACWORK s_ac_work;

unsigned char DWCi_AC_GetPhase(void)
{
    return s_ac_work.fieldC ? s_ac_work.fieldC[9] : 0;
}
