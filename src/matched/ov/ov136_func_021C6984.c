/*
 * function: func_021C6984
 * address:  0x021C6984
 * packet:   pkt_ov136_021C6984
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0       0x020056A0  thumb
 *   func_0203064C   0x0203064C  arm
 *   func_02030734        0x02030734  arm
 *   func_02030EAC   0x02030EAC  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4             0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_02082AC0    0x02082AC0  arm
 *   func_021C54FC 0x021C54FC thumb
 *   func_021C5508 0x021C5508 thumb
 *   func_021C5518 0x021C5518 thumb
 *   func_021C574C 0x021C574C thumb
 *   func_021C5828 0x021C5828 thumb
 *   func_021C587C 0x021C587C thumb
 *   func_021C5924 0x021C5924 thumb
 *   func_021C59B8 0x021C59B8 thumb
 *   func_021C5B40 0x021C5B40 thumb
 *   func_021C5C00 0x021C5C00 thumb
 *   func_021C5DD8 0x021C5DD8 thumb
 *   func_021C5E58 0x021C5E58 thumb
 *   func_021C6170 0x021C6170 thumb
 *   func_021C64A8 0x021C64A8 thumb
 *   func_021C7658  0x021C7658  thumb
 *   d_021C7F04 0x021C7F04 data a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021C7F04[];
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204363C(u32);
extern void func_0203064C(u32, u32, u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082AC0(u32, void *, u32);
extern void func_021C5B40(u8 *);
extern void func_021C5508(void);
extern void func_021C5518(u8 *);
extern void func_021C574C(u8 *);
extern void func_021C5828(u8 *);
extern void func_021C5E58(u8 *);
extern void func_021C587C(u8 *);
extern void func_021C64A8(u8 *);
extern void func_021C5DD8(u8 *);
extern void func_021C7658(u8 *);
extern void func_021C5924(u8 *);
extern void func_021C6170(u8 *);
extern void func_021C5C00(u8 *);
extern void func_021C59B8(u8 *);
extern void func_021C54FC(void);
extern void *func_020056A0(void (*)(void *), void *, u32);
extern void func_0203D34C(u32, u32);
int func_021C6984(u8 *p)
{
    if (*(void **)(p + 0x2C) != 0) {
        func_02030EAC(*(void **)(p + 0x2C));
        *(u32 *)(p + 0x2C) = 0;
    }
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0204363C(0);
    func_0203064C(1, 0x66, 0x60000);
    *(void **)(p + 8) = func_02030734(0x66, 0x370, 0, d_021C7F04, 0x10C);
    func_02082AC0(0, *(void **)(p + 8), 0x370);
    func_021C5B40(p);
    func_021C5508();
    func_021C5518(p);
    func_021C574C(p);
    func_021C5828(p);
    func_021C5E58(p);
    func_021C587C(p);
    func_021C64A8(p);
    func_021C5DD8(p);
    func_021C7658(p);
    func_021C5924(*(u8 **)(p + 8));
    func_021C6170(p);
    func_021C5C00(p);
    func_021C59B8(p);
    *(void **)(p + 0x2C) = func_020056A0((void (*)(void *))func_021C54FC, p, 1);
    func_0203D34C(0, 0x66);
    return *(u32 *)(p + 0x28);
}
