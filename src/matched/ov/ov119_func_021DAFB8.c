/*
 * function: func_021DAFB8
 * address: 0x021DAFB8
 * packet: pkt_ov119_021DAFB8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAF68 0x021DAF68 thumb ov119
 *   func_021D9434 0x021D9434 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 */
#include "../include/Obj00001.h"
#include "../include/Obj22732.h"
typedef unsigned short u16;
typedef unsigned char u8;
extern int func_021D8A24(void *);
extern void func_021D8E84(void *,int),func_021DAF68(void *),func_021D9434(void *);
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
struct MsgBank;
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
struct Link;
extern void func_02039C68(struct Link *,unsigned,unsigned);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *),func_021E1030(void *);
void func_021DAFB8(char *p) {
 u8 b;
 if(func_021D8A24(p)) {
  b=4;
  if(func_0203D3A8(func_020399A8(),0xc00,1,(u32)(&b))) {
   func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),136,(void *)(*(int *)&((struct Obj00001 *)p)->f738));func_021E1024(p);func_021E1030(p);
   func_02039C68((struct Link *)func_020399A8(),26,8);func_021D8E84(p,(int)func_021DAF68);
  }
 } else {((struct Obj22732 *)(*(char * *)&((struct Obj00001 *)p)->f8))->f8=3;func_021D8E84(p,(int)func_021D9434);}
}
