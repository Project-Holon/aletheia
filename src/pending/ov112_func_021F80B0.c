/*
 * function: func_021F80B0
 * address:  0x021F80B0
 * packet:   pkt_ov112_021F80B0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker:  scheduling, 4 bytes.  Original slots `movs r1,#0` between the
 *           first bl and the `ldr r0,[r4,#0x58]` that feeds func_021F5424;
 *           every spelling tried emits the load first, or the store before
 *           the load.  (After 0x021F53B4, set b->4c = 0, call func_021F5424
 *           with b->58 and 0.)
 * symbols:
 *   func_021F53B4  0x021F53B4  thumb  ov112
 *   func_021F5424  0x021F5424  thumb  ov112
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021F53B4(int);
extern void func_021F5424(int, int);

void func_021F80B0(int a, int b) {
    func_021F53B4(*(int *)(b + 0x58));
    *(int *)(b + 0x4c) = 0;
    func_021F5424(*(int *)(b + 0x58), 0);
}