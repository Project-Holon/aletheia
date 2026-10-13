/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200C9EC
 * packet:   pkt_0200C9F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ZUKAN_SAVE_GetSize, ZUKAN_SAVE_Init, ZUKAN_SAVE_GetBlock, ZUKAN_SAVE_GetFromGameData,
 *           ZUKAN_SAVE_EnableNationalDex, ZUKAN_SAVE_IsNationalDexEnabled, ZUKAN_SAVE_SetDexObtained, ZUKAN_SAVE_GetDexObtained,
 *           ZUKAN_SAVE_SetViewMode, ZUKAN_SAVE_GetViewMode, ZUKAN_SAVE_SetLastViewedSpecies, ZUKAN_SAVE_GetLastViewedSpecies
 *
 * 172 bytes, 0x0200C9EC..0x0200CA98, 12 functions, nine of which carry no
 * label in the generated listing.
 *
 * The opening of the save block with id 0x37: ZUKAN_SAVE_GetSize returns 0x4D4,
 * ZUKAN_SAVE_Init clears exactly 0x4D4 bytes and stamps 0xBEEFCAFE into the
 * first word, and ZUKAN_SAVE_GetBlock is the whole of the lookup
 * `func_020071CC(sys, 0x37)`.  The magic word is the tell that the record is
 * checked rather than merely zeroed; nothing in this range reads it back.
 *
 * The word at +0x04 is a packed set of bitfields, and the widths are read off
 * the shift pairs rather than guessed: `lsls #0x15` / `lsrs #0x16` is bits
 * 1..10 and `lsls #0x0A` / `lsrs #0x16` is bits 12..21, so the layout is
 * 1 + 10 + 1 + 10 bits with the top ten unused by anything in this range.
 * ZUKAN_SAVE_GetLastViewedSpecies truncates its ten-bit field to `u16` on the way out, which is
 * the second shift pair in it and is a return type rather than a field width.
 *
 * This unit stops at 0x0200CA98 rather than running to the end of the
 * original file: ZUKAN_SAVE_UpdateViewFlags is 376 bytes of bit-array maintenance over
 * three module-level tables and is not attempted here.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
struct Big;
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *GAME_DATA_GetSaveControl(struct Big *p);

struct Blk37 {
    u32 unk00;
    u32 f0  : 1;
    u32 f1  : 10;
    u32 f11 : 1;
    u32 f12 : 10;
    u32 f22 : 10;
    u8  unk08[0x4CC];
};

void *ZUKAN_SAVE_GetBlock(void *sys);

u32 ZUKAN_SAVE_GetSize(void)
{
    return sizeof(struct Blk37);
}

void ZUKAN_SAVE_Init(struct Blk37 *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Blk37));
    p->unk00 = 0xBEEFCAFE;
}

void *ZUKAN_SAVE_GetBlock(void *sys)
{
    return func_020071CC(sys, 0x37);
}

void *ZUKAN_SAVE_GetFromGameData(void *a)
{
    return ZUKAN_SAVE_GetBlock(GAME_DATA_GetSaveControl(a));
}

struct Blk37 *ZUKAN_SAVE_EnableNationalDex(struct Blk37 *p)
{
    p->f0 = 1;
    return p;
}

u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p)
{
    return p->f0;
}

struct Blk37 *ZUKAN_SAVE_SetDexObtained(struct Blk37 *p)
{
    p->f1 = 1;
    return p;
}

u32 ZUKAN_SAVE_GetDexObtained(struct Blk37 *p)
{
    return p->f1;
}

void ZUKAN_SAVE_SetViewMode(struct Blk37 *p, u32 v)
{
    p->f11 = v;
}

u32 ZUKAN_SAVE_GetViewMode(struct Blk37 *p)
{
    return p->f11;
}

void ZUKAN_SAVE_SetLastViewedSpecies(struct Blk37 *p, u32 v)
{
    p->f12 = v;
}

u16 ZUKAN_SAVE_GetLastViewedSpecies(struct Blk37 *p)
{
    return p->f12;
}
