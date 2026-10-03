/*
 * function: func_021B7FC8
 * address: 0x021B7FC8
 * packet: pkt_ov106_021B7FC8
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte alignment padding, no follower.
 * symbols:
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204B1CC(void *);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *,int,int);
void func_021B7FC8(void **p) { func_0204B1CC(*p); func_0204A5AC(); func_02082BCC(p,0,20); }
