/*
 * function: func_021D76D8
 * address: 0x021D76D8
 * packet: pkt_ov125_021D76D8
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_02012E7C 0x02012E7C thumb
 *   func_020072A4 0x020072A4 thumb
 */
extern void *func_02012EBC(void *); extern int func_02012E7C(char *,int); extern void func_020072A4(void *,unsigned int);
int func_021D76D8(char *p,int id) {void *s=func_02012EBC(p); int r=func_02012E7C(p,id); if(r==2 || r==3) func_020072A4(s,id); return r;}
