/*
 * function: func_021BB534
 * address: 0x021BB534
 * packet: pkt_ov206_021BB534
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020275E8 0x020275E8 thumb
 *   func_020275EC 0x020275EC thumb
 *   func_020275F8 0x020275F8 thumb
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 */
typedef enum { B_FALSE, B_TRUE } Bool;

typedef struct {
    short a, b, c;
    unsigned char d, e;
} Rect;

typedef struct {
    short x, y;
} Pos;

typedef struct {
    short x, y, z, w;
} Rect4;

typedef signed int     s32;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Actor;
struct Node;
struct Obj;
extern u32 func_020275E8(void);
extern u8 func_020275EC(int i);
extern u32 func_020275F8(u32 a);
extern u32 func_020275FC(u32 a);
extern u32 func_02027600(u32 a);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B404(void *, Pos *, unsigned short);

typedef struct {
    unsigned short f0;
    char pad02[0x18 - 2];
    int f18;
    int f1c;
    char pad20[4];
    void *f24;
    char pad28[0xb8 - 0x28];
    int m[2][2];
    void *fc8;
    void *fcc;
    void *n[2][2];
    int fe0;
    int fe4;
    void *a[0x11];
    void *b[0x11];
    unsigned char f170;
    unsigned char f171;
    char pad172[0x1b4 - 0x172];
    int f1b4;
    char pad1b8[0x1d0 - 0x1b8];
    void *f1d0;
} Ent;

void func_021BB534(Ent *p, unsigned x, unsigned y, int row)
{
    Rect4 rr[2];
    Pos pos[2];
    unsigned char sel[2];
    int ifv;
    int tern;
    short v;
    int j;
    void *arc;
    short *zp;

    if (p->fe4 != 0) {
        ifv = 0;
        if (p->f1c != 0) ifv = 1;
        pos[0].x = 0xa8;
        v = p->f1b4 + 0x54;
        pos[0].y = v;
        pos[1].x = 0xd0;
        pos[1].y = v;
        if (p->f170 != 0x11) {
            if (p->f170 != x && p->f170 != y) {
                func_0204B3DC(p->b[p->f170], 0);
                p->f170 = 0x11;
            } else {
                if (p->f170 == y) {
                    func_0204B404(p->b[p->f170], &pos[1], ifv);
                }
                func_0204B3DC(p->b[p->f170], 1);
            }
        }
        if (p->f171 != 0x11) {
            if (p->f171 != x && p->f171 != y) {
                func_0204B3DC(p->b[p->f171], 0);
                p->f171 = 0x11;
            } else {
                if (p->f171 == x) {
                    func_0204B404(p->b[p->f171], &pos[0], ifv);
                }
                func_0204B3DC(p->b[p->f171], 1);
            }
        }
        if (x != 0x11) {
            p->f170 = x;
            func_0204B3DC(p->b[p->f170], 1);
            func_0204B404(p->b[p->f170], &pos[0], ifv);
        }
        if (y != 0x11) {
            p->f171 = y;
            func_0204B3DC(p->b[p->f171], 1);
            func_0204B404(p->b[p->f171], &pos[1], ifv);
        }
    } else {
        zp = (short *)rr;
        zp[0] = 0;
        zp[1] = 0;
        zp[2] = 0;
        zp[3] = 0;
        zp[4] = 0;
        zp[5] = 0;
        zp[6] = 0;
        zp[7] = 0;
        ifv = 0;
        if (p->f1c != 0) ifv = 1;
        tern = p->f1c == 0 ? B_FALSE : B_TRUE;
        sel[0] = x;
        sel[1] = y;
        rr[0].x = 0xa8;
        v = p->f1b4 + 0x54;
        rr[0].y = v;
        rr[1].x = 0xd0;
        rr[1].y = v;
        arc = p->f1d0;
        for (j = 0; j < 2; j++) {
            p->m[row][j] = -1;
            if (sel[j] != 0x11) {
                p->m[row][j] = (int)func_0204A6C8(arc, func_020275F8(sel[j]), 0, ifv, p->f0);
            }
        }
        for (j = 0; j < 2; j++) {
            if (p->m[row][j] != -1) {
                p->n[row][j] = func_0204B294(p->f24, p->m[row][j], (unsigned int)p->fc8, (unsigned int)p->fcc, &rr[j], (unsigned short)tern, p->f0);
                func_0204B6F4(p->n[row][j], func_020275EC(sel[j]), 1);
                CLACT_SetActorDrawPriority(p->n[row][j], 2);
                func_0204B688(p->n[row][j], 1);
            }
        }
    }
}
