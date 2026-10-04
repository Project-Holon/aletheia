/*
 * function: func_021F9FE8
 * address: 0x021F9FE8
 * packet: pkt_ov186_021F9FE8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FD1BC 0x021FD1BC thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void func_021FD71C(u8 *p);
extern u32 func_0201C4E4(struct PrintSys *);
extern void func_021FD1BC(char *);
void func_021F9FE8(char *p) { func_021FD71C((u8 *)(*(int *)(p+12)));func_0201C4E4(*(struct PrintSys **)(p+0x4c));if(*(char **)(p+0x50))func_021FD1BC(*(char **)(p+0x50)); }
