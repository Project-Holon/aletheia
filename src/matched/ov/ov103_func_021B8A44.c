/*
 * function: func_021B8A44
 * address: 0x021B8A44
 * packet: pkt_ov103_021B8A44
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6480 0x021B6480 thumb ov101
 *   func_021B8358 0x021B8358 thumb ov103
 *   func_021B8138 0x021B8138 thumb ov103
 *   func_021B630C 0x021B630C thumb ov101
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int func_021B6480(int *);
extern void func_021B8358(u8 *);
extern void func_021B8138(u8 *p, void *q, int c, int x, s16 y);
extern int func_021B630C(int *,int);
void func_021B8A44(u8 *p,u16 *s) {
 switch(*s) {
 case 0:
  if(func_021B6480(*(int **)(*(u8 **)(p+0xb0c)+4))>0)*s=1;
  else if(func_021B6480(*(int **)(*(u8 **)(p+0xb0c)+4))<0) {(*(u8 **)(p+0xb0c))[16]=0;*(int *)(*(u8 **)(p+0xb0c)+12)=2;func_021B8358(p);}
  break;
 case 1:(*(u8 **)(p+0xb0c))[16]=0;*(int *)(*(u8 **)(p+0xb0c)+12)=2;*s=2;break;
 case 2:func_021B8138(p+0x184,p+0x174,6,0,0);*s=3;break;
 case 3:if(func_021B630C(*(int **)(*(u8 **)(p+0xb0c)+4),6))*s=4;break;
 case 4:func_021B8358(p);break;
 }
}
