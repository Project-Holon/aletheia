/*
 * function: func_021BDFA8
 * address: 0x021BDFA8
 * packet: pkt_ov208_021BDFA8
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BE1BC 0x021BE1BC thumb
 *   func_021BE16C 0x021BE16C thumb
 *   func_021BD208 0x021BD208 thumb
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
struct Ov208Mgr;
struct Ov208Eff { char pad[0x30]; struct Ov208Mgr *mgr; char pad2[0x10]; void *f44; void *f48; void *f4c; };
extern void func_021BE1BC(struct Ov208Eff *e);
extern void func_021BE16C(struct Ov208Eff *e);
extern void func_021BD208(struct Ov208Mgr *m);
typedef unsigned int   u32;
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
void func_021BDFA8(struct Ov208Eff *e)
{
    if (e->mgr != 0) {
        func_021BE1BC(e);
        func_021BE16C(e);
        func_021BD208(e->mgr);
        func_0204ADA4((u32)e->f44);
        func_0204A8D4((u32)e->f48);
        func_0204AFD8((u32)e->f4c);
    }
    e->mgr = 0;
}
