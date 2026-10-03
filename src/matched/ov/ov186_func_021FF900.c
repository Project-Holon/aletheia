/*
 * function: func_021FF900
 * address: 0x021FF900
 * packet: pkt_ov186_021FF900
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D67C8 0x021D67C8 thumb ov125
 *   func_02034714 0x02034714 arm
 *   func_021FFB68 0x021FFB68 thumb ov186
 *   func_021FF8E4 0x021FF8E4 thumb ov186
 *   d_02200D98 0x02200D98 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct{int words[32];} Block128;
typedef struct{int words[108];} Block432;
extern int func_021D67C8(char*,const Block128*,const Block432*);
extern void func_02034714(const char*,u32,const char*);
extern void func_021FFB68(char*,int);
extern void func_021FF8E4(void*,int,int);
extern const char d_02200D98[];
void func_021FF900(char*p,int unused,char*q){if(!func_021D67C8(q,*(const Block128**)(q+1448),*(const Block432**)(q+1456)))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}
