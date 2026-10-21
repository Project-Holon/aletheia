/*
 * function: BTLV_INPUT_ButtonFlashTaskEnd
 * address:  0x02206710
 * packet:   pkt_ov094_02206710
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_GetOwnedWork  0x02030EE8  arm  arm9
 */

typedef struct { char pad[0x68]; unsigned int f68; } W;
extern W **TCBL_GetOwnedWork(void *h);

void BTLV_INPUT_ButtonFlashTaskEnd(void *h)
{
    (*TCBL_GetOwnedWork(h))->f68 &= 0x7fffffff;
}
