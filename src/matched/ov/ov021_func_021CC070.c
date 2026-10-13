/*
 * function: FLD_TRADE_GetMessageString
 * address:  0x021CC070
 * packet:   pkt_ov021_021CC070
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Opens message bank 0x23 for a given file, fetches one string and closes the bank.
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   MSGDATA_Delete  0x02045C04  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);

void *FLD_TRADE_GetMessageString(u32 file, u32 index)
{
    void *bank = func_02045B38(0, 2, 0x23, (u16)file);
    void *s = func_02045EC0(bank, index);
    MSGDATA_Delete(bank);
    return s;
}
