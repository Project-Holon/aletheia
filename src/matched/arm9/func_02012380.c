/*
 * function: GAME_EVENT_Control
 * address:  0x02012380
 * packet:   pkt_02012380
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetEvent   0x02012104  thumb
 *   GAMESYSTEM_SetEvent   0x02012108  thumb
 *   GAME_EVENT_RunFunc   0x02012304  thumb
 *   GAME_EVENT_Delete   0x02012314  thumb
 *   GAME_EVENT_GetParent   0x020124F0  thumb
 *
 * game_event.c: run the event queue until it drains, stalls or finishes.
 * The dangling `cmp r0, #0x21` followed by an unconditional branch back to
 * the loop head is a SWITCH whose case 0x21 lands where the default does:
 * the compare chain keeps the compare and drops the branch.  An if chain
 * (docs/notes/pkt_02012380.c.txt, 38 out) never emits it.
 */

struct Ctx;
extern unsigned int GAMESYSTEM_GetEvent(const struct Ctx *p);
typedef unsigned int   u32;
struct Ctx;
struct S02012304;
extern void GAMESYSTEM_SetEvent(struct Ctx *p, u32 v);
extern int GAME_EVENT_RunFunc(struct S02012304 *o);
extern void GAME_EVENT_Delete(char *p);
struct Obj;
extern void *GAME_EVENT_GetParent(struct Obj *p);

int GAME_EVENT_Control(void *p)
{
    void *v;
    int x;

    for (;;) {
        v = (void *)GAMESYSTEM_GetEvent(p);
        if (v == 0)
            return 0;
        switch (GAME_EVENT_RunFunc(v)) {
        case 0:
            return 0;
        case 1:
            x = (int)GAME_EVENT_GetParent(v);
            GAME_EVENT_Delete(v);
            GAMESYSTEM_SetEvent(p, x);
            if (x == 0)
                return 1;
            break;
        case 0x21:
            break;
        }
    }
}
