/*
 * function: NET_PARTY_COMMAND_IsHandleFor
 * address: 0x021DC86C
 * packet: pkt_ov134_021DC86C
 * region: ov134
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding; early return keeps the final unused compare.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
void NET_PARTY_COMMAND_IsHandleFor(u32 value,u32 a,u32 b,u32 c,void *expected) { if(expected==GFL_NET_HANDLE_GetCurrentHandle()) { if(value!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) return; } }
