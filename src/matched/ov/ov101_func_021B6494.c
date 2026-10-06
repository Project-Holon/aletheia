/*
 * function: func_021B6494
 * address: 0x021B6494
 * packet: pkt_ov101_021B6494
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two zero alignment bytes. Extern b/c widened because
 *       caller forwards full words without callee's u16 truncation pairs.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
#include "../include/Obj22091.h"
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
int func_021B6494(u32 p,u32 a,u32 b,u32 c) {
    if(((struct Obj22091 *)p)->f78!=0) return 1;
    return func_0203D3A8((struct Entry *)func_020399A8(),a,b,c);
}
