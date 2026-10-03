/*
 * function: func_021B86A0
 * address: 0x021B86A0
 * packet: pkt_ov104_021B86A0
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Repeated inline absolute-value expressions preserve each signed test.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
static inline int magnitude(int x) { return x<0 ? -x : x; }
int func_021B86A0(u8 *p) {
 int diff; int result; int sound; u16 n;
 n=*(u16 *)(p+0x78);
 if(n<2) { sound=0x64c; result=3; }
 else {
  diff=*(int *)(p+(n-1)*8+4)-*(int *)(p+(n-2)*8+4);
  if(magnitude(diff)>=0 && magnitude(diff)<50) {sound=0x64c;result=3;}
  else if(diff<0) {
   if(magnitude(diff)<200) {sound=0x64f;result=1;} else {sound=0x650;result=0;}
  } else {
   if(magnitude(diff)<200) {sound=0x64d;result=5;} else {sound=0x64e;result=6;}
  }
 }
 func_020061E4(sound); return result;
}
