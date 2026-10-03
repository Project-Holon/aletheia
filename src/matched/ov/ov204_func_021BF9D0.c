/*
 * function: func_021BF9D0
 * address: 0x021BF9D0
 * packet: pkt_ov204_021BF9D0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048AC4 0x02048AC4 arm
 *   func_020480E4 0x020480E4 arm
 *   func_02047E54 0x02047E54 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx; struct Rec; extern void func_02048AC4(void *); extern void func_020480E4(struct Ctx *,u32); extern void func_02047E54(struct Rec *); extern void func_020307B0(void *);
void func_021BF9D0(char *p) { u16 id; func_02048AC4(*(void **)(p+12)); id=*(u16 *)(p+16); if(id!=65535) func_020480E4(*(struct Ctx **)(p+8),id);func_02047E54(*(struct Rec **)(p+8));func_020307B0(p); }
