/*
 * function: EVENT_ID_GetIndex
 * address:  0x0202F6D8
 * packet:   pkt_0202F6D8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (no entry in layout/function_starts.txt; the listing
 * shows the range as ARM). Compiled body is 84 bytes including its literal
 * pool. Witness for ov131 func_021D8784 (bl from 0x021D878C / 0x021D8794).
 * Maps an id range to a bank number (0x0202F688) and to an index inside
 * that bank (0x0202F6D8).
 */

unsigned int EVENT_ID_GetIndex(unsigned int n) {
  if(n<0x7531) { if(n>=117) return 2; }
  else if(n<0x9c41) { n-=0x7531; if(n>=14) return 2; }
  else if(n<0xea61) { n-=0x9c41; if(n>=109) return 2; }
  else { if(n<=65535) { n-=0xea61; if(n>=3) return 0; } else return 2; }
  return n;
}
