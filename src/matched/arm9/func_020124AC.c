/*
 * function: func_020124AC
 * address:  0x020124AC
 * packet:   pkt_020123D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020124AC.c \
 *       --func func_020124AC --addr 0x020124AC --cc 1.1p1 --thumb
 *
 * symbols:
 *   GAME_EVENT_OverlaySeq  0x02012474  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 */

typedef unsigned int u32;

struct Desc;

extern struct Desc *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *GAME_EVENT_GetWork(struct Obj *p);
typedef signed int     s32;
extern int GAME_EVENT_OverlaySeq(void *a0, u32 *a1, u32 *a2);
extern int func_02034AC4(s32 handle);

struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3)
{
    struct Desc *d;
    u32 *p;

    d = GAME_EVENT_Create(a0, 0, GAME_EVENT_OverlaySeq, 0x10);
    p = GAME_EVENT_GetWork((struct Obj *)d);
    p[0] = a1;
    func_02034AC4(a1);
    p[1] = fn(a0, a3);
    return d;
}

