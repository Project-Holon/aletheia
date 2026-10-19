/*
 * function: PLACE_NAME_GetBank
 * address:  0x0202F688
 * packet:   pkt_0202F688
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (no entry in layout/function_starts.txt; the listing
 * shows the range as ARM). Compiled body is 80 bytes including its literal
 * pool. Witness for ov131 func_021D8784 (bl from 0x021D878C / 0x021D8794).
 * Maps an id range to a bank number (0x0202F688) and to an index inside
 * that bank (0x0202F6D8).
 */

unsigned int PLACE_NAME_GetBank(unsigned int n) {
  if(n<0x7531) return 89;
  if(n<0x9c41) { if(n-0x7531>=14) return 89; return 92; }
  if(n<0xea61) { if(n-0x9c41>=109) return 89; return 90; }
  if(n<=65535) return 91;
  return 89;
}
