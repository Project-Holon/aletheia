/*
 * function: func_021B8C0C
 * address:  0x021B8C0C
 * packet:   pkt_ov071_021B8C0C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Each window draw is a `static inline` whose `q->f8` local gets its own
 * spill slot per inlined copy (seven slots, 0x24 down to 0xc).
 *
 * symbols:
 *   MONOLITH_TOOL_GetTitleSpecies  0x021B6F2C  thumb  ov071
 *   MONOLITH_TOOL_GetSlotIconStates  0x021B6F40  thumb  ov071
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   _ll_sdiv       0x0209BE5C  arm
 *   TOWN_MAP_SPOT_CountVisited  0x0216FEAC  thumb  ov010
 *   STRBUF_Delete  0x02045808  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;

typedef struct {
    u8 pad[0xc];
    u16 n;
    u16 m;
} Counts;

typedef struct {
    char pad0[0x2c];
    int f2c;
    s64 f30;
    u8 f38[1];
} Save;

typedef struct {
    Save *f0;
} C;

typedef struct {
    char pad0[8];
    void *f8;
    void *fc;
    void *f10;
    char pad14[0x14];
    void *f28;
    char pad2c[8];
    void *f34;
} Q;

typedef struct {
    void *h[6];
    struct {
        void *h;
        u8 on;
    } e[6];
} P;

extern void *MONOLITH_TOOL_GetTitleSpecies(u8 **p);
extern void *MONOLITH_TOOL_GetSlotIconStates(u8 **p);
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct PrintSys;
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int TOWN_MAP_SPOT_CountVisited(void *, void *, u8 *);
extern void STRBUF_Delete(struct U16Vec *vec);

static inline void Draw(Q *q, void *h, u32 x, u32 y, void *buf)
{
    void *w = q->f8;
    PRINTSYS_PrintQue(w, (u32)BMP_WIN_GetBmp(h), x, y, buf, (u32)q->fc);
}

void func_021B8C0C(C *c, Q *q, P *d)
{
    Counts *x;
    s64 v;
    u32 hours;
    u32 min;
    void *s0;
    void *s1;

    MONOLITH_TOOL_GetTitleSpecies((u8 **)c);
    x = MONOLITH_TOOL_GetSlotIconStates((u8 **)c);
    s0 = STRBUF_Create(0x100, 0x61);
    s1 = STRBUF_Create(0x100, 0x61);

    MSGDATA_ReadString(q->f28, 0xd, s0);
    Draw(q, d->e[0].h, 0, 4, s0);
    d->e[0].on = 1;

    MSGDATA_ReadString(q->f28, 5, s0);
    func_0201EFA4(q->f10, 0, x->m + x->n, 5, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[1].h, 0, 0, s1);
    d->e[1].on = 1;

    MSGDATA_ReadString(q->f28, 9, s0);
    func_0201EFA4(q->f10, 0, x->m, 4, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[2].h, 0, 0, s1);
    d->e[2].on = 1;

    MSGDATA_ReadString(q->f28, 8, s0);
    func_0201EFA4(q->f10, 0, x->n, 4, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[2].h, 0x78, 0, s1);
    d->e[2].on = 1;

    v = c->f0->f30;
    hours = v / 60 / 60;
    if (hours > 999) {
        hours = 999;
        min = 59;
    } else {
        v -= hours * 3600;
        min = v / 60;
    }
    MSGDATA_ReadString(q->f28, 0xb, s0);
    func_0201EFA4(q->f10, 0, hours, 3, 1, 1);
    func_0201EFA4(q->f10, 1, min, 2, 2, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[3].h, 0, 0, s1);
    d->e[3].on = 1;

    MSGDATA_ReadString(q->f28, 0xc, s0);
    func_0201EFA4(q->f10, 0, c->f0->f2c, 5, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[4].h, 0, 0, s1);
    d->e[4].on = 1;

    MSGDATA_ReadString(q->f28, 0xa, s0);
    func_0201EFA4(q->f10, 0, TOWN_MAP_SPOT_CountVisited(q->f34, MONOLITH_TOOL_GetSlotIconStates((u8 **)c), c->f0->f38), 4, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[5].h, 0, 0, s1);
    d->e[5].on = 1;

    STRBUF_Delete(s0);
    STRBUF_Delete(s1);
}
