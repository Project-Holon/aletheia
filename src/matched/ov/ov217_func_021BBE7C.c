/*
 * function: RESEARCH_LIST_ShiftTextLeft
 * address: 0x021BBE7C
 * packet: pkt_ov217_021BBE7C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_GetBuf 0x0204162C arm
 *   RESEARCH_LIST_GetRowBase 0x021BBF1C thumb ov217
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { INDEX_ZERO=0 } Index;
extern u32 BG_SYS_GetBuf(int channel);
extern u32 RESEARCH_LIST_GetRowBase(u32 object,u32 index);
extern void func_02041B6C(u32 channel);
void RESEARCH_LIST_ShiftTextLeft(u32 object,u32 slot)
{
    u16 *first;
    int row;
    u16 *second;
    int column;
    Index index;
    int base,destination;
    first=(u16 *)BG_SYS_GetBuf(2);
    second=(u16 *)BG_SYS_GetBuf(3);
    for(row=2;row>=0;row--) {
        for(column=27;column>=0;column--) {
            base=RESEARCH_LIST_GetRowBase(object,slot);
            index=column+1+(base+row)*32;
            destination=index+1;
            first[destination]=first[index];
            second[destination]=second[index];
        }
    }
    base=RESEARCH_LIST_GetRowBase(object,slot);
    first[base*32+1]=first[0];
    second[base*32+1]=second[0];
    first[(base+1)*32+1]=first[0];
    second[(base+1)*32+1]=second[0];
    first[(base+2)*32+1]=first[0];
    second[(base+2)*32+1]=second[0];
    func_02041B6C(2);
    func_02041B6C(3);
}
