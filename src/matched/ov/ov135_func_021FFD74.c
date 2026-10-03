/*
 * function: func_021FFD74
 * address: 0x021FFD74
 * packet: pkt_ov135_021FFD74
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4EA0 0x021F4EA0 thumb ov135
 */
extern void func_021F4EA0(void *,int,int);
void func_021FFD74(char *p) {int i;for(i=0;i<8;i++) {unsigned a=(unsigned)p+i*4;void *v=*(void **)(a+0xd0c);if(v) func_021F4EA0(v,*(short *)(a+0xec4),*(short *)(a+0xec6)+32);}}
