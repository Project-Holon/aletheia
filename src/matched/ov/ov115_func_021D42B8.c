/*
 * function: func_021D42B8
 * address: 0x021D42B8
 * packet: pkt_ov115_021D42B8
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201283C 0x0201283C thumb
 *   func_020099C8 0x020099C8 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct BigObj;
struct Sub020097BCFriend;
struct Sub020097BCObj;
extern u32 func_0201283C(const struct BigObj *p);
extern struct Sub020097BCFriend *func_020099C8(struct Sub020097BCObj *obj, int i);
void func_021D42B8(u8 *p) { func_020099C8((void *)func_0201283C(*(void **)(p+0x44)),0); }
