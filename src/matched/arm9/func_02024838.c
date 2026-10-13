/*
 * function: PMS_WORD_LoadString
 * address:  0x02024838
 * packet:   pkt_02024838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads one archived message/graphics entry into the caller's buffer.
 * The flat id is split by PMS_WORD_SplitWordId into a bank index and an
 * entry index; the bank index selects an archive id out of the
 * halfword table at 0x0209F7AC, that archive is opened, the entry is
 * read into dest and the archive closed again.  The sentinel id
 * 0xffff means "nothing to load" and only clears dest.
 *
 * symbols:
 *   Table_0209F7AC   0x0209F7AC  data
 *   PMS_WORD_SplitWordId    0x020248D8  thumb
 *   STRBUF_Clear    0x0204581C  arm
 *   func_02045B38    0x02045B38  arm
 *   MSGDATA_Delete    0x02045C04  arm
 *   MSGDATA_ReadString    0x02045CAC  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 Table_0209F7AC[];

extern int   PMS_WORD_SplitWordId(u32 id, u32 *bank, u32 *entry);
struct MsgBank;
struct Rec;
struct U16Vec;
extern void STRBUF_Clear(struct U16Vec *vec);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);

void PMS_WORD_LoadString(u32 id, void *dest, u32 heap)
{
    u32 bank;
    u32 entry;

    if (id != 0xffff) {
        void *arc;

        PMS_WORD_SplitWordId(id, &bank, &entry);
        bank = Table_0209F7AC[bank];
        arc = func_02045B38(0, 2, bank, heap);
        MSGDATA_ReadString(arc, entry, dest);
        MSGDATA_Delete(arc);
    } else {
        STRBUF_Clear(dest);
    }
}
