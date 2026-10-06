/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B938
 * packet:   pkt_0200B938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200B938
 *
 * 84 bytes, 0x0200B938..0x0200B98C, one function, which carries a label in
 * the generated listing.
 *
 * The publisher of the battle record: three copies into the single object at
 * 0x0214616C and then a checksum word handed to func_0200B900.  The object is
 * 0x18A4 bytes, which is what func_0200B440 in src/matched/unit_0200B400.c
 * returns, so the record is pinned from both ends: 0x80 + 0x44 + 0x17E0 is
 * exactly 0x18A4.
 *
 * The word handed over is `v + ((v ^ 0xFFFF) << 16)`, spelled with `+` and
 * not with `|`: the two halves cannot overlap and this compiler emits `adds`
 * for the one and `orrs` for the other.  The length 0x17DC is rematerialised
 * as `subs r1, r6, #4` off the 0x17E0 that is still live from the second
 * copy, which is the compiler reusing a value rather than a second constant
 * in the source.
 *
 * The range stops at 0x0200B98C because of a near miss there; see
 * src/matched/unit_0200BA38.c. *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   gObj_0214616C  0x0214616C  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;
typedef signed int     s32;

extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
struct Mon;
struct MsgBank;
struct MsgData;
struct Party;
struct PartyMon;
struct Rec;
struct Sav;
extern int func_0203F1FC(const u8 *src, u32 len);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern void func_02045C04(struct Rec *rec);
extern void  func_020307B0(void *p);

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

void func_0200B938(const void *a, const void *b, const void *c)
{
    u16 v;

    MI_CpuCopy8(b, gObj_0214616C->unk80, sizeof(gObj_0214616C->unk80));
    MI_CpuCopy8(c, &gObj_0214616C->unkC4, sizeof(gObj_0214616C->unkC4));
    MI_CpuCopy8(a, gObj_0214616C->unk00, sizeof(gObj_0214616C->unk00));
    v = gObj_0214616C->unkC4.unk17DC;
    func_0200B900(&gObj_0214616C->unkC4, 0x17DC, v + ((v ^ 0xFFFF) << 16));
}

