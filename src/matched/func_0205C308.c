/*
 * function: DWCi_AC_GetError
 * address:  0x0205C308
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
 * File-local .bss work object; pool word is its base.
 */
typedef struct {
    unsigned char pad[12];
    void *fieldC;
} ACWORK;

static ACWORK s_ac_work;

int DWCi_AC_GetError(void)
{
    return *(int *)((char *)s_ac_work.fieldC + 12);
}
