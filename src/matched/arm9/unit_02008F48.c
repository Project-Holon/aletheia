/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008F48
 * packet:   pkt_02008F48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MAIL_InitForPlayer
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   MYSTATUS_GetOutfitVariant  0x02008550  thumb
 *   MAIL_Init  0x02008EAC  thumb
 *
 * alias: mail.c.  The record this fills in is the 0x38-byte object
 * src/matched/unit_02008EAC.c constructs and src/matched/unit_02008F80.c
 * accesses, and the file name is in the image: the allocator at 0x02008F08
 * passes 0x020A716C to the debug allocator and those bytes spell "mail.c".
 *
 * MYSTATUS_GetName is four bytes, `bx lr`, and src/matched/unit_020084BC.c records
 * it as `void MYSTATUS_GetName(void)`.  This call site says what it is: its result
 * feeds MI_CpuCopy8's source operand with no move in between, so it is an
 * identity accessor on its argument, declared here with the type that call
 * needs.  The declaration is a claim about the source, not about the bytes,
 * which are `bx lr` either way.
 *
 * The third parameter is dead: nothing in the function reads r2.
 *
 * NEAR MISS, 0x02008F08, 52 bytes, MATCH with every concrete byte right,
 * skipped.  It is mail.c's allocator,
 *
 *   struct Mail *sub_02008F08(u32 heap)
 *   {
 *       struct Mail *p = sub_02030734((u16)((heap & 0x7FFF) | 0x8000), 0x38,
 *                                     0, sub_02008F08_File, 135);
 *       MAIL_Init(p);
 *       return p;
 *   }
 *
 * which reproduces all 52 bytes, the single 0x7FFF pool word the compiler
 * turns into 0x8000 with `adds r0, r1, #1` included, and caps at MATCH on the
 * __FILE__ pool word.  0x020A716C is named by exactly one word in the image,
 * its own at 0x02008F38, so `literal` has no witness and no cut helps.  The
 * `string` class cannot reach it either, and the reason is worth recording:
 * the run before "mail.c" is not a string.  Its single NUL terminator at
 * 0x020A716B is preceded by 0x2B bytes of 0x02 and 0x03, a static table, so
 * condition 5 of the rule ("the bytes before those NULs are themselves at
 * least four printable ASCII characters") refuses it.  A string at the head of
 * a string section, or one whose neighbour is data, has no outside witness at
 * all.  See docs/idioms/a-string-after-a-data-table-has-no-witness.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008F48.c \
 *       --addr 0x02008F48 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Sub02008EACObj;
struct Sub0200852CObj;

extern void MAIL_Init(struct Sub02008EACObj *obj);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern u8 *func_02012944(void *p);
extern const void *MYSTATUS_GetName(const void *p);
extern u32 MYSTATUS_GetId(const struct Sub0200852CObj *obj);
extern u8  MYSTATUS_GetOutfitVariant(const struct Sub0200852CObj *obj);

struct Sub02008EACObjLayout {
    u32 unk00;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u8  unk08[0x10];
};

void MAIL_InitForPlayer(struct Sub02008EACObjLayout *obj, u8 kind, u32 unused,
                  void *p)
{
    struct Sub0200852CObj *src;

    MAIL_Init((struct Sub02008EACObj *)obj);
    obj->unk07 = kind;
    src = (struct Sub0200852CObj *)func_02012944(p);
    MI_CpuCopy8(MYSTATUS_GetName(src), obj->unk08, sizeof(obj->unk08));
    obj->unk04 = MYSTATUS_GetOutfitVariant(src);
    obj->unk00 = MYSTATUS_GetId(src);
}
