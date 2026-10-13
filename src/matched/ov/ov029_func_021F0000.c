/*
 * function: func_021F0000
 * address:  0x021F0000
 * packet:   pkt_ov029_021F0000
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0000  0x021F0000  thumb  ov029
 *   CLACT_GetActorAnimSeqCount  0x0204B918  arm
 *   CLACT_GetActorAnimFrame  0x0204B8F4  arm
 */

typedef unsigned short u16;
struct Obj;
extern u16 CLACT_GetActorAnimSeqCount(struct Obj *p);
typedef unsigned int   u32;
struct Obj;
extern u32 CLACT_GetActorAnimFrame(struct Obj *p);

struct Slot {
    void *obj;
    int a;
    int b;
};

struct Owner {
    unsigned char pad[0x3c];
    struct Slot s[20];
};

struct Slot *func_021F0000(struct Owner *p)
{
    int best = -1;
    int bestSub = -1;
    int idx = 0;
    int i;
    int pri;
    int sub;

    for (i = 0; i < 20; i++) {
        if (p->s[i].obj == 0) {
            return &p->s[i];
        }
        pri = CLACT_GetActorAnimSeqCount(p->s[i].obj);
        sub = CLACT_GetActorAnimFrame(p->s[i].obj);
        if (pri > best || (pri == best && sub > bestSub)) {
            best = pri;
            bestSub = sub;
            idx = i;
        }
    }
    return &p->s[idx];
}
