/*
 * function: func_021FFB14
 * address: 0x021FFB14
 * packet: pkt_ov186_021FFB14
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FFB68 0x021FFB68 thumb ov186
 *   d_02200D8C 0x02200D8C data a1
 */
extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned short);extern void func_02082BCC(void *,int,unsigned);extern void func_021FFB68(char *,int);extern const char d_02200D8C[];
char *func_021FFB14(void *p,int f,unsigned heap) {char *q=func_02030734(heap,16,0,d_02200D8C,0x44f);func_02082BCC(q,0,16);*(void **)(q+8)=p;func_021FFB68(q,f);return q;}
