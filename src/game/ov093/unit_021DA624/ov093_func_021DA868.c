/*
 * function: func_021DA868
 * address:  0x021DA868
 * packet:   pkt_ov093_021DA868
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021D7B08   0x021D7B08  thumb ov093
 *   func_021D76BC   0x021D76BC  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int func_021D775C(int a);
extern int func_021D7B08(int a, int b);
extern int func_021D76BC(int key, u32 val);

void func_021DA868(int a, int b, int c)
{
    int t;

    if (c != func_021D775C(2))
        return;
    if (func_021D775C(0x1d) != 4)
        return;
    t = func_021D775C(0x32);
    func_021D76BC(0x32, func_021D7B08(t / 2, 1));
}
