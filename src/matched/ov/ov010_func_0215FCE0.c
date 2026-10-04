/*
 * function: func_0215FCE0
 * address: 0x0215FCE0
 * packet: pkt_ov010_0215FCE0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0215FC40 0x0215FC40 thumb ov010
 *   func_020124E8 0x020124E8 thumb
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_02013CE0 0x02013CE0 thumb
 */

typedef unsigned int u32;
extern int func_0215FC40(int,int,unsigned short);
struct Obj;
extern void *func_020124E8(struct Obj *p);
typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 func_02188C9C(u8 *p);
extern u32 func_02013CE0(u32);
int func_0215FCE0(int a, int b, unsigned short c) { int task; u32 *p; task=func_0215FC40(a,b,c); p=func_020124E8((struct Obj *)task); p[6]=func_02013CE0(func_02188C9C((void *)b)) == 1 ? 5 : 2; return task; }
