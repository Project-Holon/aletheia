/*
 * function: func_0217F894
 * address: 0x0217F894
 * packet: pkt_ov019_0217F894
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02009D50 0x02009D50 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Sub020097BCObj;
extern int func_02009D50(struct Sub020097BCObj *obj, const void *unused, u32 id, u32 kind, u32 *out);
struct Bits { u8 pad[7]; unsigned char low:3; unsigned char kind:1; unsigned char high:4; };
int func_0217F894(void *p,char *q) { u32 out; if(func_02009D50(p,q+12,*(u32 *)(q+0x5c), ((struct Bits *)q)->kind,&out)==1) { return 1; } else { return 0; } }
