/*
 * unit: yes
 * function: func_02174E64, func_02174E88
 * address: 0x02174E64
 * packet: pkt_ov012_02174E64
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller consumes 020399A8's live r0 despite its filed void return.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
#include "../include/Obj19292.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
u32 func_02174E64(void) { return func_0203D3F8((u32)func_020399A8(),0,0x1509,0,0,1,0,0); }
void func_02174E88(int unused0,int unused1,int unused2,u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19292 *)ctx)->f355C;
    if (p) p[0xdf] = 0;
}
