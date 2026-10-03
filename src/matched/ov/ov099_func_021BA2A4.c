/*
 * function: func_021BA2A4
 * address: 0x021BA2A4
 * packet: pkt_ov099_021BA2A4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BA578 0x021BA578 thumb ov099
 *   func_021BA36C 0x021BA36C thumb ov099
 *   func_021BA5B4 0x021BA5B4 thumb ov099
 *   func_021C57D8 0x021C57D8 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BA578(void *,void *); extern void func_021BA36C(void *,void *); extern void func_021BA5B4(void *,int,void *); extern void func_021C57D8(void *,int);
void func_021BA2A4(void *w,u8 *s) { *(void **)(s+16)=(void *)func_021BA578; *(void **)(s+24)=(void *)func_021BA36C; *(u16 *)(s+8)=28; *(u16 *)(s+12)=4; func_021BA5B4(w,4,s); func_021C57D8(*(void **)(s+4),0); }
