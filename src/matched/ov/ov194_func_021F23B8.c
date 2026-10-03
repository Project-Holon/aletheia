/*
 * function: func_021F23B8
 * address: 0x021F23B8
 * packet: pkt_ov194_021F23B8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045A98 0x02045A98 arm
 *   func_021F2190 0x021F2190 thumb ov194
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_02045A98(void);
extern int func_021F2190(char *,u16);
void func_021F23B8(char *p,const u16 *q) {while(*q!=func_02045A98()) {if(!func_021F2190(p,*q)) break;q++;}}
