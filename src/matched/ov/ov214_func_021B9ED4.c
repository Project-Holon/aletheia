/*
 * function: BTL_REC_SEL_StartEntryA
 * address: 0x021B9ED4
 * packet: pkt_ov214_021B9ED4
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_REC_SEL_SetEntryA 0x021B9EF0 thumb ov214
 */
extern void BTL_REC_SEL_SetEntryA(void *,char *,unsigned,unsigned,unsigned);
void BTL_REC_SEL_StartEntryA(unsigned *out,void *a,char *p,unsigned b,unsigned c,unsigned d){*out=2;BTL_REC_SEL_SetEntryA(a,p,b,c,d);}
