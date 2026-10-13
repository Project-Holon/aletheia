/*
 * function: PMSI_PARAM_GetSourceString
 * address:  0x0202441C
 * packet:   pkt_02024368
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   Table_0209F724  0x0209F724  data
 *   MSGDATA_CreateFromArchive    0x02045B38  arm
 *   MSGDATA_AllocString    0x02045EC0  arm
 *   MSGDATA_Delete   0x02045C04  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Struct_0202441C {
    u16 arcFileIdx;
    u16 strIdx;
};

extern const u16 Table_0209F724[];
struct MsgBank;
struct Rec;
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);

void *PMSI_PARAM_GetSourceString(const struct Struct_0202441C *obj, u32 heapId)
{
    void *str;
    void *bank;
    u16 hid = (u16)heapId;

    bank = MSGDATA_CreateFromArchive(0, 2, Table_0209F724[obj->arcFileIdx], hid);
    str = MSGDATA_AllocString(bank, obj->strIdx);
    MSGDATA_Delete(bank);

    return str;
}
