/*
 * function: func_021DF0D4
 * address: 0x021DF0D4
 * packet: pkt_ov170_021DF0D4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EBFA8 0x021EBFA8 thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank; struct CharBuf; struct Descriptor; struct Rec; struct Node; struct Blk37;
extern void func_021EBFA8(char *,int,u16);
extern void func_021EC000(char *,int,int);
void func_021DF0D4(char *p,int base,u32 bits) { u16 i,v;for(i=0;i<6;i++){if(bits & (1<<i))v=i*2+1;else v=i*2;func_021EBFA8(*(char **)(p+0x2c),base+i,v);func_021EC000(*(char **)(p+0x2c),base+i,1);} }
