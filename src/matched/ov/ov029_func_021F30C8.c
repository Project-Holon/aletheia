/*
 * function: func_021F30C8
 * address: 0x021F30C8
 * packet: pkt_ov029_021F30C8
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
struct Obj;
extern void func_0204B3B4(struct Obj *p);
struct Slot { void *object; int a; int b; };
struct Obj { char pad[0x3c]; struct Slot slots[20]; };
void func_021F30C8(struct Obj *p)
{
    int i;
    for (i = 0; i < 20; i++) {
        if (p->slots[i].object) {
            func_0204B3B4(p->slots[i].object);
            p->slots[i].object = 0;
        }
    }
}
