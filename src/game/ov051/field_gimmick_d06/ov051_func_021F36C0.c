/*
 * function: func_021F36C0
 * address: 0x021F36C0
 * packet: pkt_ov051_021F36C0
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F3DB4 0x021F3DB4 data a4
 */

typedef struct { int id; int n; int *ptr; } Entry;
extern const Entry d_021F3DB4[];
const Entry *func_021F36C0(int id) { unsigned int i; const Entry *p=d_021F3DB4; for(i=0;i<3;i++,p++) if(p->id==id) return p; return d_021F3DB4; }
