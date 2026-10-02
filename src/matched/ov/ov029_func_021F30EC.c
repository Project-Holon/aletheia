/*
 * function: func_021F30EC
 * address: 0x021F30EC
 * packet: pkt_ov029_021F30EC
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 */
extern unsigned int func_0204B98C(void *);
struct Slot { void *object; int a; int b; };
struct Obj { char pad[0x3c]; struct Slot slots[20]; };
int func_021F30EC(struct Obj *p)
{
    int result = 1;
    int i;
    for (i = 0; i < 20; i++) {
        if (p->slots[i].object) {
            if (func_0204B98C(p->slots[i].object)) {
                result = 0;
                break;
            }
        }
    }
    return result;
}
