/*
 * function: func_021FA284
 * address: 0x021FA284
 * packet: pkt_ov186_021FA284
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   func_021FAD04 0x021FAD04 thumb ov186
 *   func_021FAF24 0x021FAF24 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FAFCC 0x021FAFCC thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FAFA0 0x021FAFA0 thumb ov186
 *   func_021FAA74 0x021FAA74 thumb ov186
 *   func_021FA758 0x021FA758 thumb ov186
 *   func_021FA444 0x021FA444 thumb ov186
 *   func_021FAB7C 0x021FAB7C thumb ov186
 *   func_021FAA34 0x021FAA34 thumb ov186
 */
typedef struct {int x,y;} Pair;
extern int func_02035D20(int *,int *);
extern int func_021FAD04(int *,int,int),func_021FAF24(char *,int);
extern void func_021FD15C(void *p, int a1);
extern void func_020061E4(int);
extern void func_021FD860(char *,unsigned,const Pair *);
extern void func_021FAFCC(char *,Pair *);
extern void func_021FD73C(int *p, int v);
extern int func_021FAFA0(void *,int);
extern void func_021FAA74(void *,int *,unsigned *);
extern void func_021FA758(void *,int *,unsigned char *);
extern void func_021FA444(void *,int *,unsigned char *);
extern void func_021FAB7C(void *,int *,unsigned char *);
extern void func_021FAA34(void *,int *,int *);
void func_021FA284(void *p,int *state,unsigned char *ctx)
{
 int found,i,x,y,kind;
 found=0;*(int *)(ctx+0x18)=0;*(int *)(ctx+0x14)=0;
 if(func_02035D20(&x,&y)){
  for(i=0;i<ctx[0x38];i++){
   if(func_021FAD04((int *)(*(char **)(ctx+0x40)+i*0x44),x,y)){
    if(func_021FAF24(*(char **)(ctx+0x40)+i*0x44,3)){
     if(*(unsigned *)(ctx+0x50)){
      func_021FD15C((void *)(*(unsigned *)(ctx+0x50)),*(unsigned *)(ctx+4));
      *(unsigned *)(ctx+0x50)=0;
     }
     func_020061E4(0x703);
     *(int *)(ctx+0x2c)=i;
     found=1;
     *(int *)(ctx+0x30)=x;*(int *)(ctx+0x34)=y;
     func_021FD860(*(char **)(ctx+0x58),7,(Pair *)(ctx+0x30));
     func_021FAFCC(*(char **)(ctx+0x40)+*(int *)(ctx+0x2c)*0x44,(Pair *)(ctx+0x30));
     *(int *)(ctx+0x54)=0;
    }else{
     kind=func_021FAF24(*(char **)(ctx+0x40)+i*0x44,5);
     func_021FAF24(*(char **)(ctx+0x40)+i*0x44,6);
     func_020061E4(0x704);
     if(kind==1){*(int *)(ctx+0x2c)=i;func_021FD73C(p,(int)func_021FAA74);}
    }
    break;
   }
  }
 }
 if(found){
  *(int *)(ctx+0x14)=1;
  *(int *)(ctx+0x1c)=func_021FAF24(*(char **)(ctx+0x40)+*(int *)(ctx+0x2c)*0x44,0);
  *(int *)(ctx+0x20)=func_021FAF24(*(char **)(ctx+0x40)+*(int *)(ctx+0x2c)*0x44,3);
  *(int *)(ctx+0x24)=func_021FAF24(*(char **)(ctx+0x40)+*(int *)(ctx+0x2c)*0x44,1);
  *(int *)(ctx+0x28)=func_021FAF24(*(char **)(ctx+0x40)+*(int *)(ctx+0x2c)*0x44,2);
  for(i=0;i<ctx[0x39];i++){
   if(i==*(int *)(ctx+0x2c))func_021FAFA0(*(char **)(ctx+0x40)+i*0x44,1);
   else func_021FAFA0(*(char **)(ctx+0x40)+i*0x44,3);
  }
  switch(*(unsigned *)(ctx+0x1c)){
  case 2:func_021FD73C(p,(int)func_021FA758);break;
  case 0:case 1:case 4:func_021FD73C(p,(int)func_021FA444);break;
  case 3:func_021FD73C(p,(int)func_021FAB7C);break;
  default:func_021FD73C(p,(int)func_021FAA34);break;
  }
 }
}
