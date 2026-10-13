/*
 * function: SCRCMD_POKEMON_FLD_CheckGiftItemCanReceive
 * address: 0x021B6FEC
 * packet: pkt_ov021_021B6FEC
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/unit_021B6DC0.c and filed here.
 */

int SCRCMD_POKEMON_FLD_CheckGiftItemCanReceive(void);

/*
 * `ldr ip,[pc,#4]; ldr r0,[pc,#4]; bx ip; .word 0x02061B5C; .word 0x02146B80`,
 * no witness outside this range.  Leaf C tried (DIFF only, the two loads and
 * the two pool words come out swapped, 8 bytes):
 *   extern void NNSi_GfdResetVramTransferTaskQueue(void *); extern char d_02146B80[];
 *   void NNS_GfdResetVramTransferTaskQueue(void) { NNSi_GfdResetVramTransferTaskQueue(d_02146B80); }
 *   (`return NNSi_GfdResetVramTransferTaskQueue((int)d_02146B80)` with int types: same DIFF)
 */
int SCRCMD_POKEMON_FLD_CheckGiftItemCanReceive(void) { return 1; }
