/*
 * file:     musical_dist_save.c
 * unit:     yes
 * function: MUSICAL_DIST_SAVE_Create, MUSICAL_DIST_SAVE_Delete, MUSICAL_DIST_SAVE_CreateFromData, MUSICAL_DIST_SAVE_ProcessApply, MUSICAL_DIST_SAVE_GetBlockSize, func_0200C6F0, func_0200C720, func_0200C738, func_0200C780, func_0200C7A0
 * address:  0x0200C52C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   SAVE_CONTROL_LoadExtraSaveWithBuffer  0x020072CC  thumb
 *   func_020073D8  0x020073D8  thumb
 *   g_MusicalDistSaveFileName     0x020A71D4  data  a1
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_CreateHandleFromMemory  0x0204913C  arm
 *   ARC_UTIL_LoadHandleMemberWithSize  0x0204A39C  arm
 *   MSGDATA_CreateFromMemory  0x02045C44  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_ToChars  0x02045A38  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   g_0209DE2C      0x0209DE2C  data
 *   g_0209DE20      0x0209DE20  data
 *   GAME_DATA_PartSaveStart  0x02012E4C  thumb
 *   GAME_DATA_PartSaveMain  0x02012E7C  thumb
 */
struct SaveWork;
struct SaveBlockCtrl;
struct MsgBank;
struct MsgString;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct DistHeader {
    u32 payload_size;
    u32 reserved[3];
};

struct MusicalDist {
    u16 heap_id;
    u32 load_ok;
    u32 state;
    struct DistHeader header;
    void *block;
    struct DistHeader *block_head;
    u8   *payload;
    void *game_sys;
};

typedef signed int     s32;

struct BlockImage {
    u8 body[0x1FE0];
    u8 footer[0x20];
};

