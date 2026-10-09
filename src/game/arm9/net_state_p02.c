/*
 * file:     net_state_p02.c
 * unit:     yes
 * function: func_0203675C, func_020367C4, func_020368C0, func_020369C8, func_020369F8, func_02036A50, func_02036AF4
 * address:  0x0203675C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020364D4  0x020364D4  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02036670   0x02036670  arm
 *   func_0203660C   0x0203660C  arm
 *   func_02036428   0x02036428  arm
 *   func_0203666C   0x0203666C  arm
 *   func_02034714   0x02034714  arm
 *   g_020A79C4      0x020A79C4  data
 *   g_020A79D0      0x020A79D0  data
 *   g_020A79D4      0x020A79D4  data
 *   str_020A79C4  0x020A79C4  data
 *   str_020A79EC  0x020A79EC  data
 *   func_020366FC 0x020366FC  arm
 *   func_02082BCC   0x02082BCC  arm
 *   func_02030734 0x02030734  arm
 */
#include "../../matched/include/Obj04748.h"
#include "../../matched/include/Obj11349.h"
#include "../../matched/include/Obj08825.h"
#include "../../matched/include/Obj08826.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int            BOOL;

typedef struct {
    u8  *src;       /* +0x00 */
    u32  pad4;
    u32  pad8;
    u16  rest;      /* +0x0C */
    u16  fE;
    u8   f10;
    u8   headerDone;/* +0x11 */
} NetSendItem;

typedef struct {
    u8  *ptr;       /* +0x00 */
    u16  len;       /* +0x04 */
} NetOutBuf;

typedef struct Node020368C0 {
    u32 f0;
    struct Node020368C0 *f4;
    struct Node020368C0 *f8;
    u16 fC;
    u16 fE;
    u8 f10;
    u8 f11;
} Node020368C0;

typedef struct Queue020368C0 {
    Node020368C0 *f0;
    Node020368C0 *f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
} Queue020368C0;

