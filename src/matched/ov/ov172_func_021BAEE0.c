/*
 * function: func_021BAEE0
 * address:  0x021BAEE0
 * packet:   pkt_ov172_021BAEE0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035C08  0x02035C08  arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021BB54C  0x021BB54C  thumb  ov172
 *   func_021BE0B8  0x021BE0B8  thumb  ov172
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B404  0x0204B404  arm
 *   func_020362DC  0x020362DC  arm
 *   func_021BB65C  0x021BB65C  thumb  ov172
 *   func_021BB9E4  0x021BB9E4  thumb  ov172
 *   func_0204B98C  0x0204B98C  arm
 *   d_021C6FF8     0x021C6FF8  data
 *   d_021C7014     0x021C7014  data
 *   d_021C6FBC     0x021C6FBC  data
 *   d_021C7030     0x021C7030  data
 *   d_021C6FDC     0x021C6FDC  data
 *   d_021C6FC8     0x021C6FC8  data
 *   d_021C7034     0x021C7034  data
 *   d_021C7038     0x021C7038  data
 *   d_021C703C     0x021C703C  data
 */

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned long u32;

struct SpritePos {
    s16 x;
    s16 y;
};

extern int func_02035C08(const void *p);
struct Actor;
struct Obj;
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_020061E4(u32 id);
extern void func_021BB54C(void *ctx, u8 *p);
extern void func_021BE0B8(void *ctx);
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B404(void *spr, struct SpritePos *pos, int n);
extern u32 func_020362DC(void);
extern void func_021BB65C(void *ctx, u8 *p, int v);
extern void func_021BB9E4(void *ctx, u8 *p);
extern u32 func_0204B98C(struct Actor *a);
extern const u8 d_021C6FF8[];
extern const u8 d_021C7014[];
extern const u32 d_021C6FBC[];
extern const struct SpritePos d_021C7030;
extern const u8 d_021C6FDC[];
extern const u32 d_021C6FC8[];
extern const struct SpritePos d_021C7034;
extern const struct SpritePos d_021C7038;
extern const struct SpritePos d_021C703C;

void func_021BAEE0(void *ctx, u8 *p)
{
    struct SpritePos pa;
    struct SpritePos pb;
    struct SpritePos pc;
    struct SpritePos pd;
    int k;
    int j;

    k = func_02035C08(d_021C6FF8);
    if (k == 0 && func_0204B3F4(*(void **)(p + 0x8c)) == 0) {
        *(int *)(p + 0x28) = 0;
        *(int *)(p + 0x24) = 0;
        func_021BB54C(ctx, p);
        *(int *)(p + 8) = 1;
        *(int *)(p + 0x10) = 1;
        func_0204B3DC(*(void **)(p + 0x84), 1);
        func_0204B92C(*(void **)(p + 0x84), 1);
        func_020061E4(0x66c);
    }
    if (k == 1) {
        *(int *)(p + 0x28) = 1;
        func_021BB54C(ctx, p);
        *(int *)(p + 8) = 1;
        func_020061E4(0x66c);
    }
    if (k == 2) {
        *(int *)(p + 0x28) = 2;
        func_021BB54C(ctx, p);
        *(int *)(p + 8) = 1;
        func_020061E4(0x66c);
    }
    if (k == 3 && func_0204B3F4(*(void **)(p + 0x8c)) == 0) {
        *(int *)(p + 0x28) = 3;
        *(int *)(p + 0x24) = 1;
        func_021BB54C(ctx, p);
        *(int *)(p + 8) = 1;
        *(int *)(p + 0x14) = 1;
        func_0204B3DC(*(void **)(p + 0x88), 1);
        func_0204B92C(*(void **)(p + 0x88), 1);
        func_020061E4(0x66c);
    }
    if (k == 4) {
        func_021BE0B8(ctx);
        func_021BB54C(ctx, p);
        *(int *)(p + 8) = 1;
        func_020061E4(0x66f);
    }
    if (*(int *)(p + 0x10) == 1) {
        j = func_02035C08(d_021C7014);
        if (j != -1) {
            p[0x36] = d_021C6FBC[j];
            *(int *)(p + 8) = 1;
            pa = d_021C7030;
            func_0204B3DC(*(void **)(p + 0x8c), 1);
            func_0204B9A0(*(void **)(p + 0x8c));
            func_0204B92C(*(void **)(p + 0x8c), 1);
            func_0204B878(*(void **)(p + 0x8c), (u16)(j + 0x11));
            func_0204B404(*(void **)(p + 0x8c), &pa, 0);
            func_0204B3DC(*(void **)(p + 0x90), 0);
            func_020061E4(0x66c);
        }
    }
    if (*(int *)(p + 0x14) == 1) {
        j = func_02035C08(d_021C6FDC);
        if (j != -1) {
            p[0x37] = d_021C6FC8[j];
            *(int *)(p + 8) = 1;
            func_020061E4(0x66c);
            pb = d_021C7034;
            func_0204B3DC(*(void **)(p + 0x8c), 1);
            func_0204B9A0(*(void **)(p + 0x8c));
            func_0204B92C(*(void **)(p + 0x8c), 1);
            func_0204B878(*(void **)(p + 0x8c), (u16)(j + 0x14));
            func_0204B404(*(void **)(p + 0x8c), &pb, 0);
            func_0204B3DC(*(void **)(p + 0x90), 0);
        }
    }
    if ((func_020362DC() & 0x400) || (func_020362DC() & 2) || k == 5) {
        if (*(int *)(p + 0x38) == 0) {
            *(int *)p = 4;
            p[4] = 0x18;
            *(int *)(p + 8) = 1;
            func_021BB65C(ctx, p, 0);
            func_021BB9E4(ctx, p);
            func_020061E4(0x551);
            func_0204B878(*(void **)(p + 0x6c), 9);
        }
    }
    if (func_020362DC() & 0xc) {
        func_021BE0B8(ctx);
        func_021BB54C(ctx, p);
        func_020061E4(0x66f);
    }
    if (func_0204B3F4(*(void **)(p + 0x8c)) == 1 && func_0204B98C(*(void **)(p + 0x8c)) == 0) {
        func_021BB9E4(ctx, p);
    }
    if (*(int *)(p + 0x10) == 1 && func_0204B98C(*(void **)(p + 0x84)) == 0 && func_0204B3F4(*(void **)(p + 0x90)) == 0) {
        pc = d_021C7038;
        switch (p[0x36]) {
        case 1:
            pc.x = pc.x + 0x10;
            break;
        case 0:
            pc.x = pc.x + 0x20;
            break;
        case 2:
            break;
        }
        func_0204B404(*(void **)(p + 0x90), &pc, 0);
        func_0204B3DC(*(void **)(p + 0x90), 1);
    }
    if (*(int *)(p + 0x14) == 1 && func_0204B98C(*(void **)(p + 0x88)) == 0 && func_0204B3F4(*(void **)(p + 0x90)) == 0) {
        pd = d_021C703C;
        switch (p[0x37]) {
        case 3:
            pd.x = pd.x - 0x20;
            break;
        case 4:
            pd.x = pd.x - 0x10;
            break;
        case 6:
            pd.x = pd.x + 0x10;
            break;
        case 7:
            pd.x = pd.x + 0x20;
            break;
        }
        func_0204B404(*(void **)(p + 0x90), &pd, 0);
        func_0204B3DC(*(void **)(p + 0x90), 1);
    }
}
