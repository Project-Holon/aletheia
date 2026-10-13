/*
 * function: DWCi_PostProcessConnectionSYNFinishFullmesh
 * address:  0x021725EC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the byte at +0x62f of the module block.
 *
 * symbols:
 *   func_0217253C  0x0217253C  arm  ov009
 */

extern void func_0217253C(void);
extern int func_02175F3C(void);

void DWCi_PostProcessConnectionSYNFinishFullmesh(void)
{
    func_0217253C();

    *(unsigned char *)(func_02175F3C() + 0x62f) = 0;
}

