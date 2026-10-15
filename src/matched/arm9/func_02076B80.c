/*
 * unit:     no
 * function: CARD_WaitBackupAsync
 * address:  0x02076B80
 * packet:   pkt_02076B80
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
void CARD_WaitBackupAsync(void){ CARDi_WaitAsync(); }
