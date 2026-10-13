/*
 * function: DWCi_Np_SetInitFlag
 * address:  0x0205A11C
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   cardi_param  0x02146AAC  data  a4
 *
 * TwlSDK libcard card_spi.o.
 * The pool word names the .bss base; the store is at +4 (cardi_param).
 */
typedef struct {
    int _r0;
    int len;
    int f2;
    int f3;
} CARDiParam;

static CARDiParam cardi_param;

void DWCi_Np_SetInitFlag(int len)
{
    cardi_param.len = len;
}
