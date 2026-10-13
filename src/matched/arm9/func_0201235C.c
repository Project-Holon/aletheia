/*
 * function: GAME_EVENT_ChangeEvent
 * address:  0x0201235C
 * packet:   pkt_0201235C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_Delete  0x02012314  thumb
 *   GAMESYSTEM_SetEvent  0x02012108  thumb
 *
 * Reads the object's +0x10 word into a register first, then copies its +0 word
 * out through the caller's pointer and hands that same value to
 * GAME_EVENT_Delete, then passes the +0x10 word and the pointer to GAMESYSTEM_SetEvent.
 * Order matters: the +0x10 load is hoisted above the store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_EVENT_ChangeEvent.c \
 *       --func GAME_EVENT_ChangeEvent --addr 0x0201235C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct S0201235C {
    u32 f00;
    unsigned char pad[0xc];
    u32 f10;
};

extern void GAME_EVENT_Delete(char *p);
struct Ctx;
extern void GAMESYSTEM_SetEvent(struct Ctx *p, u32 v);

void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out)
{
    u32 t = o->f10;
    u32 v = o->f00;

    *out = v;
    GAME_EVENT_Delete((char *)o);
    GAMESYSTEM_SetEvent((struct Ctx *)t, (u32)out);
}
