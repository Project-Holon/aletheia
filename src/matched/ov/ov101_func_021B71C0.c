/*
 * function: func_021B71C0
 * address: 0x021B71C0
 * packet: pkt_ov101_021B71C0
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02028148 0x02028148 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021B73E8 0x021B73E8 thumb ov101
 *   func_021B7384 0x021B7384 thumb ov101
 */
struct TaskMenuState; extern void func_02028148(unsigned char *); extern void func_02027FD8(struct TaskMenuState *); extern void func_020307B0(void *); extern void func_021B73E8(void *); extern void func_021B7384(unsigned);
void func_021B71C0(void *p) { func_02028148(*(unsigned char **)p); func_021B73E8(p); func_02027FD8(*(struct TaskMenuState **)((char *)p+4)); func_021B7384((unsigned)p); func_020307B0(p); }
