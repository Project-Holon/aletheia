/*
 * function: func_021A274C
 * address:  0x021A274C
 * packet:   pkt_ov021_021A274C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: original spills p to [sp] at entry and, on the return path,
 * reloads it, adds 0x74, stores it back, then adds i*0x38; the draft keeps
 * p+0x74 in r4 for both uses. Unknown source shape for the store-back.
 *
 * symbols:
 *   func_021A2BC4  0x021A2BC4  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    u8 data[0x38];
} Slot021A274C;

typedef struct {
    u8 pad[0x74];
    Slot021A274C slots[0x20];
} Obj021A274C;

int func_021A2BC4(Slot021A274C *s);

Slot021A274C *func_021A274C(Obj021A274C *p)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        if (func_021A2BC4(&p->slots[i]) == 0)
            return &p->slots[i];
    }
    return 0;
}
