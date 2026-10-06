/*
 * function: func_0217F8EC
 * address: 0x0217F8EC
 * packet: pkt_ov019_0217F8EC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217FCE4 0x0217FCE4 thumb ov019
 *   func_0217FBD0 0x0217FBD0 thumb ov019
 *   func_0217FABC 0x0217FABC thumb ov019
 *   func_0217F9BC 0x0217F9BC thumb ov019
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct E;
extern void func_0217FCE4(struct E *p);
extern void func_0217FBD0(char *p);
extern void func_0217FABC(u32 *p);
extern void func_0217F9BC(char *p);
extern u32 func_020307B0(void *p);
void func_0217F8EC(char *p) { if(p) { func_0217FCE4((struct E *)(p+0x20)); func_0217FBD0(p+0x20); func_0217FABC((u32 *)p); func_0217F9BC(p); func_020307B0(p); } }
