/*
 * unit: yes
 * function: func_02174DF0, func_02174E08
 * address: 0x02174DF0
 * packet: pkt_ov012_02174DF0
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller consumes 020399A8's live r0 despite its filed void return.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
void func_02174DF0(u32 v) { func_0203D3A8(func_020399A8(),0x1507,4,v); }
void func_02174E08(int index,int unused1,int unused2,u8 *ctx)
{
    u8 *p = *(u8 **)(ctx+0x355c);
    if (p) (p+index)[0xd4] = 1;
}
