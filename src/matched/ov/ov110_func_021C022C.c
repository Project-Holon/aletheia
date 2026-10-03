/*
 * unit: yes
 * function: func_021C022C, func_021C0250
 * address: 0x021C022C
 * packet: pkt_ov110_021C022C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0202DC98 0x0202DC98 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_0201C6B4(void *);
extern u32 func_0202DC98(void *);
int func_021C022C(u8 *p) { if(func_0201C6B4(*(void **)(p+0x5c)) && func_0202DC98(*(void **)(p+0x8c))) return 1; return 0; }
void func_021C0250(int *out,u8 *p,int value) { *out=value; *(int *)(p+0x9c)=0; }
