/*
 * file:     btlv_effvm_p73.c
 * unit:     yes
 * function: func_02200A50, func_02200A84, func_02200B10, func_02200B48, func_02200BD4, func_02200C0C, func_02200C98, func_02200CD0
 * address:  0x02200A50
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030EE8  0x02030EE8  arm
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_02015C94  0x02015C94  thumb
 *   func_02015CAC  0x02015CAC  thumb
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_02015D4C  0x02015D4C  thumb
 *   func_02015D64  0x02015D64  thumb
 *   func_02015CF8  0x02015CF8  thumb
 *   func_02015D14  0x02015D14  thumb
 *   func_021FF260  0x021FF260  thumb  ov094
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 */
struct S02030EE8;
typedef unsigned char u8;

typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x518 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x518 */
    char pad51c[0x550 - 0x51c];
    u8 tag[1];              /* 0x550 */
} Work_02200A50;

typedef struct {
    char body[0x3c];
} Mover;

typedef struct {
    Work_02200A50 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200A50;

typedef unsigned int   u32;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x55e - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x55e */
} Work_02200A84;

typedef struct {
    Work_02200A84 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200A84;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x520 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x520 */
    char pad524[0x55e - 0x524];
    u8 tag[1];              /* 0x55e */
} Work_02200B10;

typedef struct {
    Work_02200B10 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200B10;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x56c - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x56c */
} Work_02200B48;

typedef struct {
    Work_02200B48 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200B48;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x524 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x524 */
    char pad528[0x56c - 0x528];
    u8 tag[1];              /* 0x56c */
} Work_02200BD4;

typedef struct {
    Work_02200BD4 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200BD4;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x57a - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x57a */
} Work_02200C0C;

typedef struct {
    Work_02200C0C *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200C0C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x51c - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x51c */
    char pad520[0x57a - 0x520];
    u8 tag[1];              /* 0x57a */
} Work_02200C98;

typedef struct {
    Work_02200C98 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200C98;

typedef struct {
    char pad000[0x588];
    u8 tag[1];              /* 0x588 */
} Work_02200CD0;

typedef struct {
    Work_02200CD0 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x3c];
    int wait;               /* 0x44 */
    int reload;             /* 0x48 */
    int count;              /* 0x4c */
    int tag;                /* 0x50 */
} Ctx_02200CD0;

extern u32 func_02030EE8(struct S02030EE8 *p);
extern int func_021F935C(int x);
extern void func_02015C94(void *p, u32 *out);
extern void func_02015CAC(void *p, u32 *src);
extern void func_021F89BC(void *h);
extern int func_021F9260(Mover *m, VecFx32 *out);
extern int func_022019F4(char *p, int key);
extern void func_02015D4C(void *p, u32 *out);
extern void func_02015D64(void *p, u32 *src);
extern void func_02015CF8(void *p, u32 *out);
extern void func_02015D14(void *p, u32 *src);
extern int func_021FFD9C(char *p, int key);
extern void func_021FF260(Work_02200CD0 *w, int key, int kind);
void func_02200A50(void *h);
void func_02200A84(void *h, Ctx_02200A84 *c);
void func_02200B10(void *h);
void func_02200B48(void *h, Ctx_02200B48 *c);
void func_02200BD4(void *h);
void func_02200C0C(void *h, Ctx_02200C0C *c);
void func_02200C98(void *h);
void func_02200CD0(void *h, Ctx_02200CD0 *c);


void func_02200A50(void *h)
{
    Ctx_02200A50 *c = (Ctx_02200A50 *)func_02030EE8(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}


/*
 * Task callback passed by func_021FF630.
 */
void func_02200A84(void *h, Ctx_02200A84 *c)
{
    Work_02200A84 *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    func_02015C94(w->e[i].h, (u32 *)(&v));
    r = func_021F9260(&c->mv, &v);
    func_02015CAC(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}


/*
 * Task destructor passed by func_021FF630.
 */
void func_02200B10(void *h)
{
    Ctx_02200B10 *c = (Ctx_02200B10 *)func_02030EE8(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}


/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * MATCH: bytes identical; blocked on two unfiled ARM9 Thumb leaves (Ilias's),
 * no witness outside this range. Verified C, each EXACT with `one --thumb`
 * and no --region (cc 1.1p1, -O4,p), packets pkt_02015D4C / pkt_02015D64:
 *
 *   typedef unsigned int u32;
 *   void func_02015D4C(void *p, u32 *out)   // 0x02015D4C, 64 B extent
 *   {
 *       out[0] = *(u32 *)((char *)p + 0x110);
 *       out[1] = *(u32 *)((char *)p + 0x114);
 *       out[2] = *(u32 *)((char *)p + 0x118);
 *   }
 *   void func_02015D64(void *p, u32 *src)  // 0x02015D64, inverse
 *   {
 *       *(u32 *)((char *)p + 0x110) = src[0];
 *       *(u32 *)((char *)p + 0x114) = src[1];
 *       *(u32 *)((char *)p + 0x118) = src[2];
 *   }
 *
 * Task callback, twin of func_02200A84.
 */
void func_02200B48(void *h, Ctx_02200B48 *c)
{
    Work_02200B48 *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    func_02015D4C(w->e[i].h, (u32 *)(&v));
    r = func_021F9260(&c->mv, &v);
    func_02015D64(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}


void func_02200BD4(void *h)
{
    Ctx_02200BD4 *c = (Ctx_02200BD4 *)func_02030EE8(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}


void func_02200C0C(void *h, Ctx_02200C0C *c)
{
    Work_02200C0C *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    func_02015CF8(w->e[i].h, (u32 *)(&v));
    r = func_021F9260(&c->mv, &v);
    func_02015D14(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}


void func_02200C98(void *h)
{
    Ctx_02200C98 *c = (Ctx_02200C98 *)func_02030EE8(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}


/*
 * Task callback.
 */
void func_02200CD0(void *h, Ctx_02200CD0 *c)
{
    Work_02200CD0 *w = c->w;

    if (func_021FFD9C((char *)w, c->key) == 0 || c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    if (c->wait == 0) {
        c->wait = c->reload;
        func_021FF260(c->w, c->key, 2);
        if (--c->count == 0) {
            func_021FF260(c->w, c->key, 0);
            func_021F89BC(h);
        }
    } else {
        c->wait--;
    }
}
