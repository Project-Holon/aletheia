/*
 * unit:     no
 * function: MISC_SAVEDATA_GetStatusByte
 * address:  0x0200E44C
 * packet:   pkt_0200E3A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

int MISC_SAVEDATA_GetStatusByte(int p0, int p1){ return *(unsigned char *)(((p0 + p1) + ((0xa << 6) << 0))); }
