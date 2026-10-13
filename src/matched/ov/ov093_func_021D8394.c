/*
 * function: BTL_ACTION_SetChange
 * address: 0x021D8394
 * packet: pkt_ov093_021D8394
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct B { u32 kind:4; u32 sub:3; u32 val:3; u32 flag:1; u32 rest:21; }; void BTL_ACTION_SetChange(struct B *p,u32 sub,u32 val) { struct B t={0}; t.kind=3; t.sub=sub; t.val=val; t.flag=0; *p=t; }
