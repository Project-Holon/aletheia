/*
 * function: func_021DFD68
 * address:  0x021DFD68
 * packet:   pkt_ov093_021DFD68
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef struct Rec {
    int pad00;
    int f04;
    unsigned char pad08[4];
    unsigned char f0c;
    unsigned char pad0d[2];
    unsigned char f0f;
    unsigned char f10;
} Rec;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021DFD68(void *self, void *q, int id)
{
    Rec *r;

    if (id != BTL_EVENT_GetVar(2))
        return;
    r = (Rec *)func_021C88A4(q, 14, id);
    r->f0f = 1;
    r->f10 = id;
    r->f04 = 3;
    r->f0c = 1;
    func_021C88C8(q, r);
}
