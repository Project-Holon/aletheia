/*
 * function: func_0220B5AC
 * address: 0x0220B5AC
 * packet: pkt_ov198_0220B5AC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: expand the inner-loop value use to pair[i]; the bounded permuter baseline was DIFF 7 and this mutation reached EXACT.
 * symbols:
 *   func_0220B4B0 0x0220B4B0 thumb ov198
 *   func_02082D44 0x02082D44 arm
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02210F04 0x02210F04 thumb ov198
 *   d_02211A74 0x02211A74 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u8 x,y,w,h;} Rect;
typedef struct {u8 low:7;u8 high:1;} Flags;
extern const Rect d_02211A74[];
extern void *func_0220B4B0(void *,u32,u32,int);
extern void func_02082D44(const void *,void *,u32);
extern int func_022110D4(u8 *,int);
extern u32 func_02210F04(u32,u32);
void func_0220B5AC(u8 *p,void *dst,u8 kind,u8 index,u8 which)
{
 void *src;
 int count,n;
 u32 w;
 u8 i,j;
 u16 pair[2];
 u8 *rec;
 src=func_0220B4B0(p,kind,index,which);
 w=((const u8 *)&d_02211A74[0].w)[kind*4];
 count=w*((const u8 *)&d_02211A74[0].h)[kind*4];
 func_02082D44(src,dst,count*2);
 switch(kind){
 case 0:case 1:case 2:case 3:case 4:case 5:
  n=func_022110D4(p,kind);
  rec=(u8 *)((u32)p+(u32)n*0x4c);
  if(*(u16 *)(rec+8)==0) break;
  if(((Flags *)(rec+0x1b))->high){
   pair[0]=*(u16 *)((u32)dst+(w*2+5)*2);
   pair[1]=*(u16 *)((u32)dst+(w*3+5)*2);
   for(i=0;i<2;i++){
    u16 value=pair[i];
    for(j=0;j<9;j++) (((u16 *)((u32)dst+(i+2)*w*2))+j)[6]=pair[i];
   }
   return;
  }else if(*(u16 *)(rec+0x14)==0){
   for(i=0;i<count;i++) *(u16 *)((u32)dst+i*2)=(*(u16 *)((u32)dst+i*2)&0xfff)|(((index&1)+7)<<12);
   return;
  }else if(func_02210F04((u32)p,n)==1){
   for(i=0;i<count;i++) *(u16 *)((u32)dst+i*2)=(*(u16 *)((u32)dst+i*2)&0xfff)|(((index&1)+5)<<12);
  }
  break;
 }
}
