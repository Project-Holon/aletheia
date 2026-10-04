/*
 * function: func_021B8768
 * address: 0x021B8768
 * packet: pkt_ov104_021B8768
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 021B87F2 before 021B87F4.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021B64B8 0x021B64B8 thumb ov101
 */
typedef unsigned char u8;
typedef struct {int words[33];} Block;
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
struct Link;
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_021B64B8(u32 p, u32 a, u32 b, u32 c, u8 d, u32 e, u32 f, u32 g);
int func_021B8768(u8 *p,const Block *q) {
 switch(*(int *)(p+4)) {
 case 0: *(Block *)(p+0x110)=*q; *(int *)(p+4)=1; break;
 case 1:
  if(func_021B64B8(*(int *)p,0xf00,0x84,(u32)(p+0x110),(u8)(func_0203D1A4((struct Link *)((int)func_020399A8()))==0),0,0,1)) *(int *)(p+4)=2;
  break;
 case 2:
  if(*(int *)(p+0x194)) { *(int *)(p+0x194)=0; *(int *)(p+4)=0; return 1; }
  break;
 }
 return 0;
}
