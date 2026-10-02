/*
 * unit: yes
 * function: func_021DCA68,func_021DCA8C
 * address: 0x021DCA68
 * packet: pkt_ov093_021DCA68
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F05C8 0x021F05C8 data a4
 *   func_021DA8A8 0x021DA8A8 thumb ov093
 *   func_021DA96C 0x021DA96C thumb ov093
 */
extern unsigned char d_021F05C8[];
extern int func_021DA8A8(int,int,int);
extern void func_021DA96C(void *,int,unsigned int,int);
void func_021DCA68(int a, void *b, int c) { if (func_021DA8A8((int)b,c,11)) func_021DA96C(b,c,1,1); }
void *func_021DCA8C(int *p) { *p = 1; return d_021F05C8; }
