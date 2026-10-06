/*
 * function: func_0202441C
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
 *   sub_02045B38    0x02045B38  arm
 *   sub_02045EC0    0x02045EC0  arm
 *   func_02045C04   0x02045C04  arm
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
extern struct MsgBank *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *sub_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);

void *func_0202441C(const struct Struct_0202441C *obj, u32 heapId)
{
    void *str;
    void *bank;
    u16 hid = (u16)heapId;

    bank = sub_02045B38(0, 2, Table_0209F724[obj->arcFileIdx], hid);
    str = sub_02045EC0(bank, obj->strIdx);
    func_02045C04(bank);

    return str;
}
