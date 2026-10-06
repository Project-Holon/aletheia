/*
 * function: func_021C6E74
 * address: 0x021C6E74
 * packet: pkt_ov128_021C6E74
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_02027974(void *);
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(struct TaskMenu *m);
int func_021C6E74(u8 *p) {int n;func_02027974(p);if(func_020279E8((struct TaskMenu *)p)==1) {n=func_02027A04(p);func_02027858((struct TaskMenu *)p);return n;}return -1;}
