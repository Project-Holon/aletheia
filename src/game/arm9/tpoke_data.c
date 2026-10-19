/*
 * file:     tpoke_data.c
 * unit:     yes
 * function: TPOKE_DATA_Create, TPOKE_Delete, TPOKE_DATA_GetRecordIndex, TPOKE_DATA_IsRecordKindTwo, TPOKE_DATA_FindEntryIndex, TPOKE_DATA_GetEntryIndex, TPOKE_DATA_GetRecordPtr, TPOKE_DATA_GetRecordField, TPOKE_DATA_FindRecord, TPOKE_DATA_ReadRecordString, TPOKE_DATA_ReadRecord, TPOKE_DATA_ReadParty, TPOKE_DATA_GetGenderValue, TPOKE_DATA_FindTrainerType, TPOKE_DATA_GetTrainerKind, TPOKE_DATA_GetTrainerGroup
 * address:  0x0202A128
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
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   ARC_UTIL_LoadMemberWithSize  0x0204A298  arm
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   sTpokeData82   0x020A76CC  data
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   ARC_TOOL_ReadMemberRange  0x02048F74  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   STRBUF_Clear  0x0204581C  arm
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   gTpokeDataGenderValueTable  0x0209FF1C  data
 *   gTpokeDataTrainerKindTable  0x0209FEE4  data
 *   TPOKE_DATA_FindTrainerType   0x0202A3D8  thumb
 *   TPOKE_DATA_ReadRecord  0x0202A3AC  thumb
 *   MIi_CpuCopy16  0x02082A60  arm
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   NET_DEVICE_TABLE_RemapId  0x0200F128  thumb
 */
struct ArcFile;
struct MsgBank;
struct Rec;
struct U16Vec;
typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {
    int   handle;
    void *buf;
    void *buf4;
    u32   count;
} Tpoke;

typedef unsigned char  u8;

/* One 8-byte entry of the container's entry table.  TPOKE_DATA_FindEntryIndex matches
 * key/type/subtype and returns the entry index; the u16 at +6 indexes the
 * container's 0x1c-byte record table. */
struct Item {
    u16 key;
    u16 type;
    u16 subtype;
    u16 recordIndex;
};

/* The container p: an entry table (8-byte Item records, count entries) and a
 * base address of 0x1c-byte records.  The matched files viewed the entry table
 * at +0x00 and the record base at +0x08. */
struct Container {
    const struct Item *entries;
    u32 pad04;
    int records;
    u32 count;
};

/* One 0x1c-byte record of the container's record table.  Only the byte at
 * +7 is read here (TPOKE_DATA_IsRecordKindTwo compares it with 2); the rest is unknown
 * and recorded in open_items. */
struct TpokeRecord {
    u8 reserved00[7];
    u8 battleKind;
    u8 reserved08[0x14];
};

typedef signed int    s32;

/* The 0x14-byte archive-member-0x5c record, decoded field by field.
 * TPOKE_DATA_GetRecordField returns its fields by index (0..11).  tr_tool.c reads the
 * same member as the trainer record. */
typedef struct {
    u8  type;
    u8  genderClass;
    u8  pad02;
    u8  count;
    u16 words[4];
    u32 word0C;
    u8  flag10 : 1;
    u8  byte11;
    u16 half12;
} TpokeDataRecord;

/* One 7-bit-keyed trainer-kind table row (gTpokeDataTrainerKindTable): val is the
 * trainer type, kind and group are the two small fields looked up from it. */
