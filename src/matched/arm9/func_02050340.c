/*
 * function: func_02050340
 * address:  0x02050340
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   AREAMAN_Alloc  0x02033CA8  arm
 *   BILLBOARD_ACT_InitEntry  0x020500B8  arm
 *   BILLBOARD_AddElem  0x0204F428  arm
 *   func_0204F720  0x0204F720  arm
 *
 * billboard_act.c: take `count` consecutive entry indices from the pool at
 * +0x20 and build one board element per 0x24-byte descriptor through
 * BILLBOARD_AddElem, returning the first index (0xFFFF when the pool is full).
 * Levers, all measured: the descriptor array is `const` (its field loads
 * then move above the entry stores, 62 -> 15 bytes); the element id is a
 * named local passed on to func_0204F720 rather than re-read; the caller's
 * view of BILLBOARD_AddElem takes s16 v12/v14 (ldrsh, no narrowing); all five
 * locals at function scope in the order p, e, idx, i, r (loop-scoped e/p
 * swap the i and p registers).
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Vec3 { s32 a, b, c; };

struct BbActSlot { u16 id; u16 pad; u32 val; };

struct BbActEntry {
    u32   f00;
    u16   f04;
    u16   f06;
    u32   f08;
    u16   f0C;
    u16   f0E;
    u16   f10;
    u16   f12;
    u32   f14;
    u32   f18;
    u16   f1C;
    u16   f1E;
    u32   f20;
    u32   f24;
};

struct BbActDesc {          /* 0x24 bytes */
    u16 slot;               /* 0x00 */
    s16 v12;                /* 0x02 */
    s16 v14;                /* 0x04 */
    u8  k;                  /* 0x06 */
    u8  pad07;
    u32 flag;               /* 0x08 */
    u32 w;                  /* 0x0c */
    struct Vec3 pos;        /* 0x10 */
    u32 f1c;                /* 0x1c */
    u32 f20;                /* 0x20 */
};

struct BbActSys {
    u16 f00;
    u16 f02;
    void *f04;
    u32 f08;
    struct BbActSlot *f0C;
    u16 f10;
    u16 f12;
    void *f14;
    struct BbActEntry *f18;
    u16 f1C;
    u16 f1E;
    u32 f20;
};

struct AreaMan;
extern s32 AREAMAN_Alloc(struct AreaMan *p, u32 len);
extern void BILLBOARD_ACT_InitEntry(u32 *p);
extern s32  BILLBOARD_AddElem(void *board, u32 id, s16 v12, s16 v14, const struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void func_0204F720(void *p, u32 idx, u32 *flag);

u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode)
{
    const struct BbActDesc *p;
    struct BbActEntry *e;
    int idx;
    u32 i;
    s32 r;

    idx = AREAMAN_Alloc((struct AreaMan *)o->f20, count);
    if (idx == -1) {
        return 0xFFFF;
    }
    for (i = 0; i < count; i++) {
        e = &o->f18[idx + i];
        p = &d[i];

        BILLBOARD_ACT_InitEntry((u32 *)e);
        e->f04 = base + p->slot;
        r = BILLBOARD_AddElem(o->f04, o->f0C[e->f04].id, p->v12, p->v14, &p->pos, p->k, p->w, mode);
        e->f00 = r;
        e->f20 = p->f1c;
        e->f24 = p->f20;
        func_0204F720(o->f04, r, (u32 *)(&p->flag));
        e->f1C = 0x3FFF;
    }
    return idx;
}

