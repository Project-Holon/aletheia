/*
 * function: func_021CCA74
 * address: 0x021CCA74
 * packet: pkt_ov093_021CCA74
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8; typedef unsigned int u32;
typedef struct { unsigned low:10, size:9, high:13; } A;
typedef struct { unsigned low:13, size:10, high:9; } B;
void func_021CCA74(A *p,B *q) { unsigned a,b,t; a=p->size;b=q->size;if(b<=a) {t=(u32)q-((u32)p+4);t+=b;if(t==a) p->size=a-b;} }
