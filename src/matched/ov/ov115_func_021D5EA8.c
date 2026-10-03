/*
 * function: func_021D5EA8
 * address: 0x021D5EA8
 * packet: pkt_ov115_021D5EA8
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027A04 0x02027A04 thumb
 *   func_02034714 0x02034714 arm
 *   d_021D663C 0x021D663C data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern const char d_021D663C[];
extern u8 func_02027A04(const u8 *);
extern void func_02034714(const char *expr, u32 line, const char *file);
u8 func_021D5EA8(u8 *p) { switch(*(int *)p) { case 0: return func_02027A04(*(const u8 **)(p+32)); case 1: return (u8)*(u32 *)(p+40); default: func_02034714(d_021D663C,0,d_021D663C); return 0; } }
