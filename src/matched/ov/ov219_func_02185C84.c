/*
 * function: BEACON_DETAIL_GetEntryText
 * address: 0x02185C84
 * packet: pkt_ov219_02185C84
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_DETAIL_GetRecordIndex 0x02184790 thumb ov219
 *   func_02045B38 0x02045B38 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_OAM_GetRecordField 0x02025BA0 thumb
 * prototype: caller explicitly truncatesB5B38 member/heap at secondsite; useu16extern for those observed narrow inputs.4790 is tailstubto02025B3C readingonlykey.
 */
typedef unsigned short u16;
extern unsigned BEACON_DETAIL_GetRecordIndex(unsigned),BMP_OAM_GetRecordField(unsigned);
extern void *func_02045B38(unsigned,unsigned,u16,u16);
typedef unsigned int   u32;
struct MsgBank;
struct Rec;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 MSGDATA_Delete(struct Rec *rec);
int BEACON_DETAIL_GetEntryText(unsigned key,unsigned optional,void *first,void *second,unsigned heap)
{
    unsigned index;
    void *bank;
    int found;
    index=BEACON_DETAIL_GetRecordIndex(key);
    found=0;
    bank=func_02045B38(0,2,231,heap);
    MSGDATA_ReadString(bank,key,first);
    MSGDATA_Delete(bank);
    if(index==0) {index=1;optional=0;}
    else found=1;
    bank=func_02045B38(0,2,BMP_OAM_GetRecordField(index),heap);
    MSGDATA_ReadString(bank,optional,second);
    MSGDATA_Delete(bank);
    return found;
}
