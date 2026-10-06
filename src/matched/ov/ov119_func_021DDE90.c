/*
 * function: func_021DDE90
 * address: 0x021DDE90
 * packet: pkt_ov119_021DDE90
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD080 0x021DD080 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDDF4 0x021DDDF4 thumb ov119
 */
#include "../include/Obj10360.h"

typedef unsigned int   u32;
struct MsgBank;
extern void func_021DD080(void *a, void *b, void *c);
struct Entry;
extern struct Entry *func_020399A8(void);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *);
extern void func_021E1030(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DDDF4(unsigned char *p);

void func_021DDE90(unsigned char *p)
{
    func_021DD080((void *)((unsigned)func_020399A8()),(void *)30,p); func_02045CAC((struct MsgBank *)(((struct Obj10360 *)p)->f720),0x88,(void *)(((struct Obj10360 *)p)->f738)); func_021E1024(p); func_021E1030((char *)p); p[0x11f1]=120; func_021D8E84(p,(int)func_021DDDF4);
}
