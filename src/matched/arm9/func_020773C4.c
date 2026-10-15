/*
 * unit:     no
 * function: CARD_WaitRomAsync
 * address:  0x020773C4
 * packet:   pkt_020773C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CARDi_WaitAsync  0x02076050  arm
 */

extern void CARDi_WaitAsync(void);
void CARD_WaitRomAsync(void){ CARDi_WaitAsync(); }
