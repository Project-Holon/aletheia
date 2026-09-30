/*
 * function: func_021DCB30
 * address: 0x021DCB30
 * packet: pkt_ov119_021DCB30
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DC854 0x021DC854 thumb ov119
 *   func_021DC894 0x021DC894 thumb ov119
 */
extern char *func_021DC854(void *,int);extern void func_021DC894(void *,int,void *,void *,int);
void func_021DCB30(void *a,int b,char *c) {const char *q=*(char **)(c+0x18);char *p=func_021DC854(a,0xc6000);if(q) {if(*(int *)(q+0x1b0)==2) {int i;for(i=0;i<2;i++) {const int *s=(const int *)(q+i*8);char *d=p+i*4;*(int *)(d+0x1048)=s[2];*(int *)(d+0x1050)=s[1];}} else {int j;for(j=0;j<2;j++){char *d=p+j*4;*(int *)(d+0x1048)=-1;*(int *)(d+0x1050)=-1;}}}func_021DC894(a,b,c,p,3);}
