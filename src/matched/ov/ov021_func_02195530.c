/*
 * function: func_02195530
 * address:  0x02195530
 * packet:   pkt_ov021_02195530
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207F7A0  0x0207F7A0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   func_0207F7FC  0x0207F7FC  arm
 *   func_0207F9B4  0x0207F9B4  arm
 *   func_0207FA0C  0x0207FA0C  arm
 *   func_0207FA40  0x0207FA40  arm
 *   func_0207FADC  0x0207FADC  arm
 *   d_021DDA84     0x021DDA84  data  a4
 *   d_021DDAA4     0x021DDAA4  data  a4
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 d_021DDA84[];
extern u32 d_021DDAA4[];
extern void func_0207F7A0();
extern void DC_FlushRange(void *p, u32 size);
extern void func_0207F7FC(void *p, u32 off, u32 size);
extern void func_0207F9B4();
extern void func_0207FA0C();
extern void func_0207FA40(void *p, u32 off, u32 size);
extern void func_0207FADC();

void func_02195530(char *p)
{
    func_0207F7A0();
    DC_FlushRange(d_021DDA84, 0x20);
    func_0207F7FC(d_021DDA84, (u16)*(u32 *)(p + 0xCC8) << 3, 0x20);
    func_0207F9B4();
    func_0207FA0C();
    DC_FlushRange(d_021DDAA4, 0x20);
    func_0207FA40(d_021DDAA4, (u16)*(u32 *)(p + 0xCCC) << 3, 0x20);
    func_0207FADC();
}
