/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200BA38
 * packet:   pkt_0200B938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200BA38, func_0200BA44
 *
 * 32 bytes, 0x0200BA38..0x0200BA58, 2 functions, one of which carries a
 * label in the generated listing.
 *
 * func_0200BA44 stamps the record's own checksum into its last halfword, and
 * 0x17DC is both the length checksummed and the store's offset, so the
 * compiler holds it in one register and the store is a register-offset
 * `strh`; 0x17DC is far past the 62-byte reach of the immediate form anyway.
 *
 * Near miss, and the reason this range starts at 0x0200BA38: func_0200B98C,
 * 172 bytes, an eight-case dispatcher returning `long long`.  Every case, the
 * jump table and the three pool words reproduce; what does not is one
 * instruction in the `case 3` table search.  The original keeps the loop
 * index in r2 and copies it into r0 to return it (`adds r0, r2, #0`), where
 * every spelling tried here allocates the index to r0 directly and drops the
 * copy, which is two bytes short and moves the four later table entries.
 * Nine shapes were compiled and ranked: the table as a named `const u16 *`
 * local declared before and after the compared value, the comparison in both
 * operand orders, `while` against `for`, a `continue` form, the index at
 * function scope and at case scope, and the compared field as `u16` and
 * `u32`.  All nine are 168 bytes against the original's 172 and the ranking
 * is flat, so the missing copy is not reachable from the source shape.  Same
 * class as the near misses at 0x0200B2A4 and 0x0200B37C.
 *
 * Near miss, and the reason this range stops at 0x0200BA58: func_0200BA58 and
 * func_0200BA68, eight bytes of tail call each.  Both reproduce every
 * instruction but hold their argument in a pool word rather than in a `movs`,
 * and 0xBC fits a `movs` immediate, so the argument cannot be an integer
 * literal.  Both are now matched on their own: src/matched/arm9/
 * func_0200BA58.c and func_0200BA68.c. *
 * symbols:
 *   func_0203F1FC  0x0203F1FC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;
typedef signed int     s32;

extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern u16 func_0203F1FC(const u8 *src, u32 len);
struct Mon;
struct MsgBank;
struct MsgData;
struct Party;
struct PartyMon;
struct Rec;
struct Sav;
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020307B0(void *p);

extern void  func_0200B900(void *a, u32 b, u32 c);
extern void *func_020271CC(void *a, u32 id);
extern void func_02017550(struct Sav *p);
extern struct Party *func_0201A920(u32 heap);
extern void func_0201A954(struct Party *p, s32 capacity);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32   func_0201AA18(void *list);
extern void *func_0201AB28(void *list, u32 i);
extern void *func_020185F4(void *a);
extern u32   func_02017E88(void *e, u32 a, u32 b);
extern void *func_0201747C(struct Mon *p, u32 heap);
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

u32 func_0200BA38(u32 v)
{
    if (v <= 100) {
        return 1;
    }
    return 0;
}

void func_0200BA44(struct RecC4 *p)
{
    p->unk17DC = func_0203F1FC((const u8 *)p, 0x17DC);
}

