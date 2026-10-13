/*
 * function: func_0200E098
 * address:  0x0200E098
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Zeroes 0x850 bytes then runs the initialiser.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E098.c \
 *       --func func_0200E098 --addr 0x0200E098 --thumb --cc 1.1p1
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuFill8(void *p, u32 v, u32 size);
extern void func_0200E024(void *obj);

void func_0200E098(u8 *p)
{
    MI_CpuFill8(p, 0, 0x850);
    func_0200E024(p);
}
