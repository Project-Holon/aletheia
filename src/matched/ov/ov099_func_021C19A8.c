/*
 * function: func_021C19A8
 * address: 0x021C19A8
 * packet: pkt_ov099_021C19A8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C24A4 0x021C24A4 thumb ov099
 *   func_021C27E8 0x021C27E8 thumb ov099
 *   func_021C2864 0x021C2864 thumb ov099
 *   func_021BE6E4 0x021BE6E4 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C24A4(char *,int);
extern void func_021C27E8(void *,int);
extern void func_021C2864(void *,int);
extern void func_021BE6E4(char *);
extern void func_021C27E0(void *);
void func_021C19A8(char *p){func_021C24A4(p,127);func_021C27E8(*(void **)(p+8),*(u8 *)(*(u32 *)(p+0x248)+0x46));func_021C2864(*(void **)(p+8),*(u8 *)(*(u32 *)(p+0x248)+0x46));func_021BE6E4(p);func_021C27E0(*(void **)(p+8));}
