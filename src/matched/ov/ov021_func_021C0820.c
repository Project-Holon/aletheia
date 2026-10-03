/*
 * function: func_021C0820
 * address:  0x021C0820
 * packet:   pkt_ov021_021C0820
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns a 0x38-byte task (callback func_021C0844) and initialises it.
 *
 * symbols:
 *   func_021C0904  0x021C0904  thumb  ov021
 *   func_021C0844  0x021C0844  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
struct Obj;
void *func_020124E8(struct Obj *p);
void func_021C0844(void);
void func_021C0904(u8 *p, u32 a, u32 n);

void *func_021C0820(void *p, int a1, u32 n)
{
    void *t = func_020122C0(p, a1, func_021C0844, 0x38);
    u8 *w = func_020124E8(t);

    func_021C0904(w, (u32)p, n);
    return t;
}
