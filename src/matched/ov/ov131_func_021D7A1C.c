/*
 * function: P_STA_SUB_ApplyMcssOffset
 * address: 0x021D7A1C
 * packet: pkt_ov131_021D7A1C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   VEC_Add 0x0207C9D0 arm
 *   MCSS_SetShadowOffset 0x02015D94 thumb
 */
typedef struct {int x,y,z;} Vec;
extern void VEC_Add(Vec *,Vec *,Vec *);
extern void MCSS_SetShadowOffset(char *p, int *src);
void P_STA_SUB_ApplyMcssOffset(void *p,void **q,Vec *v) {
 Vec r;
 VEC_Add(v,(Vec *)((char *)q+0x4c),&r);
 MCSS_SetShadowOffset(q[0],(int *)(&r));
 MCSS_SetShadowOffset(q[1],(int *)(&r));
}
