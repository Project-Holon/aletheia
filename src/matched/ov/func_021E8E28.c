/*
 * function: func_021E8E28
 * address:  0x021E8E28
 * packet:   pkt_021E8E28
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8F08   0x021E8F08  thumb ov093
 *   func_021E8E38   0x021E8E38  thumb ov093
 *   func_021E8E28   0x021E8E28  thumb ov093
 *
 * wrapper over func_021E8F08, func_021E8E38
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_021E8F08(void);
extern void func_021E8E38(void *p);

void func_021E8E28(void *p)
{
    func_021E8F08();
    func_021E8E38(p);
}
