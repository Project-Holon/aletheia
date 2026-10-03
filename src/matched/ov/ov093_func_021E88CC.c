/*
 * function: func_021E88CC
 * address:  0x021E88CC
 * packet:   pkt_ov093_021E88CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OS_GetConsoleType  0x02085CBC  arm
 *   sub_02034AC4  0x02034AC4  arm
 *   d_021F6380  0x021F6380  data
 *   ov140_id  0x0000008C  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 OS_GetConsoleType(void);
extern int sub_02034AC4(signed int handle);
extern u8 ov140_id[];
extern int d_021F6380;

void func_021E88CC(void)
{
    if (OS_GetConsoleType() & 0x02000000) {
        sub_02034AC4((int)ov140_id);
        d_021F6380 = 1;
    } else {
        d_021F6380 = 0;
    }
}
