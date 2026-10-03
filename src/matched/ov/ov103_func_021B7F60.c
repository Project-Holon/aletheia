/*
 * function: func_021B7F60
 * address: 0x021B7F60
 * packet: pkt_ov103_021B7F60
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02047804 0x02047804 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct AnmCtl;
extern u32 func_02047804(struct AnmCtl *c, u32 idx);
void func_021B7F60(u8 *p,int n) {if(*(int *)(p+0x58)!=n) {func_02047804(*(void **)(p+0x10),0); *(int *)(p+0x58)=n;}}
