/*
 * function: func_021B9A18
 * address: 0x021B9A18
 * packet: pkt_ov071_021B9A18
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020437AC 0x020437AC arm
 */

typedef unsigned char u8;
extern void func_020437AC(void *);
void func_021B9A18(char *p) { int i; for (i = 0; i < *(u8 *)(p + 0x27c); i++) func_020437AC(*(void **)(p + i * 4 + 0x24)); }
