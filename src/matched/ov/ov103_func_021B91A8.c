/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_ClearStroke
 * address:  0x021B91A8
 * packet:   pkt_ov103_021B91A8
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void MI_CpuFill8(void *, int, int);
void IRC_COMPATIBLE_TOUCH_TEST_ClearStroke(void *p) { MI_CpuFill8(p, 0, 0x60); }
