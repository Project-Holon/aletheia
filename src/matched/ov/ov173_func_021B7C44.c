/*
 * function: func_021B7C44
 * address: 0x021B7C44
 * packet: pkt_ov173_021B7C44
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02025CD0 0x02025CD0 thumb
 *   func_02026124 0x02026124 thumb
 *   func_021B7F64 0x021B7F64 thumb ov173
 *   d_021B83A8 0x021B83A8 data a4
 *   d_021B81DC 0x021B81DC data a4
 */
#include "../include/Obj00180.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Struct_02025CD0;struct Sound;
extern u8 d_021B81DC[];
extern const u8 d_021B83A8[];
extern struct Struct_02025CD0 *func_02025CD0(u32,u32,u32,u32,u8,u16);
extern void func_02026124(struct Sound *,u32);
extern void func_021B7F64(char *);
void func_021B7C44(u8 *p) {struct Struct_02025CD0 *q;q=func_02025CD0((u32)d_021B83A8,(u32)d_021B81DC,(u32)p,1,0,79);*(struct Struct_02025CD0 * *)&((struct Obj00180 *)p)->f1C8=q;func_02026124((struct Sound *)q,8);func_021B7F64((char *)p);}
