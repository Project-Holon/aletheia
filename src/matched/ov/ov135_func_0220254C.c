/*
 * function: func_0220254C
 * address:  0x0220254C
 * packet:   pkt_0220254C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02019B58  0x02019B58  thumb
 *   func_02045A90  0x02045A90  arm
 *   func_02017E40  0x02017E40  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_02008F08  0x02008F08  thumb
 *   func_02008F88  0x02008F88  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02045808  0x02045808  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
struct Rec;
struct Sub02008F80Obj;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045C04(struct Rec *rec);
extern void func_02019B58(void *mon);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_02017E40(void *mon, u32 id, u32 v);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u32 func_0202136C(u16 v);
extern void *func_02008F08(int a0);
extern void func_02008F88(struct Sub02008F80Obj *obj, const void *src);
extern u32 func_020307B0(void *p);
extern void func_02045808(struct U16Vec *vec);

void func_0220254C(void *mon, u32 heap)
{
    void *bank;
    void *str;
    void *buf;
    u32 id;

    id = (heap & 0x7FFF) | 0x8000;
    bank = func_02045B38(0, 2, 0x51, (u16)id);
    str = func_02045EC0(bank, 0xF);
    func_02045C04(bank);
    func_02019B58(mon);
    func_02017E40(mon, 0x8E, (u32)func_02045A90(str));
    if (func_0202136C((u16)func_02017E1C(mon, 6, 0)) != 0) {
        buf = func_02008F08((u16)id);
        func_02017E1C(mon, 0xA7, (u32)buf);
        func_02008F88(buf, func_02045A90(str));
        func_02017E40(mon, 0xA7, (u32)buf);
        func_020307B0(buf);
    }
    func_02045808(str);
}
