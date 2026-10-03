/*
 * function: func_021DCBCC
 * address: 0x021DCBCC
 * packet: pkt_ov137_021DCBCC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCE00 0x021DCE00 thumb ov137
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern int func_021DCE00(char *,int);
extern void func_02082D44(void *,int,u32);
void func_021DCBCC(int i,int unused,void *q,char *p) {*(s16 *)(p+70)=*(s16 *)(p+70)|(s16)(1<<i);func_02082D44(q,func_021DCE00(p,i),1428);}
