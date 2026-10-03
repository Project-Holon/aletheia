/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200BA78
 * packet:   pkt_0200B938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200BA78, func_0200BA80
 *
 * 80 bytes, 0x0200BA78..0x0200BAC8, 2 functions, one of which carries a
 * label in the generated listing.
 *
 * The size getter and the constructor of a 0x35C-byte record: six 0x88-byte
 * entries, then 0x14 bytes at +0x330 that a resource read fills.  The two
 * agree, which is what pins the entry size: 6 * 0x88 is 0x330.
 *
 * The entry is declared as an array of words rather than of bytes, because
 * func_0200BAD4 in src/matched/unit_0200BAD4.c copies one with an eight-byte
 * stepped `ldm`/`stm` loop; a one-aligned declaration gives a byte loop
 * instead.  See docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * The range stops at 0x0200BAC8 because of func_0200BAC8, an eight-byte tail
 * call whose pool word names 0x020271CC and which nothing else in the image
 * branches to or holds a pointer to, so the `label` and `literal` classes are
 * both empty and no cut helps.  It is now matched on its own, as are the
 * other two: src/matched/arm9/func_0200BAC8.c, func_0200BA58.c and
 * func_0200BA68.c. *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045F5C  0x02045F5C  arm
 *   func_02045C04  0x02045C04  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;
typedef signed int     s32;

extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern u16   func_0203F1FC(const void *src, u32 size);
extern void *func_02034AC4(u32 a);
extern void *func_02034A5C(u32 a);
extern void *func_02045B38(u32 a, u32 b, u32 c, u32 d);
extern void  func_02045F5C(void *h, u32 a, void *dest, u32 size);
extern void  func_02045C04(void *h);
extern void  func_020307B0(void *p);

extern void  func_0200B900(void *a, u32 b, u32 c);
extern void *func_020271CC(void *a, u32 id);
extern void  func_02017550(void *ent);
extern void *func_0201A920(u32 a);
extern void  func_0201A954(void *list, u32 n);
extern u32   func_0201A98C(void *list, void *e);
extern u32   func_0201AA18(void *list);
extern void *func_0201AB28(void *list, u32 i);
extern void *func_020185F4(void *a);
extern u32   func_02017E88(void *e, u32 a, u32 b);
extern void *func_0201747C(void *e, u16 tag);
extern void *func_0200BBEC(void *a, u32 b, u32 c);

extern const u16 func_0200B98C_Table[];

struct RecC4 {
    u8  unk0000[0x17DC];
    u16 unk17DC;
    u8  unk17DE[2];
};

struct BattleRec {
    u8  unk00[0x80];
    u8  unk80[0x44];
    struct RecC4 unkC4;
};

extern struct BattleRec *gObj_0214616C;

struct QRec {
    u16 unk00[0x0C];
    u8  unk18[0x0C];
    u16 unk24;
    u16 unk26;
    u8  unk28[2];
    u8  unk2A;
    u8  unk2B;
    u8  unk2C[0x0C];
    u64 unk38;
};

struct Ent88 {
    u32 unk00[0x22];
};

struct Grp330 {
    struct Ent88 ent[6];
};

struct Rec35C {
    struct Grp330 unk000;
    u8 unk330[0x14];
    u8 unk344[0x18];
};

u32 func_0200BA78(void)
{
    return sizeof(struct Rec35C);
}

void func_0200BA80(struct Rec35C *p)
{
    u32 i;
    void *h;

    MI_CpuFill8(p, 0, sizeof(struct Rec35C));
    for (i = 0; i < 6; i++) {
        func_02017550(&p->unk000.ent[i]);
    }
    h = func_02045B38(0, 2, 9, 1);
    if (h != 0) {
        func_02045F5C(h, 6, p->unk330, sizeof(p->unk330));
        func_02045C04(h);
    }
}

