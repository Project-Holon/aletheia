/*
 * function: func_021F1744
 * address: 0x021F1744
 * packet: pkt_ov194_021F1744
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F4614 0x021F4614 thumb ov194
 *   func_021F4BD8 0x021F4BD8 thumb ov194
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021F436C 0x021F436C thumb ov194
 *   func_021F4628 0x021F4628 thumb ov194
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;
extern void func_021F4614(u8 *);
extern void func_021F4BD8(u8 *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021F436C(u8 *);
extern unsigned func_021F4628(unsigned char *p);
int func_021F1744(int a,int b,int c,u8 *p) { func_021F4614(p+0x2a0);func_021F4BD8(*(u8 **)p);func_0201C4E4((struct PrintSys *)(*(int *)(p+0x2b4)));func_021F436C(p+0x264);if(func_021F4628(p+0x2a0))return 1;return 0; }
