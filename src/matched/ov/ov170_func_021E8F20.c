/*
 * function: func_021E8F20
 * address: 0x021E8F20
 * packet: pkt_ov170_021E8F20
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021EBADC 0x021EBADC thumb ov170
 *   func_021EA984 0x021EA984 thumb ov170
 *   func_021E8FE8 0x021E8FE8 thumb ov170
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021EC000(char *,int,int);
extern void func_021ED508(u8 *,int,int);
extern void func_021EBADC(char *,int);
extern void func_021EA984(u8 *);
extern int func_021E8FE8(u8 *,int);
void func_021E8F20(u8 *p){func_021EC000(*(char **)(p+0x2c),4,0);func_021ED508(p,14,0);func_021EBADC((char *)p,24);func_021EA984(p);func_021E8FE8(p,4);}
