/*
 * function: func_021FF52C
 * address: 0x021FF52C
 * packet: pkt_ov186_021FF52C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FFB58 0x021FFB58 thumb ov186
 *   func_021D6A34 0x021D6A34 thumb ov125
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {int(*fn)(void*,void*,int);char pad_04[4];int arg_08;} S;
extern void func_021FFB58(S*);
extern int func_021D6A34(char*);
void func_021FF52C(char*p){if(*(u32*)(p+1444)){func_021FFB58(*(S**)(p+1452));func_021D6A34(p);}}
