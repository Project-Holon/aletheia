/*
 * function: func_021BBBE4
 * address: 0x021BBBE4
 * packet: pkt_ov091_021BBBE4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 */
extern unsigned int func_020279E8(void *);
extern unsigned int func_02027A04(int);
unsigned int func_021BBBE4(int a,unsigned char *b) {if(func_020279E8(*(void **)(b+116))==0)return 23;return *(unsigned short *)((unsigned int)b+func_02027A04(*(int *)(b+116))*2+2);}
