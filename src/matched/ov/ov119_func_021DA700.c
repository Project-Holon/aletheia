/*
 * function: func_021DA700
 * address: 0x021DA700
 * packet: pkt_ov119_021DA700
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D4B88 0x021D4B88 thumb ov117
 *   func_021D6F2C 0x021D6F2C thumb ov118
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned char u8;
extern int func_021D8A24(void *),func_021D8AA8(void *);
extern void func_021D8E84(void *,int);
extern void func_021D4B88(u8 *p);
extern void func_021D6F2C(u8 *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
void func_021DA700(char *p) {
 u8 b=((struct Obj00001 *)p)->f10A0;
 if(func_021D8A24(p)) {if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc03,1,(u32)(&b))==0) return;}
 *(unsigned *)0x04001000 &= 0xffff1fff;
 if(func_021D8AA8(p)==0) func_021D8E84(p,(int)func_021D4B88);
 else func_021D8E84(p,(int)func_021D6F2C);
}
