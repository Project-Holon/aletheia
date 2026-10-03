/*
 * function: func_021BD2C4
 * address: 0x021BD2C4
 * packet: pkt_ov209_021BD2C4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD890 0x021BD890 thumb ov209
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bits {u16 low:1;u16 high:15;};
extern void func_021BD890(char *,int,int);
int func_021BD2C4(char *p,int a,int b,int c) { func_021BD890(p,a,b);((struct Bits *)(p+0xc24))->high=(u16)a;*(int *)(p+24)=c;return 6; }
