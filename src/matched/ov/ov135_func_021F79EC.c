/*
 * function: func_021F79EC
 * address: 0x021F79EC
 * packet: pkt_ov135_021F79EC
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
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020307B0(void *);
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
void func_021F79EC(char *p) { func_020307B0(*(void **)(*(char **)(p+0xe00)+20)); func_020307B0(*(void **)(*(char **)(p+0xe00)+24)); func_020307B0(*(void **)(p+0xe00)); func_02045808(*(void **)(p+0xb88)); }
