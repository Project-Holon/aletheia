/*
 * function: func_021D5F98
 * address: 0x021D5F98
 * packet: pkt_ov120_021D5F98
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A600 0x0204A600 arm
 *   func_0202EA40 0x0202EA40 thumb
 *   func_021D75F4 0x021D75F4 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204A600(void);
struct Row;
extern void func_0202EA40(struct Row *p);
extern void func_021D75F4(u8 *);
void func_021D5F98(u8 *p){func_0204A600();if(*(void **)(p+0xf8))func_0202EA40(*(void **)(p+0xf8));if(*(void **)(p+0xfc))func_0202EA40(*(void **)(p+0xfc));func_021D75F4(p);}
