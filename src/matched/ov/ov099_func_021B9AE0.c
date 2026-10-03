/*
 * function: func_021B9AE0
 * address: 0x021B9AE0
 * packet: pkt_ov099_021B9AE0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C57D8 0x021C57D8 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C57D8(void *,int);
void func_021B9AE0(void *w,u8 *s) { if (s) { if (*(u32 *)(s+20)) { *(u32 *)(s+16)=*(u32 *)(s+20); *(u32 *)(s+20)=0; *(u16 *)(s+12)=*(u16 *)(s+14); func_021C57D8(*(void **)(s+4),1); } } }
