/*
 * function: func_021F6CB0
 * address: 0x021F6CB0
 * packet: pkt_ov112_021F6CB0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F6CE0 0x021F6CE0 thumb ov112
 *   func_021F6D68 0x021F6D68 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F6CE0(char *,char *);
extern void func_021F6D68(char *);
void func_021F6CB0(char *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*32+8)) func_021F6CE0(p,p+8+i*32); if(*(int *)(p+4)) func_021F6D68(p); }
