/*
 * function: func_021FC124
 * address: 0x021FC124
 * packet: pkt_ov186_021FC124
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef struct {unsigned a,b,c;} Triple;
int func_021FC124(char *p,unsigned i,Triple *out) { if(*(int *)((unsigned)(p+0xb0)+i*4)) *out=*(Triple *)((unsigned)p+i*12+8);return *(int *)((unsigned)(p+0xb0)+i*4); }
