/*
 * function: func_021B9B3C
 * address: 0x021B9B3C
 * packet: pkt_ov071_021B9B3C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 */

extern void func_0202570C(void *);
extern void func_020437AC(void *);
void func_021B9B3C(char *p) { int i; for (i = 0; i < 7; i++) { func_0202570C(*(void **)(p + i * 4 + 0x2a0)); func_020437AC(*(void **)(p + i * 4 + 0x2bc)); } }
