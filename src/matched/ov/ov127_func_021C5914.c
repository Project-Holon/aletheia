/*
 * function: func_021C5914
 * address: 0x021C5914
 * packet: pkt_ov127_021C5914
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C4ADC 0x021C4ADC thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { short x,y; } Pos;
extern Pos func_021C4ADC(char *);
void func_021C5914(char *p,short *x,short *y) { Pos a=func_021C4ADC(*(char **)p); *x=a.x; *y=a.y; }
