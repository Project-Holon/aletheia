/*
 * function: func_020169E8
 * address:  0x020169E8
 * packet:   pkt_020169E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_020A72CC  0x020A72CC  data
 *   func_0201691C  0x0201691C  thumb
 *
 * Closed in the second pass (2026-09-22) from the 4-byte near miss in
 * docs/notes/func_020169E8.c.txt.  The residue was NOT the pool-word
 * shape that note predicted; it was two misreadings of the image:
 *
 *   1. the flag mask is 0xFFFFEFFF (bit 12), not 0xEFFFFFFF (bit 28).
 *      The pool word at 0x02016B94 is `ff ef ff ff`.  Fixing it alone
 *      took the diff from 4 concrete bytes to 2.
 *   2. the second clamp reads +0x135 / +0x134, not +0x137 / +0x136.
 *      The `ldr r0,[pc,#0x3c]` at 0x02016B58 resolves to 0x02016B98,
 *      the SECOND pool word (0x135), while the `ldr r0,[pc,#0x30]` at
 *      0x02016B6A resolves to 0x02016B9C, the THIRD (0x137).  Reading
 *      both as 0x137 is what made the 0x135 pool word disappear and the
 *      function come out 436 bytes instead of 440.  The missing pool
 *      word was a symptom, not the cause.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020169E8.c \
 *       --func func_020169E8 --addr 0x020169E8 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed int     s32;

struct Obj_0201691C;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02021F64(void *a, void *b, u16 c, u8 d, u16 e);
extern int func_02016C38(int a0);
extern void *func_02030DA8(void *a0, void *callback, void *ctx, int a3);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_0201691C(void *a0, struct Obj_0201691C *a1);

extern char data_020A72CC[];

struct Inner {
    u32 f00;
    u32 f04;
    u32 f08;
    void *f0c;
};

struct Obj {
    u8 pad00[4];
    struct Inner *f04;
    u8 pad08[4];
    void *f0c;
    u8 pad10[0xc];
    u32 f1c;
    void *f20;
    void *f24;
    u32 f28;
};

void func_020169E8(u8 *a0, u8 *a1)
{
    struct Obj *p;
    u32 flag;
    void *ret;
    s32 step;
    s8 cur;
    s8 tgt;

    if (*(s8 *)(a1 + 0x136) != 0) {
        goto dec;
    }

    flag = 1;
    p = (struct Obj *)func_02030734((u16)(((u16)*(u32 *)(a1 + 0x14C) & 0x7FFF) | 0x8000), 0x2C, 1, data_020A72CC, 0x9A1);
    p->f20 = a0;
    if (*(void **)(a0 + 8) == 0) {
        flag = 0;
    }
    p->f28 = flag;
    p->f24 = a1;
    p->f0c = a1 + 0xC0;
    p->f1c = *(u32 *)(a0 + 0x34) + (*(u32 *)(a1 + 0x148) << 5);

    flag = 0;
    p->f04 = (struct Inner *)func_02030734((u16)(((u16)*(u32 *)(a1 + 0x14C) & 0x7FFF) | 0x8000), 0x10, 0, data_020A72CC, 0x9A9);
    p->f04->f00 = *(u32 *)(a1 + 0xC0);
    p->f04->f04 = flag;
    p->f04->f08 = *(u32 *)(a1 + 0xDC);
    p->f04->f0c = func_02030734((u16)(((u16)*(u32 *)(a1 + 0x14C) & 0x7FFF) | 0x8000), *(u32 *)(a1 + 0xDC), 0, data_020A72CC, 0x9A9 + 5);

    if ((*(u32 *)(a1 + 0x140) << 3) >> 0x1F) {
        func_02021F64(*(void **)(a1 + 0xD8), p->f04->f0c,
                      ((s32)*(u32 *)(a1 + 0xDC) / 2),
                      *(u8 *)(a1 + 0x134), (u16)*(u32 *)(a1 + 0x13C));
    } else {
        func_02021F64(*(void **)(a1 + 0xD4), p->f04->f0c,
                      ((s32)*(u32 *)(a1 + 0xDC) / 2),
                      *(u8 *)(a1 + 0x134), (u16)*(u32 *)(a1 + 0x13C));
    }

    if (*(void **)(a1 + 4) != 0) {
        func_02016C38((int)(*(void **)(a1 + 4)));
        *(void **)(a1 + 4) = 0;
    }

    if (*(void **)(a0 + 8) != 0) {
        ret = func_02030DA8(*(void **)(a0 + 8), func_0201691C, p, 0);
    } else {
        ret = func_020056A0(func_0201691C, p, 0);
    }
    *(void **)(a1 + 4) = ret;

    cur = *(s8 *)(a1 + 0x134);
    tgt = *(s8 *)(a1 + 0x135);
    if (cur == tgt) {
        *(u32 *)(a1 + 0x140) &= 0xFFFFEFFF;
    } else {
        step = *(s32 *)(a1 + 0x138);
        *(s8 *)(a1 + 0x134) = (s8)(cur + (s8)step);
        if (step < 0 || *(s8 *)(a1 + 0x134) < tgt) {
            if (step < 0) {
                tgt = *(s8 *)(a1 + 0x135);
                if (*(s8 *)(a1 + 0x134) > tgt) {
                    goto done;
                }
            } else {
                goto done;
            }
        }
        *(s8 *)(a1 + 0x134) = tgt;
    }
done:
    *(s8 *)(a1 + 0x136) = *(s8 *)(a1 + 0x137);
    return;
dec:
    *(s8 *)(a1 + 0x136) = *(s8 *)(a1 + 0x136) - 1;
}

