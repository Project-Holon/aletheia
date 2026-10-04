/*
 * function: func_02197B5C
 * address:  0x02197B5C
 * packet:   pkt_ov021_02197B5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 *   func_02196768  0x02196768  thumb  ov021
 *   func_02155A8C  0x02155A8C  thumb  ov010
 *   func_0202F038  0x0202F038  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021974A0  0x021974A0  thumb  ov021
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_02027858  0x02027858  thumb
 *   func_02028148  0x02028148  thumb
 *   func_02027FD8  0x02027FD8  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020221A4(void);
extern void func_02196768(u32 *);
extern void func_02155A8C(u8 *, u32);
struct Bank;
struct Descriptor;
struct Node;
struct PrintSys;
struct Rec3;
struct S02031140;
struct TaskMenu;
struct TaskMenuState;
extern void func_0202F038(u8 *p);
extern void func_020307B0(void *p);
extern void func_021974A0(u32 *);
extern void func_0201CE48(struct Rec3 *p);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern void func_020403F4(u32);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020452E8(struct Descriptor *d);
extern void func_02027858(struct TaskMenu *m);
extern void func_02028148(u8 *p);
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_02030EAC(struct Node *n);
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);

int func_02197B5C(u32 a, u32 b, u8 *c, u32 *d)
{
    if (!func_020221A4()) {
        return 0;
    }
    func_02196768(d);
    func_02155A8C(c, d[2]);
    *(u32 *)(c + 0x58) = d[3];
    if (d[0xBA] != 0) {
        func_0202F038((u8 *)d[0xBA]);
        d[0xBA] = 0;
    }
    func_020307B0((void *)d[0xBB]);
    func_020307B0((void *)d[0xBC]);
    func_021974A0(d);
    if (d[0xAD] != 0) {
        func_0201CE48((struct Rec3 *)d[0xAD]);
    }
    func_02028604(d[0xAA]);
    func_02031140((struct S02031140 *)d[0xAE]);
    func_020403F4(7);
    func_0201C6EC((struct PrintSys *)d[0xAF]);
    func_0201C4C0((struct PrintSys *)d[0xAF]);
    if (d[0xAC] != 0) {
        func_020452E8((struct Descriptor *)d[0xAC]);
    }
    if (d[0xB0] != 0) {
        func_02027858((struct TaskMenu *)d[0xB0]);
        d[0xB0] = 0;
    }
    if (d[0xB8] != 0) {
        func_02028148((u8 *)d[0xB8]);
    }
    func_02027FD8((struct TaskMenuState *)d[0xB7]);
    func_02030EAC((struct Node *)d[0x9A]);
    func_0204B1CC((struct Bank *)d[0x9B]);
    func_0204A5AC();
    func_020450C8();
    func_0203F9B4();
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(0x1f);
    return 1;
}