struct TrainerKindRecord {
    u16 trainerType : 7;
    u16 kind : 4;
    u16 group : 5;
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int   ARC_UTIL_LoadMemberWithSize(int archiveID, int memberIdx, int decompress, int heapID, u32 *out);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern u32 GFL_HEAP_Free(void *p);
extern u32 TPOKE_DATA_FindEntryIndex(const struct Container *c, u32 key, u32 type, u32 subtype);
extern u32   ARC_TOOL_GetMemberSize(u32 a, u32 b);
extern void ARC_TOOL_ReadMemberRange(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
extern void *ARC_TOOL_CreateHandle(unsigned int id, unsigned int heap);
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void  ARC_TOOL_DeleteHandle(void *h);
u32 TPOKE_DATA_GetEntryIndex(u8 *p, u32 key, u32 type, u32 subtype);
int TPOKE_DATA_GetRecordPtr(struct Container *c, int recordIndex);
u32 TPOKE_DATA_GetRecordField(void *a, u32 idx);
u32 TPOKE_DATA_FindRecord(u32 key, u32 want, u32 heap);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void STRBUF_Clear(struct U16Vec *vec);
extern void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);
void TPOKE_DATA_ReadRecordString(int key, int want, void *dest, u32 heap);
void TPOKE_DATA_ReadRecord(void *dest, void *arc);
void TPOKE_DATA_ReadParty(void *dest, void *arc);
u8 TPOKE_DATA_GetGenderValue(u32 idx);
u8 TPOKE_DATA_FindTrainerType(u32 key);
u8 TPOKE_DATA_GetTrainerKind(u32 key);
u32 TPOKE_DATA_GetTrainerGroup(u32 key);
extern void  MIi_CpuCopy16(const void *src, void *dest, u32 size);
extern void  PMSI_PARAM_ClearSentence(void *p);
extern int   NET_DEVICE_TABLE_RemapId(int index);
Tpoke *TPOKE_DATA_Create(int heap);
void TPOKE_Delete(Tpoke *tpoke);
u32 TPOKE_DATA_GetRecordIndex(struct Container *c, u32 key, u32 type, u32 subtype);
int TPOKE_DATA_IsRecordKindTwo(u32 unused, struct Container *c, u32 type, u32 subtype, u16 e);
extern const char sTpokeData82[];
extern const u8 gTpokeDataGenderValueTable[];
extern const struct TrainerKindRecord gTpokeDataTrainerKindTable[];







Tpoke *TPOKE_DATA_Create(int heap)
{
    Tpoke *p;
    u32 size;

    p = (Tpoke *)GFL_HEAP_Alloc(heap, 0x10, 1, sTpokeData82, 82);
    p->handle = ARC_UTIL_LoadMemberWithSize(0xd3, 0, 0, heap, &size);
    p->count = size >> 3;
    p->buf = ARC_TOOL_LoadMember(0x30, 0, heap);
    p->buf4 = (char *)p->buf + 4;
    return p;
}






void TPOKE_Delete(Tpoke *tpoke)
{
    GFL_HEAP_Free(tpoke->buf);
    GFL_HEAP_Free((void *)tpoke->handle);
    GFL_HEAP_Free(tpoke);
}







/*
 * Returns the halfword at entry i (times 8 plus 6) of the +0 table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TPOKE_DATA_GetRecordIndex.c \
 *       --func TPOKE_DATA_GetRecordIndex --addr 0x0202A188 --thumb --cc 1.1p1
 */
u32 TPOKE_DATA_GetRecordIndex(struct Container *c, u32 key, u32 type, u32 subtype)
{
    u32 i = TPOKE_DATA_GetEntryIndex((u8 *)c, key, type, subtype);

    return *(u16 *)((u8 *)c->entries + i * 8 + 6);
}







int TPOKE_DATA_IsRecordKindTwo(u32 unused, struct Container *c, u32 type, u32 subtype, u16 e)
{
    int i = TPOKE_DATA_GetEntryIndex((u8 *)c, type, subtype, e);
    u8 *r = (u8 *)TPOKE_DATA_GetRecordPtr(c, c->entries[i].recordIndex);

    if (((struct TpokeRecord *)r)->battleKind == 2) {
        return 1;
    }
    return 0;
}







/*
 * Bounded scan of the container's 8-byte records: the one whose key matches and
 * whose second field is either 2 or the caller's v2, and whose third field is
 * the caller's v3, is returned by index; 0xffff when none is.  The bound is
 * re-read at the foot of the loop, which is the shape of
 * src/matched/ISS_ZONE_SYS_FindRecord.c: the container has to be declared as a struct
 * with a `count` member and the records reached as `c->items[i]`, because the
 * subscript form is what keeps `c` live in r0 and re-loads `c->count` at the
 * bottom of the loop.  Written with a separate base pointer the compiler caches
 * the bound and the residue is 10 bytes of register shuffling.
 *
 * Closes the blocker of src/pending/TPOKE_DATA_GetEntryIndex.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TPOKE_DATA_FindEntryIndex.c \
 *       --func TPOKE_DATA_FindEntryIndex --addr 0x0202A1CC --thumb --cc 1.1p1
 */
u32 TPOKE_DATA_FindEntryIndex(const struct Container *c, u32 key, u32 type, u32 subtype)
{
    u32 i;

    for (i = 0; i < c->count; i++) {
        if (c->entries[i].key != key) {
            continue;
        }
        if (c->entries[i].type != 2 && c->entries[i].type != type) {
            continue;
        }
        if (c->entries[i].subtype != subtype) {
            continue;
        }
        return i;
    }
    return 0xffff;
}


/*
 * Returns TPOKE_DATA_FindEntryIndex's result, clamped to zero when negative.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TPOKE_DATA_GetEntryIndex.c \
 *       --func TPOKE_DATA_GetEntryIndex --addr 0x0202A20C --thumb --cc 1.1p1
 *
 * Closed by the `matched` class: 0x0202A1CC was filed as an EXACT entry this
 * wave (pkt_0202A19C) with the struct-container spelling of the bounded scan.
 */
u32 TPOKE_DATA_GetEntryIndex(u8 *p, u32 key, u32 type, u32 subtype)
{
    s32 r = TPOKE_DATA_FindEntryIndex((const struct Container *)p, key, type, subtype);

    return r < 0 ? 0u : (u32)r;
}


int TPOKE_DATA_GetRecordPtr(struct Container *c, int recordIndex){ int t0 = NET_DEVICE_TABLE_RemapId((int)(recordIndex + 0)); return (c->records + (t0 * 0x1c)); }


u32 TPOKE_DATA_GetRecordField(void *a, u32 idx)
{
    TpokeDataRecord rec;
    u32 r;

    TPOKE_DATA_ReadRecord(a, &rec);
    switch (idx) {
    case 0:
        r = rec.type;
        break;
    case 1:
        r = rec.genderClass;
        break;
    case 2:
        r = rec.pad02;
        break;
    case 3:
        r = rec.count;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        r = rec.words[idx - 4];
        break;
    case 8:
        r = rec.word0C;
        break;
    case 9:
        r = rec.flag10;
        break;
    case 10:
        r = rec.byte11;
        break;
    case 11:
        r = rec.half12;
        break;
    }
    return r;
}


u32 TPOKE_DATA_FindRecord(u32 key, u32 want, u32 heap)
{
    u16   rec[4];
    void *h;
    u32   end;
    u32   found = 0;

    end = ARC_TOOL_GetMemberSize(0x5a, 0);
    ARC_TOOL_ReadMemberRange(rec, 0x5b, 0, key * 2, (u32 *)2);
    h = ARC_TOOL_CreateHandle(0x5a, heap);

    while (rec[0] != end) {
        ARC_TOOL_ReadHandleMemberRange(h, 0, rec[0], 4, &rec[1]);
        if (rec[1] == key && rec[2] == want) {
            found = 1;
            break;
        }
        if (rec[1] != key) {
            break;
        }
        rec[0] = (u16)(rec[0] + 4);
    }

    ARC_TOOL_DeleteHandle(h);
    return found;
}



void TPOKE_DATA_ReadRecordString(int key, int want, void *dest, u32 heap)
{
    u16   rec[4];
    void *h;
    void *bank;
    u32   end;

    bank = MSGDATA_CreateFromArchive(0, 2, 0xbd, heap);
    end = ARC_TOOL_GetMemberSize(0x5a, 0);
    ARC_TOOL_ReadMemberRange(rec, 0x5b, 0, key * 2, (u32 *)2);
    h = ARC_TOOL_CreateHandle(0x5a, heap);

    while (rec[0] != end) {
        ARC_TOOL_ReadHandleMemberRange(h, 0, rec[0], 4, &rec[1]);
        if (rec[1] == key && rec[2] == want) {
            MSGDATA_ReadString(bank, (u32)rec[0] >> 2, dest);
            break;
        }
        rec[0] = (u16)(rec[0] + 4);
    }

    ARC_TOOL_DeleteHandle(h);
    MSGDATA_Delete(bank);

    if (rec[0] == end) {
        STRBUF_Clear(dest);
    }
}



void TPOKE_DATA_ReadRecord(void *dest, void *arc)
{
    ARC_TOOL_ReadMember(arc, 0x5c, (u32)dest);
}



void TPOKE_DATA_ReadParty(void *dest, void *arc)
{
    ARC_TOOL_ReadMember(arc, 0x5d, (u32)dest);
}



/*
 * Blocked: gTpokeDataGenderValueTable is named by this function's one pool word
 * (0x0202A3D4) inside the compared range; `literal` has no outside site
 * and the target is neither a string nor a pointer table.  Every concrete
 * byte reproduces.
 */
u8 TPOKE_DATA_GetGenderValue(u32 idx)
{
    return gTpokeDataGenderValueTable[idx];
}


u8 TPOKE_DATA_FindTrainerType(u32 key)
{
    int i;

    for (i = 0; i < 0x1c; i++) {
        if (key == gTpokeDataTrainerKindTable[i].trainerType) {
            return (u8)i;
        }
    }
    return 0x1c;
}


u8 TPOKE_DATA_GetTrainerKind(u32 key)
{
    u8 idx = TPOKE_DATA_FindTrainerType(key);
    if (idx >= 0x1c) {
        return 12;
    }
    return (u8)gTpokeDataTrainerKindTable[idx].kind;
}


u32 TPOKE_DATA_GetTrainerGroup(u32 key)
{
    u8 idx = TPOKE_DATA_FindTrainerType(key);
    if (idx >= 0x1c) {
        return 0x11;
    }
    return gTpokeDataTrainerKindTable[idx].group;
}
