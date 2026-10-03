/*
 * function: func_021DEB40
 * address: 0x021DEB40
 * packet: pkt_ov137_021DEB40
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   func_021E170C 0x021E170C thumb ov137
 */
typedef unsigned short u16;
extern int func_021DCBC4(void *,int,void *,int);
extern int func_021E170C(char *);
int func_021DEB40(char *p) {*(int *)(p+48)=func_021E170C(p)+1;if(func_021DCBC4(*(void **)(p+220),0x280A,p+48,4)==1){*(int *)(p+20)=0;*(int *)p=6;}return 0;}
