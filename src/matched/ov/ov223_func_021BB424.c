/*
 * function: func_021BB424,func_021BB440
 * unit: yes
 * address: 0x021BB424
 * packet: pkt_ov223_021BB424
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02028218 0x02028218 thumb
 *   func_0202822C 0x0202822C thumb
 *   func_02028230 0x02028230 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;extern void func_02028218(struct Obj *,u32);extern void func_0202822C(char *,int);
void func_021BB424(char *p) {u32 off;off=0x260;func_02028218(*(struct Obj **)(p+off),1);func_0202822C(*(char **)(p+off),1);}
extern u32 func_02028230(u8 *);
u32 func_021BB440(char *p) {return func_02028230(*(u8 **)(p+0x260));}
