/*
 * function: func_021C9F6C
 * address: 0x021C9F6C
 * packet: pkt_ov128_021C9F6C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C9F30 0x021C9F30 thumb ov128
 *   func_021C9F8C 0x021C9F8C thumb ov128
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void func_021C9F30(char *p, u32 index);
extern void func_021C9F8C(void *,char *);
void func_021C9F6C(char *p,void *q) { int i; for(i=0;i<8;i++)func_021C9F30(p,i);func_021C9F8C(q,p); }
