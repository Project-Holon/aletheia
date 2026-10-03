/*
 * function: func_021D6A9C
 * address: 0x021D6A9C
 * packet: pkt_ov120_021D6A9C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   data_021D8B73 0x021D8B73 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern const u8 data_021D8B73[];
int func_021D6A9C(u8 *p,u32 n){void *obj=*(void **)(p+0x134);if(!obj)return 0;func_0204B878(obj,*(const u8 *)((u32)data_021D8B73+n*4));return 1;}
