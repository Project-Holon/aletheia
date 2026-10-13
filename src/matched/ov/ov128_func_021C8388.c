/*
 * function: func_021C8388
 * address: 0x021C8388
 * packet: pkt_ov128_021C8388
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled function.
 * symbols:
 *   func_0201283C 0x0201283C thumb
 *   func_021C87A0 0x021C87A0 thumb ov128
 *   func_020099C8 0x020099C8 thumb
 *   DWC_GetFriendKey 0x020598C4 arm
 */
#include "../include/Obj10485.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct BigObj;struct Sub020097BCObj;struct Sub020097BCFriend;
extern u32 func_0201283C(const struct BigObj *);
extern int func_021C87A0(s16 *);
extern struct Sub020097BCFriend *func_020099C8(struct Sub020097BCObj *,int);
extern unsigned long long DWC_GetFriendKey(void *);
unsigned long long func_021C8388(s16 *p,u8 *q) {u32 base;base=func_0201283C(*(const struct BigObj * *)&((struct Obj10485 *)q)->f4);return DWC_GetFriendKey(func_020099C8((struct Sub020097BCObj *)base,*(u8 *)(q+24+func_021C87A0(p))));}
