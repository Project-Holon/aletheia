/*
 * function: func_021B93E4
 * address: 0x021B93E4
 * packet: pkt_ov106_021B93E4
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020257D0 0x020257D0 thumb
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern int func_0201C6C4(void *,void *); extern void func_020257D0(void *);
int func_021B93E4(u8 *p) { if(*(int *)(p+8) && !func_0201C6C4(*(void **)(p+32),*(void **)p)){func_020257D0(*(void **)(p+28));*(int *)(p+8)=0;} if(!*(int *)(p+8))return 1; return 0; }
