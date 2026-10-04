/*
 * function: func_0202271C
 * address:  0x0202271C
 * packet:   pkt_0202271C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020222A8  0x020222A8  thumb
 *   func_020238B4  0x020238B4  thumb
 *   func_0202390C  0x0202390C  thumb
 *   d_0209F570     0x0209F570  data
 *   g_020A73D0     0x020A73D0  data
 *   g_wipe_slot0   0x020A73D0  data
 *
 * wipe.c (docs/families/wipe.h): the slot-0 member of the four setup steps
 * 0x0202271C/0x02022758/0x02022790/0x020227CC (template: func_02022758).
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 9 out under 1.1p1 and 1 out
 * under every 2.0 build, docs/notes/pkt_0202271C.c.txt): the pool carries
 * 0x020A73D0 TWICE (0x02022750 for the store, 0x02022754 for the argument),
 * so two source-level names were in play. The slot store goes through
 * g_020A73D0 and the argument is a second extern, g_wipe_slot0, at the same
 * address. With one name 1.1p1 CSEs both uses into r5 (push {r3, r4, r5,
 * lr}); with two it reloads each from its own pool word under push {r4, lr}.
 * Same finding as src/matched/func_02023F98.c in the same module, whose
 * header explains why the bytes fix the number of names but not whether the
 * original had one object or two declarations of it. For the other three
 * slots the two uses differ by the slot offset, so one name suffices there.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct T {
    u8  pad00[0xc];
    u32 f0c;
    u8  pad10[0x14];
    u16 f24;
    u8  pad26[2];
    u32 f28;
    u32 f2c;
};

struct G {
    u32 f00;
    u8  pad04[0xc];
    u32 f10;
    u8  pad14[0xc];
    u32 f20;
    u32 pad24;
    u32 f28;
};

extern void func_020222A8(u32 v);
struct Task;
extern void func_020238B4(struct Task *t, u32 a1);
extern u32 func_0202390C(struct Task *t);
extern const u32 d_0209F570[];
extern struct G g_020A73D0;
extern struct G g_wipe_slot0;

void func_0202271C(struct T *p)
{
    if (p->f0c == 0) {
        g_020A73D0.f00 = (u32)d_0209F570;
        func_020222A8(p->f24);
        func_020238B4((struct Task *)p, (u32)(&g_wipe_slot0));
        p->f28 = 1;
        p->f2c = 0;
    } else {
        func_0202390C((struct Task *)p);
    }
}
