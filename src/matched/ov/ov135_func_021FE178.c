/*
 * function: func_021FE178
 * address: 0x021FE178
 * packet: pkt_ov135_021FE178
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02045808 0x02045808 arm
 */
struct U16Vec;
extern void func_020307B0(void *);extern void func_02045808(struct U16Vec *);
void func_021FE178(char *p) {func_020307B0(*(void **)(*(char **)(p+0xe00)+20));func_020307B0(*(void **)(p+0xe00));func_02045808(*(struct U16Vec **)(p+0xb88));func_02045808(*(struct U16Vec **)(p+0xb8c));}
