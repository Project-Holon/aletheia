/*
 * function: func_021D797C
 * address: 0x021D797C
 * packet: pkt_ov131_021D797C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02015EA0 0x02015EA0 thumb
 *   func_02015BA4 0x02015BA4 thumb
 */
extern void func_02015EA0(void *);
extern void func_02015BA4(void *,void *);
void func_021D797C(unsigned char *p,void **q) {
 func_02015EA0(q[0]);
 func_02015EA0(q[1]);
 func_02015BA4(*(void **)(p+0x78),q[0]);
 func_02015BA4(*(void **)(p+0x78),q[1]);
 q[0]=0;
 q[1]=0;
}
