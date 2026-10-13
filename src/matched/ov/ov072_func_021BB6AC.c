/*
 * function: TOWNMAP_GRH_GetTouchDrag
 * address: 0x021BB6AC
 * packet: pkt_ov072_021BB6AC
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned int u32;
typedef struct { u32 x,y,z; } Vec;
int TOWNMAP_GRH_GetTouchDrag(u32 *p,Vec *v,u32 *out) { if(p[7]!=0) { if(v!=0) *v=*(Vec *)(p+9); if(out!=0) *out=p[6]; return 1; } return 0; }
