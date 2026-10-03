/*
 * function: func_021DE884
 * address: 0x021DE884
 * packet: pkt_ov171_021DE884
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_02025588 0x02025588 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202570C(void *);
extern void func_020437AC(void *);
extern void func_02025588(void *);
void func_021DE884(char *p) { func_0202570C(*(void **)(p+0xc54)); func_020437AC(*(void **)(p+0xc58)); func_02025588(*(void **)(p+0xc50)); }
