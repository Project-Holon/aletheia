/*
 * function: func_021BB9A4, func_021BB9DC
 * unit: yes
 * extent: copy helper followed by unlabelled return-one stub at 021BB9DC.
 * address: 0x021BB9A4
 * packet: pkt_ov223_021BB9A4
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082D44 0x02082D44 arm
 */
extern void func_02082D44(const void *,void *,unsigned);
void func_021BB9A4(unsigned char *p,int value){if(p[2161]!=value){*(unsigned *)(p+2156)=1;p[2160]=0;p[2161]=value;func_02082D44(p+1898,p+1642,256);}}
int func_021BB9DC(void){return 1;}
