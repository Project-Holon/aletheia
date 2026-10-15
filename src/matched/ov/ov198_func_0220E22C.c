/*
 * unit: no
 * function: B_PLIST_DRAW_UpdateToolWindows
 * address: 0x0220E22C
 * packet: pkt_ov198_0220E22C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: enum offset k retained across the call; j saves k+0x10 before k-=0xb4. Parenthesised offsets and the sequenced local match the 48-byte original.
 * symbols:
 *   B_APP_TOOL_Update 0x0220B0B0 thumb ov196
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Entry;extern void B_APP_TOOL_Update(struct Entry *,int,u32);
void B_PLIST_DRAW_UpdateToolWindows(u8 *p){enum{K=0x1f60}k=K;u32 j;B_APP_TOOL_Update((struct Entry *)(p+k),*(int *)(p+(k-0xb4)),2);j=k+0x10;k-=0xb4;B_APP_TOOL_Update((struct Entry *)(p+j),*(int *)(p+k),p[0x2174]);}
