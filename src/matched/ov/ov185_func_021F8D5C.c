/*
 * function: func_021F8D5C
 * address: 0x021F8D5C
 * packet: pkt_ov185_021F8D5C
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F3BF0 0x021F3BF0 thumb ov112
 *   func_021FC640 0x021FC640 thumb ov186
 *   func_021FC148 0x021FC148 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FEEC0 0x021FEEC0 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void func_021F3BF0(u8 *);
extern void func_021FC640(void *,unsigned);
extern void func_021FC148(char *,unsigned,unsigned);
extern void func_021FB964(void *,unsigned,u16);
extern void func_021FEEC0(char *p, int mode, u32 value);
void func_021F8D5C(char *p,char *q) { if(*(void **)(p+0x14)){func_021F3BF0(*(void **)(p+0x14));*(void **)(p+0x14)=0;func_021FC640(*(void **)(q+8),*(u16 *)(p+0x30));func_021FC148(*(char **)(q+12),0,*(u16 *)(p+0x30));func_021FB964(*(void **)(q+12),0,*(u16 *)(p+0x30));func_021FEEC0((char *)(*(int *)(q+4)),0,1);} }
