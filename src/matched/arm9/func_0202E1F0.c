/*
 * unit:     no
 * function: func_0202E1F0
 * address:  0x0202E1F0
 * packet:   pkt_0202E1F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02024570  0x02024570  thumb
 *   func_0202465C  0x0202465C  thumb
 *   func_0202441C  0x0202441C  thumb
 *   func_0201D478  0x0201D478  thumb
 *   func_020244F8  0x020244F8  thumb
 *   func_020244D4  0x020244D4  thumb
 *   func_02024368  0x02024368  thumb
 *   func_0201D528  0x0201D528  thumb
 *   func_0201D4BC  0x0201D4BC  thumb
 *   func_0202E040  0x0202E040  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02043AF4  0x02043AF4  arm
 *   func_02045808  0x02045808  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * blink_palanm: set up a message's blink palette animation.  Copy the
 * caller's MSGPARAM into a local, build the string, mark which characters
 * blink (wk->blink[i]) or are blank (mark[i]), draw the window, then start
 * a palette animation (func_0202E040) on every blinking character and clear
 * every blank one.  Only caller: func_0202DC60, which passes the five stack
 * words (param, pos, pri, pal, heap).
 *
 * Closed 2026-09-24 (wave 21, lane E12) from DIFF 2
 * (docs/notes/pkt_0202E1F0.c.txt, waves 5-21).  Two things together,
 * neither enough on its own:
 *   - the parameter `param` is reused as `param = &mp` after the copy, and
 *     every later call, including func_02024368 after loop 1, takes
 *     `param` (with `&mp` there the image's `adds r0, r7, #0` at +0x8E is
 *     rematerialised as `add r0, sp, #0x38`, 2 out);
 *   - the two stores after func_0202465C are written msg first, then
 *     active.  In the other order the compile puts wk in r7 and param in r6
 *     (21 out).  The scheduler emits the strb before the str in both
 *     orders, so the listing only shows the order through the allocation.
 * The lane-E7 draft (callee widths read from the callees' matched bodies)
 * is the starting point; only those two lines differ from it.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0202E1F0.c \
 *       --func func_0202E1F0 --addr 0x0202E1F0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct { u16 arc; u16 str; u16 code[2]; } MSGPARAM;
typedef struct { s32 x; s32 y; } BLINKPOS;

typedef struct {
    u32   msg;          /* 0x00 */
    u8    active;       /* 0x04 */
    void *act[2];       /* 0x08 */
    u32   unk10[2];     /* 0x10 */
    u32   drawn : 1;    /* 0x18 */
    u32   ready : 1;
    u32   unk1c;        /* 0x1c */
    u32   blink[2];     /* 0x20 */
} BLINKWORK;

struct Container;
struct Pos;
struct Rec8;
struct Struct_0202441C;
struct T;
extern void func_02024570(struct Rec8 *dst, const struct Rec8 *src);
extern u32 func_0202465C(struct T *p, u32 a1, u32 a2);
extern void *func_0202441C(const struct Struct_0202441C *obj, u32 heapId);
extern u32   func_0201D478(void *str);
extern u32 func_020244F8(struct Container *p, u32 idx);
extern u16 func_020244D4(void *obj, u32 idx);
extern void *func_02024368(u16 *slots, u32 heap, int count);
extern u32 func_0201D528(void *s, u8 b, void *c, u32 d);
extern u32   func_0201D4BC(void *s, u8 idx);
struct Descriptor;
extern void func_0202E040(void *h, struct Descriptor *cell, u32 b, u32 c, u32 n, const struct Pos *base);
struct Descriptor;
extern void *func_02045770(struct Descriptor *msg);
struct Cfg;
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void  func_0201C724(void *owner, u32 a, s16 x, s16 y, void *buf, u32 e, u16 f);
extern void  func_02043AF4(u32 a, u32 b, s16 c, u32 d, u32 e, u8 f);
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void  func_02041B6C(u32 bg);

void func_0202E1F0(BLINKWORK *wk, void *owner, u32 a2, struct Descriptor *a3,
                   const MSGPARAM *param, const BLINKPOS *pos,
                   u16 pri, u8 pal, u16 heap)
{
    u32 mark[2] = {0, 0};
    MSGPARAM mp;
    void *str;
    void *buf;
    int i;
    u16 heapID;
    int n;

    func_02024570((struct Rec8 *)(&mp), (const struct Rec8 *)param);
    param = &mp;
    func_0202465C((struct T *)(&mp), 1, heap);
    wk->msg = (u32)a3;
    wk->active = 0;
    heapID = *(u16 *)&heap;
    str = func_0202441C((const struct Struct_0202441C *)param, heapID);
    n = (u8)func_0201D478(str);
    for (i = 0; i < n; i++) {
        if (func_020244F8((struct Container *)param, i)) {
            wk->blink[i] = 1;
        } else if (func_020244D4((void *)param, i) == 0xffff) {
            mark[i] = 1;
        }
    }
    buf = func_02024368((u16 *)param, heapID, n);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)wk->msg)), pal);
    func_0201C724(owner, (u32)func_02045770((struct Descriptor *)wk->msg), pos->x, pos->y, buf, a2, pri);
    wk->active = 1;
    for (i = 0; i < n; i++) {
        if (wk->blink[i] == 1) {
            u32 x = func_0201D528(buf, i, (void *)a2, 0);
            u32 y = func_0201D4BC(buf, i);
            func_0202E040(wk->act[i], a3, x, y, func_020244D4((void *)param, i), (const struct Pos *)pos);
        } else if (mark[i] == 1) {
            u32 x = func_0201D528(buf, i, (void *)a2, 0);
            u32 y = func_0201D4BC(buf, i);
            func_02043AF4((u32)func_02045770((struct Descriptor *)a3), x, y << 4, 0x54, 0x10, pal);
        }
    }
    func_02045808(buf);
    func_02045808(str);
    func_02045374((struct Cfg *)wk->msg);
    func_02041B6C(func_02045730((struct Descriptor *)wk->msg));
    wk->drawn = 1;
    wk->ready = 1;
}
