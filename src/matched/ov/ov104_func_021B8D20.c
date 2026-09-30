/*
 * function: func_021B8D20
 * address: 0x021B8D20
 * packet: pkt_ov104_021B8D20
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 021B8DA2 before 021B8DA4.
 * lever: Declare delta before pos; multiply length by counter in that order.
 * symbols:
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_0207CEE4 0x0207CEE4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int x,y,z;} Vec;
extern void func_0207CA00(Vec *,Vec *,Vec *);
extern int func_0207CBD0(Vec *);
extern void func_0207CCA4(Vec *,Vec *);
extern void func_0207CEE4(int,Vec *,Vec *,Vec *);
extern void func_0204B3DC(void *,u32);
extern void func_0204B404(void *,u16 *,u16);
void func_021B8D20(u8 *p) {
 u16 xy[2]; Vec delta; Vec pos; int length;
 if(*(int *)(p+8)) {
  func_0207CA00((Vec *)(p+0x18),(Vec *)(p+0xc),&delta);
  length=func_0207CBD0(&delta); func_0207CCA4(&delta,&delta);
  func_0207CEE4((u32)(length * *(u32 *)(p+0x24))/ *(u32 *)(p+0x28),&delta,(Vec *)(p+0xc),&pos);
  xy[0]=pos.x>>12; xy[1]=pos.y>>12;
  if((*(u32 *)(p+0x24))++ > *(u32 *)(p+0x28)) {
   xy[0]=*(int *)(p+0x18); xy[1]=*(int *)(p+0x1c);
   func_0204B3DC(*(void **)p,0); *(int *)(p+8)=0;
  }
  func_0204B404(*(void **)p,xy,*(u32 *)(p+4));
 }
}
