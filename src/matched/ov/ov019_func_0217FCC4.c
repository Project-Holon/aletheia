/*
 * function: func_0217FCC4
 * address: 0x0217FCC4
 * packet: pkt_ov019_0217FCC4
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216D88C 0x0216D88C thumb ov010
 *   func_02047AC8 0x02047AC8 arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct Actor; struct Arg;
typedef struct { int x,y,z; } VecFx32;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern int func_02047AC8(void *a, struct Arg *b);
void func_0217FCC4(u32 *p, u32 *b) { func_0216D88C((const struct Actor *)p[0], (struct VecFx32 *)b); b[1] -= 0x6800; func_02047AC8((void *)p[3], (struct Arg *)b); }
