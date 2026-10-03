/*
 * function: func_021C0AA0
 * address:  0x021C0AA0
 * packet:   pkt_ov021_021C0AA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns a 0x3C-byte task (callback func_021C0AC0) and initialises it.
 *
 * symbols:
 *   func_021C0B3C  0x021C0B3C  thumb  ov021
 *   func_021C0AC0  0x021C0AC0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
struct Obj;
void *func_020124E8(struct Obj *p);
void func_021C0AC0(void);
void func_021C0B3C(u8 *p, u32 a);

void *func_021C0AA0(void *p, int a1)
{
    void *t = func_020122C0(p, a1, func_021C0AC0, 0x3C);
    u8 *w = func_020124E8(t);

    func_021C0B3C(w, (u32)p);
    return t;
}
