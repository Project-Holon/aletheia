/*
 * function: unit_0201C6FC
 * address:  0x0201C6FC
 * packet:   pkt_0201C6FC
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * unit:     yes
 * address:  0x0201C6FC
 * note:     168 bytes, three functions
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * printsys.c's two public print entry points and the dispatcher they share.
 * PRINTSYS_SubmitJob decides between drawing straight away and queueing the request
 * into the ring: when the module is not busy and the flags nibble in the byte
 * at +7 is clear it calls PRINTSYS_RunJob directly, otherwise it queues with
 * GF_FONT_CopyStrbufD6D8 provided the request fits in the free space func_0201D6C4
 * reports.
 *
 * Why it is capped: the `bl` at 0x0201C79C is the only branch to GF_FONT_CopyStrbufD6D8
 * anywhere in the image, and no pool word holds the address either, so the
 * `label` class has no witness once the compared range holds that call.  No
 * cut helps, because the range cannot be made smaller than PRINTSYS_SubmitJob and
 * the call is inside it.  The `matched` class would carry it, but
 * GF_FONT_CopyStrbufD6D8 is not matched: it is EXACT only in a range that also holds
 * GF_FONT_Copy, and GF_FONT_Copy is four bytes short (the original spills
 * the byte counter and keeps the ring cursor in a callee-saved register; every
 * source shape tried makes the opposite choice).  See the header of
 * src/matched/unit_0201D7C4.c.
 *
 * It closes the day GF_FONT_Copy's register allocation is reproduced, which
 * makes GF_FONT_CopyStrbufD6D8 an EXACT entry and the `matched` class applies.
 *
 * PRINTSYS_SubmitJob's busy test is normalised to 0 or 1 before it is used, which is
 * what a `!= 0` assigned to a local gives; the flags nibble is read as a four
 * bit unsigned bitfield, `((u32)((u8 *)p)[7] << 24) >> 28`, the same spelling
 * src/matched/unit_0201CE5C.c needs for a one bit field.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_0201C6FC.c \
 *       --addr 0x0201C6FC --thumb
 *
 * symbols:
 *   _PrintJobWork   0x0214655C  data
 *   PRINTSYS_SetupJob  0x0201C808  thumb
 *   PRINTSYS_SetJobColor  0x0201C8A4  thumb
 *   PRINTSYS_RunJob  0x0201C8BC  thumb
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GF_FONT_CopyStrbufD6D8  0x0201D6D8  thumb
 */

#include "../include/G_Scratch.h"

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed short       s16;
typedef unsigned long long u64;

struct PrintCtx {
    s16 unk00;
    s16 unk02;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    void *unk10;
    void *unk14;
    void *unk18;
};

union Ticks {
    u64 v;
    struct {
        u32 lo;
        u32 hi;
    } w;
};

struct PrintSys {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u8  unk06;
    u8  unk07;
    union Ticks unk08;
    struct PrintCtx *unk10;
    struct PrintCtx *unk14;
};

extern struct Scratch _PrintJobWork;

extern int GFL_NET_GetNegotiationNum(void);
extern u32   func_0201D6B8(void *s);
struct Rec2;
struct Ring;
extern u32 func_0201D6C4(const struct Ring *p);
extern void  GF_FONT_CopyStrbufD6D8(struct PrintSys *p, void *a, void *b);

extern void PRINTSYS_SetupJob(struct PrintCtx *c, u32 a, u32 b, u32 d, u32 e);
extern void PRINTSYS_SetJobColor(struct Rec2 *p, u16 v);
extern void PRINTSYS_RunJob(u8 *a0, int a1);

void PRINTSYS_SubmitJob(struct PrintSys *p, struct PrintCtx *c, void *s);

void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e)
{
    PRINTSYS_SetupJob(((struct PrintCtx *)&_PrintJobWork), e, a, b, c);
    PRINTSYS_SubmitJob(p, ((struct PrintCtx *)&_PrintJobWork), s);
}

void PRINTSYS_PrintQueColor(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e,
                  u16 f)
{
    PRINTSYS_SetupJob(((struct PrintCtx *)&_PrintJobWork), e, a, b, c);
    PRINTSYS_SetJobColor((struct Rec2 *)(((struct PrintCtx *)&_PrintJobWork)), f);
    PRINTSYS_SubmitJob(p, ((struct PrintCtx *)&_PrintJobWork), s);
}

void PRINTSYS_SubmitJob(struct PrintSys *p, struct PrintCtx *c, void *s)
{
    u32 busy = GFL_NET_GetNegotiationNum() != 0;
    u32 need;

    if (busy == 0 && (((u32)((u8 *)p)[7] << 24) >> 28) == 0) {
        PRINTSYS_RunJob((u8 *)c, (int)s);
        return;
    }
    need = func_0201D6B8(s);
    if (need <= func_0201D6C4((const struct Ring *)p)) {
        GF_FONT_CopyStrbufD6D8(p, c, s);
    }
}
