/*
 * function: func_021D7A1C
 * address: 0x021D7A1C
 * packet: pkt_ov131_021D7A1C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_02015D94 0x02015D94 thumb
 */
typedef struct {int x,y,z;} Vec;
extern void func_0207C9D0(Vec *,Vec *,Vec *);
extern void func_02015D94(char *p, int *src);
void func_021D7A1C(void *p,void **q,Vec *v) {
 Vec r;
 func_0207C9D0(v,(Vec *)((char *)q+0x4c),&r);
 func_02015D94(q[0],(int *)(&r));
 func_02015D94(q[1],(int *)(&r));
}
