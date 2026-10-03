/*
 * function: func_021BBA70
 * address:  0x021BBA70
 * packet:   pkt_ov021_021BBA70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BBC58  0x021BBC58  thumb  ov021
 *   func_021BBBD8  0x021BBBD8  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   func_020084F8  0x020084F8  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0201F41C  0x0201F41C  thumb
 *   func_02087C6C  0x02087C6C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0217F894  0x0217F894  thumb  ov019
 *   func_0200EDC4  0x0200EDC4  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u8 id[8];      /* 0x00 */
    u8 pad8[8];
    u16 v[4];      /* 0x10 */
    u16 h;         /* 0x18 */
    u8 key[6];     /* 0x1a */
    u8 flag;       /* 0x20 */
    u8 kind;       /* 0x21 */
    u8 rel;        /* 0x22 */
    u8 pad23;
} Entry;

typedef struct Ring {
    Entry e[30];
    u8 head;
    u8 tail;
    u8 pad2[2];
    int count;
    int mark;
} Ring;

typedef struct Src {
    u8 pad0[7];
    u8 kind : 3;   /* 0x07 */
    u8 flag : 1;
    u8 pad8[4];
    u8 id[8];      /* 0x0c */
    u8 pad14[8];
    u16 v[4];      /* 0x1c */
    u16 h;         /* 0x24 */
    u8 pad26[0x36];
    int x5c;       /* 0x5c */
    u8 pad60[4];
    u8 key[6];     /* 0x64 */
} Src;

typedef struct Sys {
    int a;
    u8 pad4[8];
    int c;
} Sys;

typedef struct Ctx {
    Sys *sys;
    u8 pad[0x30E0 - 4];
    Ring ring;
} Ctx;

extern void func_02034714(const char *expr, u32 line, const char *file);
int func_021BBC58(Ring *r, const void *b, u16 c);
Entry *func_021BBBD8(Ring *r);
void func_020084F8(int a, void *dst, int n);
int func_02008550(int a);
void func_0201F41C(const void *src, void *dst, int n);
void func_02087C6C(void *p);
void func_02082D44(const void *src, void *dst, int n);
int func_020120F4(int a);
int func_0201283C(int a);
int func_02012EBC(int a);
int func_0200ED48(int a);
int func_0217F894(int a, Src *s);
int func_0200EDC4(int a, int b);

void func_021BBA70(Ctx *ctx, Src *src, u16 *v, u8 kind)
{
    Ring *ring = &ctx->ring;
    Entry *e;
    int a;
    int t;
    int s;
    int r;

    if (src == 0 && v == 0) {
        func_02034714((void *)0x021DE308, 0, (void *)0x021DE308);
    }
    if (src != 0 && func_021BBC58(ring, src->key, src->h) == 0) {
        return;
    }
    e = func_021BBBD8(ring);
    if (src == 0) {
        a = ctx->sys->a;
        func_020084F8(a, e->id, 8);
        /* the re-test of v inside the v == 0 arm is the dead second bne */
        if (v == 0) {
            if (v != 0 || kind == 0) {
                func_02034714((void *)0x021DE308, 0, (void *)0x021DE308);
            }
        }
        e->v[0] = v[0];
        e->v[1] = v[1];
        e->v[2] = v[2];
        e->v[3] = v[3];
        e->kind = kind;
        e->h = 0;
        func_02087C6C(e->key);
        e->flag = func_02008550(a);
        e->rel = 0;
    } else {
        func_0201F41C(src->id, e->id, 8);
        e->v[0] = src->v[0];
        e->v[1] = src->v[1];
        e->v[2] = src->v[2];
        e->v[3] = src->v[3];
        e->kind = src->kind;
        e->h = src->h;
        func_02082D44(src->key, e->key, 6);
        e->flag = src->flag;
        t = func_020120F4(ctx->sys->c);
        s = func_0201283C(t);
        t = func_0200ED48(func_02012EBC(t));
        if (func_0217F894(s, src) == 1) {
            r = 1;
        } else if (func_0200EDC4(t, src->x5c) == 1) {
            r = 2;
        } else {
            r = 0;
        }
        e->rel = r;
    }
    if (ring->count == ring->mark) {
        ring->mark++;
    }
    ring->count++;
    if (ring->count - ring->mark >= 30) {
        ring->mark = ring->count - 29;
    }
}
