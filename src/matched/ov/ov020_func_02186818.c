/*
 * function: func_02186818
 * address: 0x02186818
 * packet: pkt_ov020_02186818
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204932C 0x0204932C arm
 */

typedef unsigned int u32;
struct ArcFile;
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
void func_02186818(u32 *p, u32 member) { func_0204932C((struct ArcFile *)p[0], member, p + 2); p[1] = member; }
