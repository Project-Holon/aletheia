/*
 * function: func_021D6C50
 * address: 0x021D6C50
 * packet: pkt_ov116_021D6C50
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the epilogue.
 * symbols:
 *   func_0217BC90 0x0217BC90 arm ov009
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_0217BC90(void *);
typedef unsigned int   u32;
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045C04(struct Rec *rec);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void func_02045808(struct U16Vec *vec);
int func_021D6C50(u8 *p,unsigned heap) {
    int flag,ready;
    void *bank,*str;
    flag = func_0217BC90(p)==2;
    if(flag) ready = *(int *)(p+0x210)>0;
    if(flag==0) return 0;
    if(flag==1 && ready==1) {
        bank = func_02045B38(0,2,0x51,heap);
        str = func_02045EC0(bank,15);
        func_02045C04(bank);
        func_020084E4((u16 *)*(unsigned *)(p+0x218),str);
        func_02045808(str);
        return 2;
    }
    return 1;
}
