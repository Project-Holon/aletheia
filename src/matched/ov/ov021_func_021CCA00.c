/*
 * function: func_021CCA00
 * address:  0x021CCA00
 * packet:   pkt_ov021_021CCA00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021DB404     0x021DB404  data  a2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 x;
    u16 y;
    u16 f4;
    u16 f6;
} Pos;

typedef struct {
    u32 f0;
    void *f4;
    void *f8;
    u16 heap;
    u16 padE;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C[6];
    u32 f34[6];
    u32 pad4C[(0x7C - 0x4C) / 4];
    u16 f7C;
    u16 f7E;
    u16 f80[6];
    u16 f8C[6];
} Obj;

extern Pos d_021DB404;

extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u32 func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
struct Obj;
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B3DC(struct Obj *p, unsigned int v);

void func_021CCA00(Obj *p)
{
    Pos pos = d_021DB404;
    int n1;
    int n2;
    int i;
    void *mon;
    u32 s;
    u32 f;
    u32 e;
    u32 r;

    n1 = func_0201AA18(p->f4);
    for (i = 0; i < n1; i++) {
        pos.x = i * 0x28 + 0x18;
        p->f1C[i] = (u32)func_0204B294((void *)p->f18, p->f80[i], p->f7C, p->f7E, &pos, 0, p->heap);
        mon = func_0201AB28(p->f4, i);
        s = func_02017E1C(mon, 5, 0);
        f = func_02017E1C(mon, 0x6f, 0);
        e = (func_02017E1C(mon, 0xab, 0) == 0x28a) ? 1 : 0;
        r = func_0201BB5C(s, f, func_02017E1C(mon, 0x6e, 0), e);
        func_0204B6F4((struct Obj *)p->f1C[i], (u8)r, 1);
        func_0204B3DC((struct Obj *)p->f1C[i], 0);
    }
    if (p->f8 != 0) {
        n2 = func_0201AA18(p->f8);
        for (i = 0; i < n2; i++) {
            pos.x = i * 0x28 + 0x18;
            p->f34[i] = (u32)func_0204B294((void *)p->f18, p->f8C[i], p->f7C, p->f7E, &pos, 0, p->heap);
            mon = func_0201AB28(p->f8, i);
            s = func_02017E1C(mon, 5, 0);
            f = func_02017E1C(mon, 0x6f, 0);
            e = (func_02017E1C(mon, 0xab, 0) == 0x28a) ? 1 : 0;
            r = func_0201BB5C(s, f, func_02017E1C(mon, 0x6e, 0), e);
            func_0204B6F4((struct Obj *)p->f34[i], (u8)r, 1);
            func_0204B3DC((struct Obj *)p->f34[i], 0);
        }
    }
}
