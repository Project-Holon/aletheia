/*
 * function: func_021F2F68
 * address: 0x021F2F68
 * packet: pkt_ov194_021F2F68
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
int func_021F2F68(const int *p,int *out) {
 if(p[1]<5) {if(out) {out[1]=p[1];out[0]=p[0];}return 1;}
 if(p[0]<=5)return p[0]+2;
 return 0;
}
