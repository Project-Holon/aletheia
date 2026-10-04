/*
 * function: func_021B974C
 * address: 0x021B974C
 * packet: pkt_ov100_021B974C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B570 0x0204B570 arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;
struct Point { s16 x,y; u16 z; u8 id,mode; };
extern int func_0204B294(int,int,int,int,struct Point *,u16,u16);
struct Obj;
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_0204B3DC(int,int);
extern void func_0204B570(int,int);
void func_021B974C(int a,int b,int c,int d,int e)
{
 struct Point p;
 if(*(int *)(a+0x2c8+d*4)==0) {
  p.x=b; p.y=c; p.z=e; p.id=d; p.mode=2;
  *(int *)(a+0x2c8+d*4)=func_0204B294(*(int *)(a+0x2b4),*(int *)(a+0x2bc),*(int *)(a+0x2b8),*(int *)(a+0x2c0),&p,0,*(u16 *)(a+0x278));
  func_0204B92C((struct Obj *)*(int *)(a+0x2c8+d*4),1);
  func_0204B3DC(*(int *)(a+0x2c8+d*4),1);
  func_0204B570(*(int *)(a+0x2c8+d*4),2);
 }
}
