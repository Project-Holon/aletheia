/*
 * function: func_02172C4C
 * address: 0x02172C4C
 * packet: pkt_ov012_02172C4C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02172BC0 0x02172BC0 thumb ov012
 *   func_0203CBAC 0x0203CBAC arm
 *   func_02172C98 0x02172C98 thumb ov012
 *   d_02175380 0x02175380 data ov012 a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Work { u8 b[0x3570]; } Work;
extern Work *func_02172BC0(u32 a);
struct Req;
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_02172C98(u8 *p);
extern char d_02175380[];
Work *func_02172C4C(void *unused, u32 a) { Work *p; p = func_02172BC0(a); p->b[0x3560] = 1; func_0203CBAC((struct Req *)d_02175380, (u32)func_02172C98, (u32)p); return p; }
