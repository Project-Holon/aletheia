/*
 * function: func_021E7AE0
 * address: 0x021E7AE0
 * packet: pkt_ov177_021E7AE0
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: repeat result accumulation in each branch; hoisting through done changes cross-jump and allocation.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_0202DBC4 0x0202DBC4 thumb
 *   func_0202DC98 0x0202DC98 thumb
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Descriptor;
struct Obj0202DC98;
struct PrintSys;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_0202DBC4(u8 *p);
extern u32 func_0202DC98(struct Obj0202DC98 *o);
static inline int poll_entry(unsigned char *e, void *mgr)
{
    if (e[0x28] != 0) {
        if (func_0201C6C4(mgr, func_02045770(*(void **)(e + 0x24))) == 0) {
            func_02045334(*(void **)(e + 0x24));
            e[0x28] = 0;
        }
    }
    return e[0x28] == 0;
}
int func_021E7AE0(unsigned char *p, void *mgr)
{
    int i;
    unsigned result = 1;
    for (i = 0; i < 8; i++) {
        unsigned done;
        if (i != 7) {
            result &= poll_entry(p + i * 8, mgr);
        } else {
            func_0202DBC4(*(void **)(p + 0x7c));
            result &= func_0202DC98(*(void **)(p + 0x7c));
        }
    }
    return result;
}
