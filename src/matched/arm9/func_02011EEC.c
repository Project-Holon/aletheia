/*
 * function: GAMESYSTEM_SetupInitWork
 * address:  0x02011EEC
 * packet:   pkt_02011EC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _GameSystemGlobal        0x02146248  data
 *   func_02082BCC     0x02082BCC  arm
 *
 * The object at 0x02146248, seen through its +0x08 field: the pool words are
 * 0x02146250 (the address of +0x08, used both for the 0x14-byte clear and
 * for the return value), 0x02146248 and 0x02146254 (= +0x0C, the destination
 * of the twelve-byte record copy).  So the struct is
 * `{ pad[8]; u32 f8; Rec12 rec; u16 f18; u16 f1a; }` and the function
 * clears +0x08..+0x1C, stores two scalars, copies the record in and stores
 * one more scalar.
 *
 * The scalar store to +0x08 goes through the +0x08 pointer, the two
 * halfwords go through the +0x00 base, and the copy is one twelve-byte
 * aggregate assignment (the ldm/stm pair plus the third word).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_SetupInitWork.c \
 *       --func GAMESYSTEM_SetupInitWork --addr 0x02011EEC --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec12 {
    u32 a;
    u32 b;
    u32 c;
};

struct S02146248 {
    u8  pad0[8];
    u32 f8;         /* +0x08 */
    struct Rec12 rec;   /* +0x0C */
    u16 f18;        /* +0x18 */
    u16 f1a;        /* +0x1A */
};

extern struct S02146248 _GameSystemGlobal;
extern void func_02082BCC(void *dst, u32 val, u32 size);

void *GAMESYSTEM_SetupInitWork(u32 a0, u16 a1, struct Rec12 *a2, int a3)
{
    func_02082BCC(&_GameSystemGlobal.f8, 0, 0x14);
    _GameSystemGlobal.f8 = a0;
    _GameSystemGlobal.f18 = a1;
    _GameSystemGlobal.rec = *a2;
    _GameSystemGlobal.f1a = a3;
    return &_GameSystemGlobal.f8;
}