extern int func_020364D4(char *p, unsigned char *dst, int len, int max);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern Node020368C0 *func_02036670(Queue020368C0 *q, u32 a1, u32 a2, u32 a3);
extern u32 func_0203660C(u32 h);
extern void func_02036428(u32 h, u32 a2, u32 a3);
extern void func_0203666C(u32 h);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020366FC(u32 *p);
extern void *func_02082BCC(void *dst, int val, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
int func_0203675C(int a0, int a1);
int func_020367C4(NetSendItem *item, NetOutBuf *out, void *ring, BOOL needHeader);
int func_020368C0(Queue020368C0 *q, u16 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
u32 func_020369C8(u32 *p);
void func_020369F8(u8 *p);
int func_02036A50(u32 list, u16 *info);
void func_02036AF4(u8 *p, u32 n, u32 a, u32 b);
extern char g_020A79C4[];
extern char g_020A79D0[];
extern char g_020A79D4[];
extern const u8 str_020A79C4[];
extern const u8 str_020A79EC[];



int func_0203675C(int a0, int a1){ int t0, t1, t2, t3, t4; t0 = func_02036738((int)a1, (int)((((struct Obj04748 *)((char *)(a0)))->fE >> 8) & 0xff), (int)((struct Obj04748 *)((char *)(a0)))->fE); t1 = func_02036738((int)a1, (int)(((struct Obj04748 *)((char *)(a0)))->fE & 0xff)); t2 = func_02036738((int)a1, (int)((((struct Obj04748 *)((char *)(a0)))->fC >> 8) & 0xff)); t3 = func_02036738((int)a1, (int)(((struct Obj04748 *)((char *)(a0)))->fC & 0xff)); t4 = func_02036738((int)a1, (int)((struct Obj04748 *)((char *)(a0)))->f10); return 0; }




/*
 * Moves one queued send item into an output window: on first touch writes
 * the item's five-byte header (func_0203675C, refused with 0 when a header
 * is required and the window cannot hold rest + 5), then copies as much of
 * the payload as fits -- from the item's own source pointer with
 * MI_CpuCopy8, or out of the ring with func_020364D4 when it has none.  A
 * partial copy leaves the window marked full (0xFFFF) and the item's
 * header flag set; a complete one advances the window.  Exact on the first
 * compile from the image's field widths.
 */
int func_020367C4(NetSendItem *item, NetOutBuf *out, void *ring, BOOL needHeader)
{
    if (item->headerDone == 0) {
        if (needHeader != 0 && out->len < item->rest + 5) {
            return 0;
        }
        func_0203675C((int)item, (int)out);
    }
    if (out->len < item->rest) {
        if (item->src == 0) {
            func_020364D4(ring, out->ptr, out->len, out->len);
        } else {
            MI_CpuCopy8(item->src, out->ptr, out->len);
            item->src += out->len;
        }
        item->rest = item->rest - out->len;
        out->len = 0xffff;
        item->headerDone = 1;
        return 1;
    }
    if (item->src == 0) {
        func_020364D4(ring, out->ptr, item->rest, item->rest);
    } else {
        MI_CpuCopy8(item->src, out->ptr, item->rest);
    }
    out->ptr += item->rest;
    out->len = out->len - item->rest;
    return 1;
}




/*
 * blocked:  own-pool - the only pooled words naming g_020A79D0 (0x020A79D0 "0")
 *           and g_020A79D4 (0x020A79D4 "(u16)size < (0xffff/2)") sit inside this
 *           function's own pool at 0x020369BC/0x020369C4; every other witness is
 *           inside 0x020368C0..0x020369C8, so the two ABS32 fields stay wildcarded.
 *           g_020A79C4 ("net_queue.c") does have 10 outside witnesses (literal class).
 *           Verified byte-correct otherwise: 264/264, 0 concrete bytes differ.
 */
int func_020368C0(Queue020368C0 *q, u16 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6)
{
    Node020368C0 *n = func_02036670(q, a1, a2, a3);

    if (n == 0) {
        func_02034714(g_020A79C4, 0xdb, g_020A79D0);
        return 0;
    }
    if (!((u16)a3 < 0xffff / 2)) {
        func_02034714(g_020A79C4, 0xdf, g_020A79D4);
    }
    if (a5 != 0) {
        if (!((int)(a3 + 5) < (int)func_0203660C(q->f14))) {
            func_02034714(g_020A79C4, 0xe3, g_020A79D0);
            return 0;
        }
        func_02036428(q->f14, a2, a3);
        func_0203666C(q->f14);
        n->f0 = 0;
    } else {
        n->f0 = a2;
    }
    n->fC = a3;
    n->fE = a1;
    n->f10 = a6;
    n->f11 = 0;
    if (q->f4 == 0) {
        q->f4 = n;
        q->f0 = n;
    } else {
        q->f4->f8 = n;
        n->f4 = q->f4;
        q->f4 = n;
    }
    return 1;
}




/*
 * First non-null of three words of a queue owner: the word at +0x10, then the
 * word at +0, then the word at +8.  The first two arms load into r1 and only
 * move the answer into r0 on the taken path (`movne r0, r1`); the third arm
 * loads straight into r0, so its null case is the single `moveq r0, #0` that
 * the source's trailing `return 0;` produces.  Both taken arms branch on the
 * compare itself (`bxne lr`) instead of jumping to the shared epilogue.
 *
 * Written with three separate `if (...) return ...;` statements rather than a
 * chain of `?:`: the compiler rejects the GNU `?:` extension outright
 * (CCERR), and the merged `if` chain (`if (a) return a; if (b) return b;
 * return c;`) is 36 bytes and folds the third test away.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020369C8.c \
 *       --func func_020369C8 --addr 0x020369C8 --cc 1.1p1 --arm
 */
u32 func_020369C8(u32 *p)
{
    if (p[4] != 0)
        return p[4];
    if (p[0] != 0)
        return p[0];
    if (p[2] != 0)
        return p[2];
    return 0;
}




/*
 *           the file string at 0x020A79C4 is not NUL-terminated immediately
 *           before this message, so the `string` class refuses. Every concrete
 *           byte of the body reproduces.
 */
void func_020369F8(u8 *p)
{
    if (((struct Obj11349 *)p)->f10 != 0) {
        ((struct Obj11349 *)p)->f10 = 0;
        return;
    }
    if (func_020366FC((u32 *)p) != 0) {
        return;
    }
    if (func_020366FC((u32 *)(p + 8)) != 0) {
        return;
    }
    func_02034714((char *)((const char *)str_020A79C4), 0x12f, (char *)((const char *)str_020A79EC));
}




/*
 *           unlabelled work not in the slice and itself only called from here)
 *           and func_020367C4 (pkt_020367C4, not this lane's).  Filing
 *           func_020369F8 would still leave func_020367C4 unwitnessed, so the
 *           park is capped either way.
 *
 * Byte-identical at 164 bytes; only the two PC24 call fields at +0x40 and
 * +0x54 stay wildcarded (func_020369C8 resolves `matched`, func_02082BCC
 * resolves `label x566`).
 *
 * Spellings that mattered: every `return 1` must be a `goto` to one label at
 * the END of the function -- plain `return`s make mwcc predicate all three of
 * them inline (`moveq r0,#1; popeq`) and the frame shifts by 25 bytes.  And
 * `flag = 1;` sits BEFORE the 0xFFFF test, which is why the original shows
 * `mov r8,r6` between the `ldrh` and the `cmp`.
 */
int func_02036A50(u32 list, u16 *info)
{
    int flag = 0;

    if (info[2] == 0)
        goto done;
    while (1) {
        int slot = func_020369C8((u32 *)list);

        if (slot == 0)
            goto done;
        func_020369F8((u8 *)list);
        if (func_020367C4((NetSendItem *)slot, (NetOutBuf *)info, (void *)(((struct Obj08825 *)list)->f14), flag) == 0) {
            ((struct Obj08825 *)list)->f10 = slot;
            goto done;
        }
        flag = 1;
        if (info[2] == 0xffff) {
            ((struct Obj08825 *)list)->f10 = slot;
            return 0;
        }
        func_02082BCC((void *)slot, 0, 0x14);
        if (info[2] == 0)
            break;
    }
done:
    return 1;
}



void func_02036AF4(u8 *p, u32 n, u32 a, u32 b)
{
    func_02082BCC(p, 0, 0x28);
    ((struct Obj08826 *)p)->f18 = (u32)func_02030734(b, n * 0x14, 1, (const char *)str_020A79C4, 0x173);
    ((struct Obj08826 *)p)->f1C = n;
    ((struct Obj08826 *)p)->f14 = a;
}
