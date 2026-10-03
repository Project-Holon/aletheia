/*
 * unit: no
 * function: func_021BAC90
 * address: 0x021BAC90
 * packet: pkt_ov214_021BAC90
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204989C 0x0204989C arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040618 0x02040618 arm
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void func_0204989C(u32,u32,u32,u16,u32,u32,u16);extern void func_02041B6C(u32);extern void func_02040618(u32,u32,u32);
void func_021BAC90(int unused,u8 *p){enum{K=2}k=K;func_0204989C(188,3,k,*(u32 *)(p+0x2c0),0,0,*(u16 *)p);func_02041B6C(2);k-=10;func_02040618(3,3,k);}
