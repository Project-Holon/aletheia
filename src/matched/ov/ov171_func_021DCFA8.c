/*
 * function: func_021DCFA8
 * address: 0x021DCFA8
 * packet: pkt_ov171_021DCFA8
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_020221A4 0x020221A4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0201C6B4(void*);
extern u32 func_020221A4(void);
int func_021DCFA8(u8*p){if(func_0201C6B4(*(void**)(p+0xb6c))==1 && func_020221A4()==1)return *(int*)(p+0xc74);return 2;}
