/*
 * function: func_021DC538
 * address: 0x021DC538
 * packet: pkt_ov119_021DC538
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020173EC 0x020173EC thumb
 *   func_02030734 0x02030734 arm
 *   func_0201293C 0x0201293C thumb
 *   func_02012944 0x02012944 thumb
 *   func_02012934 0x02012934 thumb
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_02039338 0x02039338 arm
 *   func_02012950 0x02012950 thumb
 *   d_021E80B0 0x021E80B0 data a4
 */
typedef unsigned short u16;extern unsigned func_020173EC(void);extern int func_02030734(int,unsigned,int,void *,int);extern char d_021E80B0[];extern int func_0201293C(void *);extern int func_02012944(void *);extern int func_02012934(void *);extern int func_021D8A24(void *);extern int func_02039338(void);extern int func_02012950(void *,int);
void func_021DC538(char *p,void *q) {unsigned i;for(i=0;i<3;i++)*(int *)(p+0x1064+i*4)=func_02030734(0x91,func_020173EC(),1,d_021E80B0,0xfde);if(q){*(void **)(p+0x82c)=q;*(int *)(p+0x828)=func_0201293C(q);*(int *)(p+0x830)=func_02012944(q);*(int *)(p+0x838)=func_02012934(q);if(*(int *)(p+0x834)==0){if(func_021D8A24(p)){*(int *)(p+0x834)=func_02012950(q,1-func_02039338());return;}*(int *)(p+0x834)=func_02012950(q,1);}}}
