/*
 * function: func_021FC568, func_021FC598
 * address: 0x021FC568
 * packet: pkt_ov135_021FC568
 * region: ov135
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 */
struct U16Vec;
extern void func_02045808(struct U16Vec *);
void func_021FC568(char *p) {int i;for(i=0;i<10;i++) func_02045808(*(struct U16Vec **)((unsigned)p+i*4+0xb90));func_02045808(*(struct U16Vec **)(p+0xb88));func_02045808(*(struct U16Vec **)(p+0xb8c));}
int func_021FC598(char *p) {*(unsigned *)(p+40)=1;return 2;}
