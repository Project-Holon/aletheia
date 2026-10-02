/*
 * function: func_0216F144
 * address: 0x0216F144
 * packet: pkt_ov010_0216F144
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 */

typedef struct { int w[8]; } W;
extern void func_0203064C(int,int,int);
extern W *func_0203159C(void *,int,int);
extern void func_02082BCC(void *,int,int);
int func_0216F144(void *a,int b,int c) { W *w; func_0203064C(1,38,0x18000); w=func_0203159C(a,32,38); func_02082BCC(w,0,32); w->w[0]=38; w->w[6]=c; return 1; }
