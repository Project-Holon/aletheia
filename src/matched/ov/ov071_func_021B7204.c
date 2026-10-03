/*
 * function: func_021B7204
 * address: 0x021B7204
 * packet: pkt_ov071_021B7204
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 */
typedef unsigned char u8;
extern void func_02027974(void *);
typedef unsigned int   u32;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
int func_021B7204(int a, int b, void *p, int *q) { func_02027974(p); if(func_020279E8(p)==1) { *q=func_02027A04(p)==0 ? 1 : 0;return 1;} return 0; }
