/*
 * function: func_021BAA9C
 * address: 0x021BAA9C
 * packet: pkt_ov100_021BAA9C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: larger predicate follower 0x021BAAEC is filed separately.
 * symbols:
 *   func_0204E804 0x0204E804 arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009A34 0x02009A34 thumb
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BAFA0 0x021BAFA0 thumb ov100
 *   func_021BAB08 0x021BAB08 thumb ov100
 */
#include "../include/Obj10216.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Sub020097BCObj;
extern int func_0204E804(void);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02009A34(struct Sub020097BCObj *obj);
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021BAFA0(int p);
extern void func_021BAB08(int p);
void func_021BAA9C(int a) {
 if(func_0204E804()!=0) {
  if(((struct Obj10216 *)a)->f24C==7) {
   if(func_02009A34((struct Sub020097BCObj *)func_0201283C((const struct BigObj *)(**(int * *)&((struct Obj10216 *)a)->f244)))==32) {
    func_021B95B8((u8 *)a,(u32)func_021BAFA0);
    ((struct Obj10216 *)a)->fCAC=180;
    return;
   }
  }
  func_021B95B8((u8 *)a,(u32)func_021BAB08);
 }
}
