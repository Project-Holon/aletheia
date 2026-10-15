/*
 * unit:     yes
 * address:  0x0200C5F8
 * packet:   pkt_0200C5F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MUSICAL_DIST_SAVE_ProcessApply
 *
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
 * The tag the three service calls take is `(u16)((p->unk00 & 0x7FFF) |
 * 0x8000)` written out at each of the three sites: the original reloads the
 * halfword and redoes the mask each time while keeping 0x7FFF alive in r4,
 * and 0x8000 is reached as `adds rN, r4, #1` off that pool word rather than
 * from one of its own.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_CreateHandleFromMemory  0x0204913C  arm
 *   ARC_UTIL_LoadHandleMemberWithSize  0x0204A39C  arm
 *   MSGDATA_CreateFromMemory  0x02045C44  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_ToChars  0x02045A38  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MUSICAL_DIST_SAVE_Delete  0x0200C5A4  thumb
 *   GAME_DATA_PartSaveStart  0x02012E4C  thumb
 *   GAME_DATA_PartSaveMain  0x02012E7C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MUSICAL_SAVE_GetFromSave  0x0200A5F8  thumb
 *   MUSICAL_SAVE_SetHasDistData  0x0200A7EC  thumb
 *   MUSICAL_SAVE_GetStageData  0x0200A7F8  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Big;
struct MsgBank;
struct Rec;
struct U16Vec;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void GAME_DATA_PartSaveStart(u8 *p, u32 id);
extern int GAME_DATA_PartSaveMain(char *p, int a1);
extern void *MUSICAL_SAVE_GetFromSave(void *save);
extern void MUSICAL_SAVE_SetHasDistData(struct Big *p, u8 value);
extern u8 *MUSICAL_SAVE_GetStageData(struct Big *p);

extern u32 func_020307B0(void *p);
extern void *ARC_TOOL_CreateHandleFromMemory(void *a0, u32 a1, u32 heap);
extern void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern struct MsgBank *MSGDATA_CreateFromMemory(const void *file, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void  STRBUF_ToChars(struct U16Vec *a, u16 *b, u32 c);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void  ARC_TOOL_DeleteHandle(void *a);

struct DistHdr {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
};

struct MusicalDist {
    u16 unk00;
    u32 unk04;
    u32 unk08;
    struct DistHdr unk0C;
    void *unk1C;
    void *unk20;
    u8   *unk24;
    void *unk28;
};

extern void MUSICAL_DIST_SAVE_Delete(struct MusicalDist *p);

u32 MUSICAL_DIST_SAVE_ProcessApply(struct MusicalDist *p)
{
    u32 loc;
    void *a;
    void *c;
    void *d;
    void *e;
    void *f;

    switch (p->unk08) {
    case 0:
        if (p->unk1C == 0) {
            MUSICAL_DIST_SAVE_Delete(p);
            return 1;
        }
        a = MUSICAL_SAVE_GetFromSave(GAME_DATA_GetSaveControl(p->unk28));
        MUSICAL_SAVE_SetHasDistData(a, 1);
        c = ARC_TOOL_CreateHandleFromMemory(p->unk24, p->unk0C.unk00,
                          (u16)((p->unk00 & 0x7FFF) | 0x8000));
        d = ARC_UTIL_LoadHandleMemberWithSize(c, 1, 0, (u16)((p->unk00 & 0x7FFF) | 0x8000), &loc);
        e = MSGDATA_CreateFromMemory(d, (u16)((p->unk00 & 0x7FFF) | 0x8000));
        f = func_02045EC0(e, 0);
        STRBUF_ToChars(f, (u16 *)MUSICAL_SAVE_GetStageData(a), 0x25);
        STRBUF_Delete(f);
        MSGDATA_Delete(e);
        func_020307B0(d);
        ARC_TOOL_DeleteHandle(c);
        GAME_DATA_PartSaveStart(p->unk28, 6);
        p->unk08++;
        break;
    case 1:
        if (GAME_DATA_PartSaveMain(p->unk28, 6) == 2) {
            MUSICAL_DIST_SAVE_Delete(p);
            return 1;
        }
        break;
    }
    return 0;
}
