/*
 * function: func_021E170C
 * address: 0x021E170C
 * packet: pkt_ov137_021E170C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 30-byte body followed by two bytes of zero alignment padding.
 * lever: Initialize count before loading x; declare count before x.
 * Existing result-before-input and declaration-order idioms cover this.
 */

int func_021E170C(char *p) { int count; unsigned int x; count=0;x=*(unsigned short *)(*(char **)(p+0xdc)+66);while(x) { count+=x&1; x>>=1; }return count; }
