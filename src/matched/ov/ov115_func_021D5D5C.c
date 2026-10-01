/*
 * function: func_021D5D5C
 * address: 0x021D5D5C
 * packet: pkt_ov115_021D5D5C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: 5FE8 forwards the pointer returned by matched 0201FDA0;
 * this caller consumes that return. All six observed ov115 caller sites
 * (45F8,4630,46F4,47AE,488E,4926) set mode to literal0/1, so meaningful
 * Template fields are initialized on reachable case0. Complete original
 * contexts/reference search: B10/5D5C-interface-proof.txt; body unchanged.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02027778 0x02027778 thumb
 *   func_02045808 0x02045808 arm
 *   func_0207D658 0x0207D658 arm
 *   func_02027CFC 0x02027CFC thumb
 *   func_021D5FE8 0x021D5FE8 thumb ov115
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u32 heap;
    u8 count, pad[3];
    const void *items;
    u32 param;
    u8 x, y, a, b;
} Template;
extern void *func_020457B0(u32, u32);
extern void func_02045CAC(void *, u32, void *);
extern void *func_02027778(Template *, void *);
extern void func_02045808(void *);
extern void func_0207D658(u32, int, int);
extern void func_02027CFC(u8 *, int);
extern void *func_021D5FE8(u8 *, int, int);
void *func_021D5D5C(u8 *p, int mode, int flag, int selected)
{
    u8 *q = p + 0x54;
    Template t;
    *(u32 *)q = *(u32 *)(p + 0x50);
    switch (*(u32 *)q) {
    case 0:
        t.heap = *(u16 *)(p + 0x4c);
        t.count = 2;
        t.items = q + 4;
        switch (mode) {
        case 0: t.x = 32; t.y = 13; t.param = 1; break;
        case 1: t.x = 32; t.y = 24; t.param = 1; break;
        }
        t.a = 13;
        t.b = 3;
        *(void **)(q + 4) = func_020457B0(100, *(u16 *)(p + 0x4c));
        func_02045CAC(*(void **)(p + 0x1c), 28, *(void **)(q + 4));
        *(u16 *)(q + 8) = 0x39e0;
        *(void **)(q + 0x10) = func_020457B0(100, *(u16 *)(p + 0x4c));
        func_02045CAC(*(void **)(p + 0x1c), 29, *(void **)(q + 0x10));
        *(u16 *)(q + 0x14) = 0x39e0;
        *(void **)(q + 0x20) = func_02027778(&t, *(void **)(q + 0x1c));
        func_02045808(*(void **)(q + 4));
        func_02045808(*(void **)(q + 0x10));
        if (flag != 0) func_0207D658(0x04001050, 17, -8);
        func_02027CFC(*(u8 **)(q + 0x20), selected);
        break;
    case 1:
        *(void **)(q + 0x24) = func_021D5FE8(p, mode, selected);
        *(int *)(q + 0x28) = -1;
        break;
    }
    return q;
}