extern void *GAME_DATA_GetSaveControl(struct SaveWork *game_sys);
extern void *func_02030734(u32 heap_id, u32 size, int clear, const char *file_name, u16 line);
extern u32   SAVE_CONTROL_LoadExtraSaveWithBuffer(void *save_ctrl, u32 block_id, u32 heap_id, void *buf, u32 size);
extern void *func_020073D8(struct SaveBlockCtrl *save_ctrl, u32 block_id, u32 mode);
extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void func_020072A4(struct SaveBlockCtrl *save_ctrl, u32 block_id);
extern u32 func_020307B0(void *mem);
extern void GAME_DATA_PartSaveStart(u8 *game_sys, u32 block_id);
extern int GAME_DATA_PartSaveMain(char *game_sys, int block_id);
extern void *func_0200A5F8(void *save);
extern void func_0200A7EC(struct SaveWork *profile, u8 value);
extern u8 *func_0200A7F8(struct SaveWork *profile);
extern void *ARC_TOOL_CreateHandleFromMemory(void *data, u32 size, u32 heap_id);
extern void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int file_id, int decompress, u32 heap_id, u32 *out_size);
extern struct MsgBank *MSGDATA_CreateFromMemory(const void *file, u32 heap_id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void  STRBUF_ToChars(struct MsgString *str, u16 *dest, u32 max_len);
extern void STRBUF_Delete(struct MsgString *str);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern void  ARC_TOOL_DeleteHandle(void *narc);
extern void MUSICAL_DIST_SAVE_Delete(struct MusicalDist *dist);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
struct MusicalDist *MUSICAL_DIST_SAVE_Create(void *game_sys, u32 heap_id);
u32 MUSICAL_DIST_SAVE_GetPayload(struct MusicalDist *dist);
void func_0200C6EC(void);
void func_0200C738(u8 *seen_flags, u32 species, u32 language);
int func_0200C780(u32 species);
int func_0200C7A0(u32 species);
extern const char g_MusicalDistSaveFileName[];
extern u16 g_0209DE2C[];
extern u16 g_0209DE20[];


/*
 * musical_dist_save.c constructor: allocate the 0x2C-byte control block and
 * a 0x20000-byte buffer, load save block 6 into the buffer through the save
 * system, record heap/system, then attach the loaded block.
 *
 * Closed in wave 15.  The residue since wave 11 (image homes sys to the
 * stack and keeps sv in r6 and the id 6 in r7; every earlier shape did the
 * reverse) was not an allocation tie: the func_020073D8 call is written in
 * BOTH arms of the `r == 1` test and the compiler tail-merges the two
 * copies.  The merged call is what keeps 6 live in a callee-saved register
 * and lets the shared zero land in r2 as the third argument.
 */
struct MusicalDist *MUSICAL_DIST_SAVE_Create(void *game_sys, u32 heap_id)
{
    void *save_ctrl;
    struct MusicalDist *dist;
    u32 load_result;
    u8 *block;

    save_ctrl = GAME_DATA_GetSaveControl(game_sys);
    dist = func_02030734(heap_id, 0x2C, 1, g_MusicalDistSaveFileName, 0x4A);
    dist->block = func_02030734(heap_id, 0x20000, 1, g_MusicalDistSaveFileName, 0x4C);
    load_result = SAVE_CONTROL_LoadExtraSaveWithBuffer(save_ctrl, 6, heap_id, dist->block, 0x20000);
    dist->heap_id = heap_id;
    dist->game_sys = game_sys;
    dist->state = 0;
    if (load_result == 1) {
        dist->load_ok = 1;
        block = func_020073D8(save_ctrl, 6, 0);
    } else {
        dist->load_ok = 0;
        block = func_020073D8(save_ctrl, 6, 0);
    }
    dist->block = block;
    dist->block_head = (struct DistHeader *)block;
    dist->payload = block + 0x10;
    return dist;
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 84 bytes, 0x0200C5A4..0x0200C5F8, 2 functions, both of which carry a label
 * in the generated listing.
 *
 * alias: inside "musical_dist_save.c"; see src/matched/unit_0200C6D8.c for
 * how the file name at 0x020A71D4 is attested.  The record the file works on
 * is 0x2C bytes: a heap id at +0x00, a flag at +0x04, a state counter at
 * +0x08, a 0x10-byte header at +0x0C, the working buffer at +0x1C, the
 * buffer's base again at +0x20, the payload at base + 0x10 in +0x24, and the
 * system pointer at +0x28.  Every field is pinned by the constructor at
 * 0x0200C52C and by MUSICAL_DIST_SAVE_ProcessApply, neither of which is in this range; see the
 * two near misses below.
 *
 * MUSICAL_DIST_SAVE_Delete is the destructor.  The guard around the buffer free is
 * written as a plain `if`, and the fall-through arm is the free, so the test
 * in the source is `dist->block != 0` and not the inverse; see
 * docs/idioms/the-fall-through-arm-is-the-source-order.md.
 *
 * Two near misses bracket this range, and they are of different kinds.
 *
 *  - MUSICAL_DIST_SAVE_Create, 118 bytes, the constructor.  It is a codegen miss and not
 *    an evidence one: 0x0200C52C is attested by one branch from an overlay,
 *    so it resolves here as `label`.  The original spends one instruction
 *    this source cannot buy, `movs r7, #6` at 0x0200C56C, which parks the
 *    save-block id in a callee-saved register so that the second use of it
 *    (the func_020073D8 call at 0x0200C560) is a register copy rather than a
 *    second `movs`.  Doing so costs the original a register, and the visible
 *    consequence is that the first parameter is homed to the stack at entry
 *    (`str r0, [sp, #4]`) while the GAME_DATA_GetSaveControl result keeps r6; every
 *    source shape tried here does the reverse and is 116 bytes against the
 *    original's 118.  Thirty-six shapes were compiled and ranked by diff
 *    count: six permutations of the three field stores crossed with four
 *    positions for the SAVE_CONTROL_LoadExtraSaveWithBuffer call, the result as a named local
 *    against the call written inline in the `if`, the id 6 as a literal
 *    against a local, five declaration orders for the locals, and a six
 *    argument reading of SAVE_CONTROL_LoadExtraSaveWithBuffer.  The ranking is flat at 57 to 80
 *    concrete bytes and every one of them is 116 bytes, so the missing
 *    instruction is not reachable by statement order.  All nine front ends
 *    agree, at every optimisation level.  Same class as the near misses at
 *    0x0200B2A4 and 0x0200B37C: a register the original spends and the source
 *    does not.
 *  - MUSICAL_DIST_SAVE_ProcessApply, 224 bytes, the state machine.  Every concrete byte of it
 *    reproduces; it is capped at MATCH because 0x0200A7F8 is branched to from
 *    exactly one instruction in the whole image, its own call at 0x0200C680,
 *    so the `label` class has no witness left once that call is inside the
 *    compared range and no cut helps.  The source is parked in
 *    src/matched/unit_0200C5F8.c.
 */
void MUSICAL_DIST_SAVE_Delete(struct MusicalDist *dist)
{
    func_020072A4(GAME_DATA_GetSaveControl(dist->game_sys), 6);
    if (dist->block != 0) {
        func_020307B0(dist->block);
    }
    func_020307B0(dist);
}

struct MusicalDist *MUSICAL_DIST_SAVE_CreateFromData(void *game_sys, const void *data, u32 size,
                                  u32 heap_id)
{
    struct MusicalDist *dist = MUSICAL_DIST_SAVE_Create(game_sys, heap_id);

    if (dist->block != 0) {
        dist->header.payload_size = size;
        MI_CpuCopy8(&dist->header, dist->block, sizeof(dist->header));
        MI_CpuCopy8(data, dist->payload, size);
    }
    return dist;
}


/*
 * 0x0200C5F8..0x0200C6D8, 224 bytes, one function.
 *
 * The state machine of "musical_dist_save.c"; see src/matched/unit_0200C5A4.c
 * for the record it works on and for how the file name is attested.
 *
 * What held it open, and what closed it: 0x0200A7F8 is the target of exactly
 * one branch in the whole image, the `bl` at 0x0200C680 inside this very
 * function, so the `label` class discards its only witness under the honesty
 * rule and no cut helps, because shrinking the range to this one function
 * keeps the call in it.  The `matched` class carries it: 0x0200A7F8 is inside
 * src/matched/unit_0200A6F8.c, an EXACT entry verified against the original
 * bytes over a range this file does not touch.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0200C5F8.c \
 *       --addr 0x0200C5F8 --thumb
 *
 * The tag the three service calls take is `(u16)((dist->heap_id & 0x7FFF) |
 * 0x8000)` written out at each of the three sites: the original reloads the
 * halfword and redoes the mask each time while keeping 0x7FFF alive in r4,
 * and 0x8000 is reached as `adds rN, r4, #1` off that pool word rather than
 * from one of its own.
 */
u32 MUSICAL_DIST_SAVE_ProcessApply(struct MusicalDist *dist)
{
    u32 out_size;
    void *profile;
    void *narc;
    void *msg_file;
    void *msg_bank;
    void *msg_str;

    switch (dist->state) {
    case 0:
        if (dist->block == 0) {
            MUSICAL_DIST_SAVE_Delete(dist);
            return 1;
        }
        profile = func_0200A5F8(GAME_DATA_GetSaveControl(dist->game_sys));
        func_0200A7EC(profile, 1);
        narc = ARC_TOOL_CreateHandleFromMemory(dist->payload, dist->header.payload_size,
                             (u16)((dist->heap_id & 0x7FFF) | 0x8000));
        msg_file = ARC_UTIL_LoadHandleMemberWithSize(narc, 1, 0, (u16)((dist->heap_id & 0x7FFF) | 0x8000), &out_size);
        msg_bank = MSGDATA_CreateFromMemory(msg_file, (u16)((dist->heap_id & 0x7FFF) | 0x8000));
        msg_str = func_02045EC0(msg_bank, 0);
        STRBUF_ToChars(msg_str, (u16 *)func_0200A7F8(profile), 0x25);
        STRBUF_Delete(msg_str);
        MSGDATA_Delete(msg_bank);
        func_020307B0(msg_file);
        ARC_TOOL_DeleteHandle(narc);
        GAME_DATA_PartSaveStart(dist->game_sys, 6);
        dist->state++;
        break;
    case 1:
        if (GAME_DATA_PartSaveMain(dist->game_sys, 6) == 2) {
            MUSICAL_DIST_SAVE_Delete(dist);
            return 1;
        }
        break;
    }
    return 0;
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200C6F0, func_0200C720
 *
 * 96 bytes, 0x0200C6D8..0x0200C738, 6 functions, none of which carries a
 * label in the generated listing.
 *
 * alias: this range is inside "musical_dist_save.c".  The constructor of the
 * file, MUSICAL_DIST_SAVE_Create, loads 0x020A71D4 as the file-name argument to the
 * debug allocator at 0x02030734, and the bytes at 0x020A71D4 spell
 * "musical_dist_save.c"; the string before it is "battle_rec.c", whose
 * terminator at 0x020A71DF fixes that start.  That is the fourth original
 * source file name this project has recovered, after "playtime.c",
 * "box_savedata.c" and "battle_rec.c".  The functions keep their
 * `func_<address>` names, because the file identity is attested and the
 * individual entry points are not.
 *
 * The two getters at the top reach the 0x2C-byte object MUSICAL_DIST_SAVE_Create
 * allocates; func_0200C6F0 works on a 0x2000-byte buffer instead, comparing
 * the 0x20 bytes at +0x1FE0 against a cleared stack copy of the same length,
 * which is a "is this record still blank" test.  func_0200C6EC is `bx lr` and
 * nothing else, a hook that was never filled in.
 *
 * func_0200C720 is the shape docs/idioms/the-fall-through-arm-is-the-source-order.md
 * warns about, read the other way: the `beq` jumps **into** the `return 1`
 * block and the `bls` jumps **past** it, which is the short-circuit `||` of
 * one `if`, not two statements.
 */
u32 MUSICAL_DIST_SAVE_GetPayload(struct MusicalDist *dist)
{
    return (u32)dist->payload;
}

u32 MUSICAL_DIST_SAVE_GetPayloadSize(struct MusicalDist *dist)
{
    return dist->block_head->payload_size;
}

u32 MUSICAL_DIST_SAVE_GetBlockSize(void)
{
    return 0x2600;
}


void func_0200C6EC(void)
{
}


u32 func_0200C6F0(struct BlockImage *image)
{
    u8 blank[0x20];
    u32 footer_set = 0;

    MI_CpuFill8(blank, 0, sizeof(blank));
    if (func_0203EFC8(blank, image->footer, sizeof(blank)) != 0) {
        footer_set = 1;
    }
    return footer_set;
}

u32 func_0200C720(u32 species)
{
    if (species == 0 || species > 0x289) {
        return 1;
    }
    return 0;
}


/*
 * Leaf bitset setter.  Guard chain (language > 8, language == 6, species > 0x1ED all bail),
 * then a 7-wide row/column flattening into a u16 index, then a read-modify-
 * write of one bit in the 0x320-byte bitset that follows *p.  The 0x1ED bound
 * needs a pool word because it is not encodable as a Thumb movs immediate.
 *
 * The index shift is `asrs` because the u16 index promotes to signed int
 * before `>> 3`; the (u8) truncation of the one-hot mask is what the lsls/
 * lsrs #24 pair is.
 */
void func_0200C738(u8 *seen_flags, u32 species, u32 language)
{
    u16 bit_index;
    u8 *bitset;

    if (language > 8)
        return;
    if (language == 6)
        return;
    if (species > 493)
        return;
    if (language >= 7)
        language--;
    species--;

    bit_index = (u16)((language - 1) + species * 7);
    bitset = seen_flags + 0x320;
    bitset[bit_index >> 3] |= (u8)(1 << (bit_index & 7));
}


int func_0200C780(u32 species)
{
    u32 i;

    for (i = 0; i < 0xf; i++) {
        if (species == g_0209DE2C[i])
            return 0;
    }
    return 1;
}


int func_0200C7A0(u32 species)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        if (species == g_0209DE20[i])
            return 0;
    }
    return 1;
}
