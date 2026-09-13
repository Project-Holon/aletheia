/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008700
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02008700, sub_02008704, sub_02008730, sub_0200873C,
 *           sub_02008748, sub_02008754, sub_02008764, sub_02008774,
 *           sub_02008784, sub_020087A8, sub_020087C0, sub_020087D4,
 *           sub_020087E8, sub_02008808
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 *   sub_02008320    0x02008320  thumb
 *   sub_020084A0    0x020084A0  thumb
 *   sub_020085A0    0x020085A0  thumb
 *   sub_020071CC    0x020071CC  thumb
 *
 * alias: a save block and its accessors.  The unit is bounded on both sides by
 * the "how big is my block" function each of these files opens with:
 * sub_02008700 returns 0x68, which is exactly what sub_02008704 clears, and
 * the four bytes at 0x02008828 are the same two instructions returning 0x9C,
 * which is what the function after them clears.  So the range is
 * 0x02008700..0x02008828, 296 bytes and fourteen functions, closed at both
 * ends by that shape.
 *
 * Every accessor here reaches its object the same way: sub_020071CC(sys, 0x1B).
 * 0x1B is this block's id, and the call is the only thing the fourteen
 * functions have in common, which is what says they are one file.  The three
 * sub-objects sub_02008704 initialises identify the layout:
 *
 *   +0x00  4 bytes   initialised by sub_02008320
 *   +0x04  0x20      the accessor object of unit_0200852C.c, initialised by
 *                    sub_020084A0, which is the function immediately before
 *                    unit_020084BC.c and calls sub_02008560 out of it
 *   +0x24  8 bytes   the playtime object of unit_020085A0.c
 *   +0x2C  u8        a flag, set by sub_02008764 and cleared by sub_02008774
 *   +0x30  u16[10]   a table of marks, each either 0 or 0xC21E
 *   +0x44  u32[9]    a table sub_020087D4 hands out addresses into
 *                    (0x44 + 9 * 4 = 0x68, which closes the object)
 *
 * Two shapes in here are worth naming:
 *
 *  - sub_020087E8 and sub_02008808 copy the 0x20-byte sub-object in and out
 *    with four ldm/stm pairs and no call.  That is a plain struct assignment:
 *    mwccarm inlines an aggregate copy of this size rather than calling a
 *    memcpy, and it uses the padded sizeof (0x20) rather than the 0x1E bytes
 *    of declared members.
 *  - sub_0200873C is a tail call through a pool word with the second argument
 *    set up first (`ldr r3, =sub_020071CC+1; movs r1, #0x1B; bx r3`), which is
 *    what `return sub_020071CC(sys, 0x1B);` compiles to when nothing follows
 *    the call.  Its neighbours all do something to the result and therefore
 *    keep a real frame.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008700.c \
 *       --addr 0x02008700 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MIi_CpuClear32(u32 data, void *dest, u32 size);

/* The three sub-object constructors, each in a file of its own. */
extern void sub_02008320(void *p);
extern void sub_020084A0(void *p);
extern void sub_020085A0(void *p);

/* Save-block lookup: returns the block with the given id. */
extern void *sub_020071CC(void *sys, u32 id);

#define BLOCK_ID 0x1B

struct Sub0200852CObj {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u8  unk18;
    u8  unk19;
    u8  unk1A;
    u8  unk1B;
    u8  unk1C;
    u8  unk1D;
};

struct PlayTime {
    u16 hours;
    u8  minutes;
    u8  seconds;
    u32 stamp;
};

struct Sub02008700Obj {
    u32 unk00;
    struct Sub0200852CObj unk04;
    struct PlayTime unk24;
    u8  unk2C;
    u8  unk2D[3];
    u16 unk30[10];
    u32 unk44[9];
};

/* The carrier the 0x20-byte sub-object is copied to and from. */
struct Sub020087E8Arg {
    u8 unk00[0x20];
    struct Sub0200852CObj unk20;
};

u32 sub_02008700(void)
{
    return sizeof(struct Sub02008700Obj);
}

void sub_02008704(struct Sub02008700Obj *obj)
{
    MIi_CpuClear32(0, obj, sizeof(struct Sub02008700Obj));
    sub_02008320(&obj->unk00);
    sub_020084A0(&obj->unk04);
    sub_020085A0(&obj->unk24);
    obj->unk2C = 0;
}

struct Sub0200852CObj *sub_02008730(void *sys)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID);
    return &obj->unk04;
}

struct Sub02008700Obj *sub_0200873C(void *sys)
{
    return sub_020071CC(sys, BLOCK_ID);
}

struct PlayTime *sub_02008748(void *sys)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID);
    return &obj->unk24;
}

u8 sub_02008754(void *sys)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID);
    return obj->unk2C;
}

void sub_02008764(void *sys)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID);
    obj->unk2C = 1;
}

void sub_02008774(void *sys)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID);
    obj->unk2C = 0;
}

int sub_02008784(void *sys, u32 index)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID);
    if (obj->unk30[index] == 0xC21E) {
        return 1;
    }
    return 0;
}

void sub_020087A8(void *sys, u32 index)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID);
    obj->unk30[index] = 0xC21E;
}

void sub_020087C0(void *sys, u32 index)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID);
    obj->unk30[index] = 0;
}

u32 *sub_020087D4(void *sys, u32 index)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID);
    return &obj->unk44[index];
}

void sub_020087E8(void *sys, const struct Sub020087E8Arg *src)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID);
    obj->unk04 = src->unk20;
}

void sub_02008808(void *sys, struct Sub020087E8Arg *dest)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID);
    dest->unk20 = obj->unk04;
}
