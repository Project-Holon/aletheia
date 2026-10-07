/*
 * function: func_021F36F8
 * address: 0x021F36F8
 * packet: pkt_ov051_021F36F8
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F3DFC 0x021F3DFC data a4
 */

typedef struct { int id; int n; int *ptr; } Entry;
extern const Entry d_021F3DFC[];
const Entry *func_021F36F8(int id) { unsigned int i; const Entry *p=d_021F3DFC; for(i=0;i<3;i++,p++) if(p->id==id) return p; return d_021F3DFC; }
