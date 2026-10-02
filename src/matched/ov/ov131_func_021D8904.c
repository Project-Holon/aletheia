/*
 * function: func_021D8904
 * address: 0x021D8904
 * packet: pkt_ov131_021D8904
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D909C 0x021D909C thumb ov131
 *   func_021DBAC0 0x021DBAC0 thumb ov131
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned int u32;
extern void func_021D909C(void *, void *);
extern void func_021DBAC0(void *);
extern void func_020307B0(void *);
struct S { u32 a; u32 p1[10]; void *f2c; u32 p2; void *f34; u32 p3; void *f3c; u32 p4; void *f44; u32 p5; void *f4c; u32 p6[7]; void *f6c; };
void func_021D8904(void *a, struct S *s) {
 if (s->a == 1) func_021D909C(a, s);
 func_021DBAC0(s->f6c);
 func_020307B0(s->f4c);
 func_020307B0(s->f2c);
 func_020307B0(s->f34);
 func_020307B0(s->f3c);
 func_020307B0(s->f44);
}
