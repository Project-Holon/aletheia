/*
 * function: func_0220B848
 * address: 0x0220B848
 * packet: pkt_ov198_0220B848
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 0220BB92..0220BB93 is two-byte alignment padding.
 * lever: the inline byte range guard adds 255 before its u8 narrowing.
 * symbols:
 *   func_02210B00 0x02210B00 thumb ov198
 *   func_0220B6D0 0x0220B6D0 thumb ov198
 *   func_0220BBF0 0x0220BBF0 thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220BBB4 0x0220BBB4 thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u8 low:7,high:1;} Bits;
extern int func_02210B00(u8 *p, int i);
extern void func_0220B6D0(u8 *,u8,u8,u8);
extern void func_0220BBF0(u8 *);
extern int func_022110D4(u8 *,int);
extern u8 func_0220BBB4(u8 *);
void func_0220B848(u8 *p,u32 mode)
{
 switch(mode){
 case 0:{
  u16 i;
  for(i=0;i<6;i++){
   int s=func_02210B00(p,i);
   if(s==0) func_0220B6D0(p,(u8)i,3,1);
   else if(s==1) func_0220B6D0(p,(u8)i,0,0);
   else if(s==2) func_0220B6D0(p,(u8)i,0,1);
  }
  if((u8)((*(u8 **)p)[0x1f]+255)<=1) func_0220BBF0(p);
  else func_0220B6D0(p,6,0,0);
  break;
 }
 case 8:{
  u16 i;
  for(i=0;i<6;i++){
   int s=func_02210B00(p,i);
   if(s==0) func_0220B6D0(p,(u8)i,3,1);
   else if(s==1) func_0220B6D0(p,(u8)i,0,0);
   else if(s==2) func_0220B6D0(p,(u8)i,0,1);
  }
  func_0220B6D0(p,6,0,0);
  break;
 }
 case 1:{
  func_0220B6D0(p,6,0,0);func_0220B6D0(p,7,0,0);
  if(((Bits *)((u32)p+(u32)func_022110D4(p,(*(u8 **)p)[0x20])*0x4c+0x1b))->high){
   func_0220B6D0(p,8,3,0);func_0220B6D0(p,10,3,0);
  }else{
   func_0220B6D0(p,8,0,0);func_0220B6D0(p,10,0,0);
  }
  break;
 }
 case 2:
  if(func_0220BBB4(p)==1){
   func_0220B6D0(p,12,0,0);func_0220B6D0(p,13,0,0);
  }else{
   func_0220B6D0(p,12,3,0);func_0220B6D0(p,13,3,0);
  }
  func_0220B6D0(p,11,0,0);func_0220B6D0(p,6,0,0);break;
 case 3:{
  u16 i;
  if(func_0220BBB4(p)==1){
   func_0220B6D0(p,12,0,0);func_0220B6D0(p,13,0,0);
  }else{
   func_0220B6D0(p,12,3,0);func_0220B6D0(p,13,3,0);
  }
  for(i=0;i<4;i++){
   if(*(u16 *)((u32)p+(u32)func_022110D4(p,(*(u8 **)p)[0x20])*0x4c+i*8+0x30)!=0) func_0220B6D0(p,(u8)(i+14),0,0);
   else func_0220B6D0(p,(u8)(i+14),3,0);
  }
  func_0220B6D0(p,9,0,0);func_0220B6D0(p,6,0,0);break;
 }
 case 4:{
  u16 i;
  func_0220B6D0(p,6,0,0);
  for(i=0;i<4;i++){
   if((*(u8 **)p)[0x4b]==i) func_0220B6D0(p,(u8)(i+28),2,0);
   else func_0220B6D0(p,(u8)(i+28),0,0);
  }
  break;
 }
 case 5:{
  u16 i;
  for(i=0;i<4;i++){
   if(*(u16 *)((u32)p+(u32)func_022110D4(p,(*(u8 **)p)[0x20])*0x4c+i*8+0x30)!=0) func_0220B6D0(p,(u8)(i+18),0,0);
   else func_0220B6D0(p,(u8)(i+18),3,0);
  }
  func_0220B6D0(p,6,0,0);break;
 }
 case 6:
  func_0220B6D0(p,22,0,0);func_0220B6D0(p,23,0,0);func_0220B6D0(p,24,0,0);func_0220B6D0(p,25,0,0);func_0220B6D0(p,26,0,0);func_0220B6D0(p,6,0,0);break;
 case 7:
  func_0220B6D0(p,27,0,0);func_0220B6D0(p,6,0,0);break;
 }
}
