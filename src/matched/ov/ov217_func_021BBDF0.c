/*
 * function: func_021BBDF0
 * address: 0x021BBDF0
 * packet: pkt_ov217_021BBDF0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204162C 0x0204162C arm
 *   func_021BBF1C 0x021BBF1C thumb ov217
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { INDEX_ZERO=0 } Index;
extern u32 func_0204162C(int channel);
extern u32 func_021BBF1C(u32 object,u32 index);
extern void func_02041B6C(u32 channel);
void func_021BBDF0(u32 object,u32 slot)
{
    u16 *first;
    int row;
    u16 *second;
    int column;
    Index index;
    int base,destination;
    first=(u16 *)func_0204162C(2);
    second=(u16 *)func_0204162C(3);
    for(row=0;row<3;row++) {
        for(column=0;column<28;column++) {
            base=func_021BBF1C(object,slot);
            index=column+2+(base+row)*32;
            destination=index-1;
            first[destination]=first[index];
            second[destination]=second[index];
        }
    }
    base=func_021BBF1C(object,slot);
    first[base*32+29]=first[0];
    second[base*32+29]=second[0];
    first[(base+1)*32+29]=first[0];
    second[(base+1)*32+29]=second[0];
    first[(base+2)*32+29]=first[0];
    second[(base+2)*32+29]=second[0];
    func_02041B6C(2);
    func_02041B6C(3);
}
