/*
 * function: func_021DD8A8
 * address:  0x021DD8A8
 * packet:   pkt_021DD8A8
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017D30  0x02017D30  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_02017D70  0x02017D70  thumb
 */
typedef unsigned int u32;

extern void *func_0201AB28(void *p, u32 idx);
struct Sav;
extern u32 func_02017D30(struct Sav *p);
extern void func_020185C4(void *p);
extern u32 func_02017D70(struct Sav *p, u32 f);

void func_021DD8A8(void **pp, u32 idx)
{
    void *h;
    u32 v;

    if (idx < 0x1e)
        return;
    h = func_0201AB28(*(void **)((char *)*pp + 8), idx - 0x1e);
    v = func_02017D30(h);
    func_020185C4(h);
    func_02017D70(h, v);
}
