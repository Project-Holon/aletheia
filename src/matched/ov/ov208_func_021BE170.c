/*
 * function: ov208_func_021BE170
 * address:  0x021BE170
 * packet:   pkt_ov208_021BE170
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD3C0  0x021BD3C0  thumb
 *   func_0204B6F4  0x0204B6F4  arm
 */

typedef unsigned int u32;

struct Ov208Slot {
    int *key;
    u32 f4;
};

struct Ov208Scene {
    u32 pad0[7];
    u32 f1c;
    u32 pad20[4];
    u32 mgr;
    u32 pad34[14];
    struct Ov208Slot slots[10];
};

struct Obj;
extern int func_021BD3C0(void *mgr, int key);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);

void ov208_func_021BE170(struct Ov208Scene *p)
{
    u32 idx = 9;

    switch (p->f1c) {
    case 0:
        idx = 6;
        break;
    case 1:
        idx = 5;
        break;
    case 2:
        idx = 4;
        break;
    case 3:
        idx = 3;
        break;
    }
    if (idx != 9)
        func_0204B6F4((struct Obj *)func_021BD3C0((void *)p->mgr, *p->slots[idx].key), 2, 0);
}
