/*
 * function: func_021F89F0
 * address: 0x021F89F0
 * packet: pkt_ov135_021F89F0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02203C1C 0x02203C1C data a4
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int (*const d_02203C1C[])(void *);
int func_021F89F0(u8 *p) { int state,r;state=*(int *)(p+40);r=d_02203C1C[state](p);if(state!=*(int *)(p+40)){*(u16 *)(p+0xf88)=0;*(u16 *)(p+0xf8a)=0;}return r; }
