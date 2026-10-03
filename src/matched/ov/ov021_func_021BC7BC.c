/*
 * function: func_021BC7BC
 * address:  0x021BC7BC
 * packet:   pkt_ov021_021BC7BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef struct {
    char pad[0x34];
    void *f34[1];
    void *f38;
} Obj;

struct Bank;
extern void func_0204B258(struct Bank *bank, void *p);

void func_021BC7BC(Obj *p, int i)
{
    if (p->f38 != 0) {
        func_0204B258(p->f34[i], p->f38);
    }
}
