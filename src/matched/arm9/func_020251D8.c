/*
 * unit:     no
 * function: INFOWIN_LoadCharacters
 * address:  0x020251D8
 * packet:   pkt_02024ABC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_LoadPltt  0x02040E78  arm
 */

int INFOWIN_LoadCharacters(int a0, const void *a1, int a2){ int t0 = BG_SYS_LoadPltt((int)*(unsigned char *)(((char *)(*(int *)((char *)(0x214693C))) + 6)), (int)a1, (int)((unsigned int)((a2 << 0x11)) >> 0x10), (int)((unsigned int)((((a0 + 0) + (*(unsigned char *)(((char *)(*(int *)((char *)(0x214693C))) + 7)) << 4)) << 0x11)) >> 0x10)); return t0; }
