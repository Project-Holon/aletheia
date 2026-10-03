/*
 * function: func_02012380
 * address:  0x02012380
 * packet:   pkt_02012380
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   sub_02012104   0x02012104  thumb
 *   sub_02012108   0x02012108  thumb
 *   sub_02012304   0x02012304  thumb
 *   sub_02012314   0x02012314  thumb
 *   sub_020124F0   0x020124F0  thumb
 *
 * game_event.c: run the event queue until it drains, stalls or finishes.
 * The dangling `cmp r0, #0x21` followed by an unconditional branch back to
 * the loop head is a SWITCH whose case 0x21 lands where the default does:
 * the compare chain keeps the compare and drops the branch.  An if chain
 * (docs/notes/pkt_02012380.c.txt, 38 out) never emits it.
 */

extern void *sub_02012104(void *p);
typedef unsigned int   u32;
struct Ctx;
struct S02012304;
extern void sub_02012108(struct Ctx *p, u32 v);
extern int sub_02012304(struct S02012304 *o);
extern void sub_02012314(char *p);
extern int   sub_020124F0(void *v);

int func_02012380(void *p)
{
    void *v;
    int x;

    for (;;) {
        v = sub_02012104(p);
        if (v == 0)
            return 0;
        switch (sub_02012304(v)) {
        case 0:
            return 0;
        case 1:
            x = sub_020124F0(v);
            sub_02012314(v);
            sub_02012108(p, x);
            if (x == 0)
                return 1;
            break;
        case 0x21:
            break;
        }
    }
}
