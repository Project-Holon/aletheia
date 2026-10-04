/*
 * function: func_021880C8
 * address:  0x021880C8
 * packet:   pkt_ov021_021880C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D3688     0x021D3688  data
 *   d_021D3604     0x021D3604  data
 *   d_021DD9C0     0x021DD9C0  data
 *   abs_id_19      0x00000013  data
 *   abs_id_18      0x00000012  data
 *   func_020433E0  0x020433E0  arm
 *   func_02188D5C  0x02188D5C  thumb
 *   func_0204A48C  0x0204A48C  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02045088  0x02045088  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_02046440  0x02046440  arm
 *   func_02188E50  0x02188E50  thumb
 *   func_02188EE4  0x02188EE4  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0218C9E8  0x0218C9E8  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02189108  0x02189108  thumb
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_021C6D10  0x021C6D10  thumb
 *   func_021D317C  0x021D317C  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02035660  0x02035660  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 d_021D3688[];
extern u8 d_021D3604[];
extern char d_021DD9C0[];
extern u8 abs_id_19[];
extern u8 abs_id_18[];

extern void func_020433E0(void *a);
extern void func_02188D5C(u16 *p);
struct BigObj;
struct Cfg;
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
struct Ctx;
extern void func_02045088(u16 heapId);
extern void func_0201DD60(void);
extern void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                          u32 fifoSize, u32 heap, void (*setup)(void));
extern void func_02188E50(void);
extern void func_02188EE4(u8 *p);
extern u8 func_02012984(const struct BigObj *p);
extern char *func_0218C9E8(int heap, int b);
extern void *func_020056A0(void (*cb)(int, u8 *), void *arg, int pri);
extern void func_02189108(int unused, u8 *p);
extern u32 func_02030CB0(u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern u8 *func_021C6D10(int n, int heap);
extern void *func_021D317C(u32 heap);
extern u32 func_02013CC8(u32 id);
extern u32 func_02013CE0(u32 id);
extern int func_02034AC4(int id);
extern void func_02035660(u32 a);

int func_021880C8(int unused, u8 *p)
{
    u16 heap = *(u16 *)p;

    func_020433E0(d_021D3688);
    func_02188D5C((u16 *)p);
    func_0204A48C((const struct Cfg *)d_021D3604, (u32)d_021D3688, 0x89);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    func_02045088(heap);
    func_0201DD60();
    func_02046440(0, 3, 0, 1, 0x1000, *(u16 *)p, func_02188E50);
    func_02188EE4(p);
    *(char **)(p + 0x48) = func_0218C9E8(*(u16 *)p, func_02012984((const struct BigObj *)(*(int *)(p + 8))));
    *(void **)(p + 0xAC) = func_020056A0(func_02189108, p, 0);
    *(void **)(p + 0x114) = func_02030734(heap, func_02030CB0(0x20), 0, d_021DD9C0, 0x26B);
    *(void **)(p + 0x110) = func_02030CBC(0x20, *(void **)(p + 0x114));
    *(u8 **)(p + 0x134) = func_021C6D10(0xA, *(u16 *)p);
    *(void **)(p + 0x14C) = func_021D317C(*(u16 *)p);
    func_02034AC4((func_02013CC8(*(u16 *)(p + 0xD0)) == 1 || func_02013CE0(*(u16 *)(p + 0xD0)) == 1) ? (int)abs_id_19 : (int)abs_id_18);
    func_02035660(0x1E);
    return 1;
}
