/*
 * function: func_02184D30
 * address:  0x02184D30
 * packet:   pkt_ov023_02184D30
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B800  0x0204B800  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   d_02186BEC     0x02186BEC  data  ov023  a2
 *
 * The three indexed runs must be struct array members (index on the base,
 * member offset after it); the extents of a60/a98 are padding to the next
 * member, not evidence. The unsigned 0x100000u keeps the `movs #1; lsls #20`
 * add apart from the `+ 0x20`: a plain int constant folds both into one
 * pool word.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct Pos {
    s16 x;
    s16 y;
    s16 z;
    u8 a;
    u8 b;
} Pos;

typedef struct Ent {
    u16 x;
    u16 y;
    u16 anim;
} Ent;

extern const Ent d_02186BEC[];

typedef struct Work {
    u8  pad00[0x38];
    u32 f38, f3C, f40, f44, f48, f4C, f50, f54, f58, f5C;
    u32 a60[14];
    u32 a98[14];
    u32 aD0[12];
    u32 f100;
} Work;

extern u32 func_0204B294(u32, u32, u32, u32, Pos *, u32, u32);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(u32, u16);
extern void func_0204B3DC(u32, int);
extern void func_0204B84C(u32, int);
extern void func_0204B800(u32, int);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);

void func_02184D30(Work *p)
{
    Pos pos;
    int i;
    int j;

    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    pos.a = 1;
    pos.b = 1;
    for (i = 0; i < 5; i++) {
        pos.x = i * 0x28 + 0x18;
        pos.y = 0x40;
        p->a60[i] = func_0204B294(p->f38, p->f40, p->f3C, p->f44, &pos, 0, 0x28);
        func_0204B92C((struct Obj *)p->a60[i], 1);
        func_0204B878(p->a60[i], i);
        func_0204B3DC(p->a60[i], 0);
    }
    for (j = 0; j < 12; j++) {
        pos.x = d_02186BEC[j].x;
        pos.y = d_02186BEC[j].y;
        p->aD0[j] = func_0204B294(p->f38, p->f40, p->f3C, p->f44, &pos, 0, 0x28);
        func_0204B92C((struct Obj *)p->aD0[j], 1);
        func_0204B878(p->aD0[j], d_02186BEC[j].anim);
        if (j >= 8) {
            func_0204B84C(p->aD0[j], 2);
        }
    }
    func_0204B878(p->aD0[0], 6);
    for (i = 0; i < 5; i++) {
        pos.x = 0x18;
        pos.y = i * 0x20 + 0x20 + 0x100000u;
        p->a98[i] = func_0204B294(p->f38, p->f58, p->f54, p->f5C, &pos, 1, 0x28);
        func_0204B92C((struct Obj *)p->a98[i], 1);
        func_0204B878(p->a98[i], i);
        func_0204B800(p->a98[i], 1);
        func_0204B3DC(p->a98[i], 0);
    }
    pos.x = 0xD4;
    pos.y = 0xA0;
    p->f100 = func_0204B294(p->f38, p->f4C, p->f48, p->f50, &pos, 0, 0x28);
    func_0204B92C((struct Obj *)p->f100, 1);
    func_0204B878(p->f100, 1);
    func_0204B3DC(p->f100, 1);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}
