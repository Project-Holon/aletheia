/*
 * function: UNION_EFF_DeleteIconGroupObjs
 * address: 0x0217FCE4
 * packet: pkt_ov019_0217FCE4
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_EFF_DeleteIconObj 0x0217FCA4 thumb ov019
 */

typedef unsigned int u32;
struct E { u32 a,b,c,d; unsigned short h; };
extern void UNION_EFF_DeleteIconObj(u32 *p);
void UNION_EFF_DeleteIconGroupObjs(struct E *p) { int i; for(i=0;i<10;i++) { struct E *e=&p[i]; if(e->d != 0) UNION_EFF_DeleteIconObj((u32 *)e); } }
