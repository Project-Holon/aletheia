/*
 * function: func_021D29F0
 * address:  0x021D29F0
 * packet:   pkt_ov021_021D29F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045180  0x02045180  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02041300  0x02041300  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
typedef signed short   s16;
struct Cfg;
struct Descriptor;
struct MsgBank;
struct Rec;
struct U16Vec;
extern int func_02158F58(int a0);
typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 func_02188C84(u8 *p);
struct CharBuf;
struct Stream;
extern u32 func_02188C54(u8 *p);
extern u16 func_02011330(struct Stream *s);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045180(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u32 offset);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_021904AC(u8 *p);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02041B6C(u32);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045C04(struct Rec *rec);
extern void func_020452E8(struct Descriptor *d);
extern void func_02041300(int, int, int, int, int, int, int);

int func_021D29F0(u32 a, u32 b)
{
    void **q;
    u32 heap, msg, win, s;
    void *m;

    q = (void **)func_02158F58((int)func_0215A5F4((void *)b));
    heap = func_02188C84(q[1]);
    m = (void *)func_02188C54(q[1]);
    if (func_02011330((struct Stream *)a)) {
        msg = (u32)func_02045B38(0, 2, 0x16, heap);
        win = func_02045180(2, 1, 1, 0x1E, 10, 14, 0x40);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)win)), 0xF);
        func_02045334((struct Descriptor *)win);
        func_02045374((struct Cfg *)win);
        func_0201F73C((void *)win, 0, 1, 0xD);
        s = (u32)func_020457B0(0xB4, heap);
        func_02045CAC((struct MsgBank *)msg, 3, (void *)s);
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)win)), 0, 0, (void *)s, (void *)func_021904AC(m));
        func_02045334((struct Descriptor *)win);
        func_02041B6C(2);
        func_02045808((struct U16Vec *)s);
        func_02045C04((struct Rec *)msg);
        func_020452E8((struct Descriptor *)win);
    } else {
        func_02041300(2, 0, 0, 0, 0x20, 0xC, 0x11);
        func_02041B6C(2);
    }
    return 0;
}
