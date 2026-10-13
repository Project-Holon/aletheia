/*
 * function: GAME_EVENT_CallProc
 * address:  0x02012444
 * packet:   pkt_020123D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Promoted from src/pending/ in the second 0-64 byte band pass (lane 1).  It
 * sat at MATCH on the pool word at +0x2C, which holds 0x0201240D - the state
 * machine at 0x0201240C with its Thumb bit, handed to GAME_EVENT_Create as a
 * callback.  That word is the only one in the image naming 0x0201240D, and no
 * branch reaches 0x0201240C from outside this range either, so the site needed
 * 0x0201240C to be an EXACT entry of its own; now that it is, the site
 * resolves through the `matched` class and this file needs no change.
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_EVENT_CallProc.c \
 *       --func GAME_EVENT_CallProc --addr 0x02012444 --cc 1.1p1 --thumb
 *
 * symbols:
 *   GAME_EVENT_CallProcSeq  0x0201240C  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Desc;

extern struct Desc *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size);
struct Evt;
struct Obj;
extern void *GAME_EVENT_GetWork(struct Obj *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int GAME_EVENT_CallProcSeq(void *o, u32 *state, u32 *item);

struct Obj {
    u8    pad_00[0x10];
    void *unk_10;
};

void GAME_EVENT_CallProc(struct Obj *obj, u32 a1, u32 a2, u32 a3)
{
    struct Desc *d;
    u32 *p;

    d = GAME_EVENT_Create(obj->unk_10, 0, GAME_EVENT_CallProcSeq, 0xc);
    p = GAME_EVENT_GetWork((struct Obj *)d);
    p[0] = a1;
    p[1] = a2;
    p[2] = a3;
    GAME_EVENT_CallEvent((struct Evt *)obj, (struct Evt **)d);
}
