/*
 * function: func_021B9950
 * address: 0x021B9950
 * packet: pkt_ov100_021B9950
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow the return.
 * lever: pointer declared before counter; zero counter assigned before pointer base.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D378 0x0203D378 arm
 *   func_0203EFC8 0x0203EFC8 arm
 */
typedef unsigned char u8;
extern int func_020399A8(void);
extern unsigned func_0203D378(void);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
void func_021B9950(int a,int b,void *c,int d,int e)
{
 u8 *p;
 int i;
 if(e == func_020399A8()) {
  if(func_0203D378() != 0) {
   i=0;
   p = (u8 *)(d+0x260);
   for(;i<4;i++) {
    if(func_0203EFC8(p+i*6,c,6)==0) {
     *(u8 *)(*(int *)(d+0x244)+a+0x18)=i;
     return;
    }
   }
  }
 }
}
