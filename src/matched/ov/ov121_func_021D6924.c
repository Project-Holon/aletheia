/*
 * function: func_021D6924
 * address: 0x021D6924
 * packet: pkt_ov121_021D6924
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021D694C 0x021D694C thumb ov121
 *   func_02040588 0x02040588 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,int);
extern void func_021D694C(u16 *,int);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_021D6924(u16 *p,u16 heap)
{
    MI_CpuFill8(p,0,2);
    *p=heap;
    func_021D694C(p,0);
    func_02040588(6,1);
}
