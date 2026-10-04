/*
 * function: func_0218456C
 * address:  0x0218456C
 * packet:   pkt_ov023_0218456C
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020434CC  0x020434CC  arm
 *   func_02043588  0x02043588  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_021848D0  0x021848D0  thumb  ov023
 *   func_021848E0  0x021848E0  thumb  ov023
 *   func_0202208C  0x0202208C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02184B78  0x02184B78  thumb  ov023
 *   func_020056A0  0x020056A0  thumb
 *   func_0218489C  0x0218489C  thumb  ov023
 *   func_021849F8  0x021849F8  thumb  ov023
 *   func_02184C48  0x02184C48  thumb  ov023
 *   func_02184D30  0x02184D30  thumb  ov023
 *   func_02184ECC  0x02184ECC  thumb  ov023
 *   func_02186564  0x02186564  thumb  ov023
 *   func_021841E0  0x021841E0  thumb  ov023
 *   func_021866C4  0x021866C4  thumb  ov023
 *   func_0203D34C  0x0203D34C  arm
 *   func_02049238  0x02049238  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct W {
    u32 f0;
    u32 f4;
    void *f8;
    void *fc;
    u32 f10;
    void *f14;
} W;

extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern W *func_0203159C(void *task, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
struct GfFont;
struct MsgBank;
extern void func_0203F8F4(u16 heapId);
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_021848D0(void);
extern void func_021848E0(void);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02184B78(W *p, void *h);
extern void *func_020056A0(void (*cb)(void), void *ctx, int z);
extern void func_0218489C(void);
extern void func_021849F8(W *p);
extern void func_02184C48(W *p, void *h);
extern void func_02184D30(W *p);
extern void func_02184ECC(W *p, void *task);
extern void func_02186564(void);
extern void func_021841E0(u32 a);
extern void func_021866C4(W *p);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02049238(void *h);

int func_0218456C(void *task, int *state, u32 arg)
{
    W *w;
    void *h;

    switch (*state) {
    case 0:
        func_020434CC();
        func_02043588();
        func_0203064C(1, 0x28, 0x50000);
        w = func_0203159C(task, 0x9e84, 0x28);
        func_02082BCC(w, 0, 0x9e84);
        func_0203F8F4(0x28);
        w->f10 = (u32)func_0201EC64(0x28);
        w->f14 = func_02045B38(0, 2, 0x53, 0x28);
        w->fc = func_0201D7EC(0x17, 0, 0, 0, 0x28);
        func_021848D0();
        func_021848E0();
        func_0202208C(0, 9, 9, 0, 0x10, 1, 0x28);
        w->f4 = arg;
        h = func_020490F4(0xbf, 0x28);
        func_02184B78(w, h);
        w->f8 = func_020056A0(func_0218489C, w, 0);
        func_021849F8(w);
        func_02184C48(w, h);
        func_02184D30(w);
        func_02184ECC(w, task);
        func_02186564();
        func_021841E0((u32)w);
        func_021866C4(w);
        func_0203D34C(1, 0x28);
        func_02049238(h);
        (*state)++;
        break;
    case 1:
        *state = 0;
        return 1;
    }
    return 0;
}
