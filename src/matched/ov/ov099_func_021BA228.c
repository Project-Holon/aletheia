/*
 * function: func_021BA228
 * address: 0x021BA228
 * packet: pkt_ov099_021BA228
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA418 0x021BA418 thumb ov099
 *   func_021BA2D0 0x021BA2D0 thumb ov099
 *   func_021BA5B4 0x021BA5B4 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BA418(void *,void *); extern int func_021BA2D0(void *,void *); extern void func_021BA5B4(void *,int,void *);
void func_021BA228(void *w,u8 *s) { *(void **)(s+16)=(void *)func_021BA418; *(void **)(s+24)=(void *)func_021BA2D0; *(u16 *)(s+12)=0; func_021BA5B4(w,0,s); }
