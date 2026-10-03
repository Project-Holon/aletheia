/*
 * function: func_0217AECC
 * address: 0x0217AECC
 * packet: pkt_ov176_0217AECC
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217AF14 0x0217AF14 thumb ov176
 *   func_0217AFBC 0x0217AFBC thumb ov176
 *   func_021E8A80 0x021E8A80 thumb ov177
 *   func_021E8A90 0x021E8A90 thumb ov177
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {void (*fn)(void *);} CB;
extern void func_0217AF14(int *),func_0217AFBC(int *),func_021E8A80(CB *);
extern int func_021E8A90(int **);
int func_0217AECC(u32 a,u32 b,u32 c,int *p) {func_0217AF14(p);func_0217AFBC(p);func_021E8A80(*(CB **)((u8 *)p+4));if(func_021E8A90(*(int ***)((u8 *)p+4))) return 1;return 0;}
