/*
 * function: func_02185C84
 * address: 0x02185C84
 * packet: pkt_ov219_02185C84
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02184790 0x02184790 thumb ov219
 *   func_02045B38 0x02045B38 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045C04 0x02045C04 arm
 *   func_02025BA0 0x02025BA0 thumb
 * prototype: caller explicitly truncatesB5B38 member/heap at secondsite; useu16extern for those observed narrow inputs.4790 is tailstubto02025B3C readingonlykey.
 */
typedef unsigned short u16;
extern unsigned func_02184790(unsigned),func_02025BA0(unsigned);
extern void *func_02045B38(unsigned,unsigned,u16,u16);
typedef unsigned int   u32;
struct MsgBank;
struct Rec;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02045C04(struct Rec *rec);
int func_02185C84(unsigned key,unsigned optional,void *first,void *second,unsigned heap)
{
    unsigned index;
    void *bank;
    int found;
    index=func_02184790(key);
    found=0;
    bank=func_02045B38(0,2,231,heap);
    func_02045CAC(bank,key,first);
    func_02045C04(bank);
    if(index==0) {index=1;optional=0;}
    else found=1;
    bank=func_02045B38(0,2,func_02025BA0(index),heap);
    func_02045CAC(bank,optional,second);
    func_02045C04(bank);
    return found;
}
