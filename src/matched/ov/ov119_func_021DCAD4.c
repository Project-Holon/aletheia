/*
 * function: func_021DCAD4
 * address: 0x021DCAD4
 * packet: pkt_ov119_021DCAD4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DC854 0x021DC854 thumb ov119
 *   func_02039338 0x02039338 arm
 *   func_02012950 0x02012950 thumb
 *   func_021DC894 0x021DC894 thumb ov119
 */
extern char *func_021DC854(void *,int); extern int func_02039338(void); extern int func_02012950(int,int); extern void func_021DC894(void *,int,void *,void *,int);
void func_021DCAD4(void *a,int b,char *c) {char *p=func_021DC854(a,0xc6000);int i; for(i=0;i<2;i++) {char *d=p+i*4;*(int *)(d+0x1048)=0;*(int *)(d+0x1050)=1;} *(int *)(p+0x834)=func_02012950(*(int *)(c+0x14),1-func_02039338());func_021DC894(a,b,c,p,1);}
