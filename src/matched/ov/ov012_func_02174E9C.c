/*
 * unit: yes
 * function: func_02174E9C, func_02174EC4
 * address: 0x02174E9C
 * packet: pkt_ov012_02174E9C
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
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
u32 func_02174E9C(int v) { return func_0203D3F8((u32)func_020399A8(),(u8)v,0x150a,0,0,1,0,0); }
void func_02174EC4(int unused0,int unused1,int unused2,u8 *ctx)
{
    u8 *p = *(u8 **)(ctx+0x355c);
    if (p) p[0xcb] = 1;
}
