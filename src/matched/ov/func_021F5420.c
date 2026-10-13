/*
 * function: func_021F5420
 * address:  0x021F5420
 * packet:   pkt_021F5420
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_StopActorAnim  0x0204B974  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021F4EA0  0x021F4EA0  thumb
 *   tbl_02202D24   0x02202D24  data  a2
 *   tbl_02202C50   0x02202C50  data  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u8 pad10[0x18];
    u32 f28;
    u32 f2C;
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3C;
    u32 arrA[30];
    u32 arrB[30];
} Sub;

typedef struct {
    u8 pad0[0xC6];
    u16 idx;
    u8 padC8[0xBC0 - 0xC8];
    Sub sub;
    u32 arrC[6];
    u8 padD08[0xD2C - 0xD08];
    u32 arrD[2];
    u32 fD34;
    u32 fD38;
} Work;

extern const Pos tbl_02202D24[];
extern const Pos tbl_02202C50[];

extern void func_02082BCC(void *, int, int);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Obj;
extern void func_0204B92C(struct Obj *, u32);
struct Actor;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void CLACT_SetActorBgPriority(u32, int);
extern void CLACT_StopActorAnim(struct Actor *a);
extern void func_021F4EA0(u32, u16, u16);

void func_021F5420(Work *p)
{
    Local s;
    int i;

    func_02082BCC(&s, 0, 8);
    s.a = tbl_02202D24[p->idx].x;
    s.b = tbl_02202D24[p->idx].y;
    p->sub.f34 = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
    func_0204B92C((struct Obj *)p->sub.f34, 1);
    CLACT_SetActorAnimSeq((struct Obj *)p->sub.f34, 4);
    if (func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->sub.f34, 0);
    } else {
        func_0204B3DC((struct Obj *)p->sub.f34, 1);
    }
    if (p->idx == 0x1f || p->idx <= 5) {
        CLACT_SetActorBgPriority(p->sub.f34, 0);
    } else {
        CLACT_SetActorBgPriority(p->sub.f34, 1);
    }

    for (i = 0; i < 30; i++) {
        s.a = tbl_02202D24[i].x;
        s.b = tbl_02202D24[i].y;
        s.d = 30 - i % 6;
        p->sub.arrA[i] = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        CLACT_SetActorAnimSeq((struct Obj *)p->sub.arrA[i], i + 6);
        CLACT_SetActorBgPriority(p->sub.arrA[i], 1);
    }

    for (i = 0; i < 30; i++) {
        s.a = tbl_02202D24[i].x;
        s.b = tbl_02202D24[i].y + 6;
        s.d = 10;
        p->sub.arrB[i] = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        CLACT_SetActorAnimSeq((struct Obj *)p->sub.arrB[i], 0x28);
        CLACT_SetActorBgPriority(p->sub.arrB[i], 1);
    }

    for (i = 0; i < 6; i++) {
        s.a = tbl_02202D24[i].x + 8;
        s.b = tbl_02202D24[i].y + 6;
        s.d = 10;
        p->arrC[i] = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        CLACT_SetActorAnimSeq((struct Obj *)p->arrC[i], 0x2a);
        CLACT_SetActorBgPriority(p->arrC[i], 1);
    }

    for (i = 0; i < 2; i++) {
        s.a = tbl_02202C50[i].x;
        s.b = tbl_02202C50[i].y;
        p->arrD[i] = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        CLACT_SetActorAnimSeq((struct Obj *)p->arrD[i], i + 0x26);
        CLACT_SetActorBgPriority(p->arrD[i], 1);
    }

    s.a = 0xef;
    s.b = 0x88;
    s.d = 100;
    s.e = 1;
    p->sub.f3C = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f28, p->sub.f8, p->sub.f30, &s, 0, 0x48);
    CLACT_SetActorAnimSeq((struct Obj *)p->sub.f3C, 0xc);
    func_0204B92C((struct Obj *)p->sub.f3C, 1);
    CLACT_StopActorAnim((struct Actor *)p->sub.f3C);
    func_0204B3DC((struct Obj *)p->sub.f3C, 0);
    func_0204B3DC((struct Obj *)p->fD38, 1);
    func_021F4EA0(p->fD38, 0x37, 0xa8);
}
