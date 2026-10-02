/*
 * function: func_02186278
 * address: 0x02186278
 * packet: pkt_ov020_02186278
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02161ECC 0x02161ECC thumb ov010
 */
extern int func_02161ECC(char *);
int func_02186278(char *p,int which) { char *q; int i; int count; if (which==0) q=p+8; else q=p+0xf8; count=0; for(i=0;i<10;i++) if(func_02161ECC(q+i*0x18)) count++; return count; }
