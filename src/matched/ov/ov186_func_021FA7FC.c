/*
 * function: func_021FA7FC
 * address: 0x021FA7FC
 * packet: pkt_ov186_021FA7FC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FAD18 0x021FAD18 thumb ov186
 *   func_021FAD74 0x021FAD74 thumb ov186
 *   func_021FA21C 0x021FA21C thumb ov186
 *   func_021FAF24 0x021FAF24 thumb ov186
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FA6A8 0x021FA6A8 thumb ov186
 *   func_021FAA34 0x021FAA34 thumb ov186
 *   d_02200358 0x02200358 data a4
 */
extern const int d_02200358[];
extern void func_021FAD18(char *,int,const int *);
extern int func_021FAD74(char *),func_021FAF24(char *,int);
extern void func_021FA21C(unsigned char *,int);
extern void *func_021FD12C(void *,int,unsigned);
extern void func_021FD170(void *,void *,int);
extern void func_021FD73C(void *,void *);
extern void func_021FA6A8(void *,int *,unsigned char *);
extern void func_021FAA34(void *,int *,int *);
void func_021FA7FC(void *p,int *state,unsigned char *ctx)
{
 int i,ready,kind;
 unsigned short value;
 char *entry;
 switch(*state){
 case 0:
  for(i=0;i<ctx[0x3b];i++){
   if(i==ctx[0x3b]-1)func_021FAD18(*(char **)(ctx+0x3c)+i*0x44,2,d_02200358);
   else func_021FAD18(*(char **)(ctx+0x3c)+i*0x44,4,d_02200358+(ctx[0x3b]-i-1)*2);
  }
  *state=1;break;
 case 1:
  ready=1;
  for(i=0;i<ctx[0x3b];i++)ready&=func_021FAD74(*(char **)(ctx+0x3c)+i*0x44);
  if(ready){func_021FA21C(ctx,0);*state=2;}break;
 case 2:
  entry=*(char **)(ctx+0x3c)+(ctx[0x3b]-1)*0x44;
  kind=func_021FAF24(entry,0);
  value=func_021FAF24(entry,2);
  if(kind==1){
   if(!*(void **)(ctx+0x50))*(void **)(ctx+0x50)=func_021FD12C(*(void **)(ctx+4),*(int *)(ctx+0x4c),*(unsigned short *)ctx);
   func_021FD170(*(void **)(ctx+0x50),*(void **)(ctx+4),value);
  }
  *state=3;break;
 case 3:
  switch(*(unsigned *)(ctx+0x1c)){
  case 0:case 1:func_021FD73C(p,func_021FA6A8);break;
  default:func_021FD73C(p,func_021FAA34);break;
  }
  break;
 }
}
