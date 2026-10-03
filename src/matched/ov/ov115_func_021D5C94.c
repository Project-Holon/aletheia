/*
 * function: func_021D5C94
 * address: 0x021D5C94
 * packet: pkt_ov115_021D5C94
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte alignment padding, no follower.
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_021D5FA0 0x021D5FA0 thumb ov115
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_0202F038(u8 *);
extern void func_0201F7A8(void *,u32);
struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern u32 func_021D5FA0(u32);
extern void func_02041B6C(u32);
void func_021D5C94(u8 *p) { if(*(u8 **)(p+128)) { func_0202F038(*(u8 **)(p+128)); *(u8 **)(p+128)=0; } if(*(void **)(p+44)) { func_0201F7A8(*(void **)(p+44),2); func_020456F8(*(void **)(p+44)); func_02041B6C(func_021D5FA0(*(u32 *)(p+80))); } }
