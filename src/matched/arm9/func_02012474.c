/*
 * function: GAME_EVENT_OverlaySeq
 * address:  0x02012474
 * packet:   pkt_020123D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_EVENT_OverlaySeq.c \
 *       --func GAME_EVENT_OverlaySeq --addr 0x02012474 --cc 1.1p1 --thumb
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 */

typedef unsigned int u32;

struct Evt;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_02034A5C(int handle);

int GAME_EVENT_OverlaySeq(void *a0, u32 *a1, u32 *a2)
{
    GAME_EVENT_GetGameSystem(a0);
    switch (*a1) {
    case 0:
        func_02012374(a0, (void *)a2[1]);
        (*a1)++;
        break;
    case 1:
        func_02034A5C((int)a2[0]);
        return 1;
    }
    return 0;
}
