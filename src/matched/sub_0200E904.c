/*
 * function: sub_0200E904
 * address:  0x0200E904
 * packet:   pkt_0200E684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8   0x02082BCC  arm
 *   func_02087C6C 0x02087C6C  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200E904.c \
 *       --func sub_0200E904 --addr 0x0200E904 --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern void func_02087C6C(void *obj);

void sub_0200E904(void *obj)
{
    MI_CpuFill8(obj, 0, 0x5a);
    func_02087C6C(obj);
}
