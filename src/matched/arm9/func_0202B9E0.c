/*
 * unit:     no
 * function: ISS_3DS_SYS_SetTableIndex
 * address:  0x0202B9E0
 * packet:   pkt_0202B9E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int ISS_3DS_SYS_SetTableIndex(int a0, int a1){ if ((unsigned int)(*(unsigned char *)(((char *)(a0) + ((int)(0x269) << 0)))) != (unsigned int)(a1)) { *(unsigned char *)(((char *)(a0) + ((int)(0x269) << 0))) = (unsigned char)a1; } else {  return a0; } }
