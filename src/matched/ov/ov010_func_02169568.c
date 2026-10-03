/*
 * function: func_02169568
 * address: 0x02169568
 * packet: pkt_ov010_02169568
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02046C9C 0x02046C9C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec;
extern void func_02046C9C(struct Rec *rec, u32 mode, u32 value);
void func_02169568(char *p) { func_02046C9C(*(void **)(p + 0x88), 2, 0); }
