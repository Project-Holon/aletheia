/*
 * function: func_021F5390
 * address:  0x021F5390
 * packet:   pkt_ov083_021F5390
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct. Only blocker: func_02010F7C (arm9, thumb, unlabelled tail-call
 * stub, 0x02010F7C..0x02010F8C; Ilias's leaf). Its verified body (EXACT with
 * symbols: func_02048F60  0x02048F60  arm):
 *     extern int func_02048F60(int a, int b, int c);
 *     int func_02010F7C(int a) { return func_02048F60(0x26, 0, a); }
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02010F7C  0x02010F7C  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
    int f30;
    int f34;
    int f38;
} Work;

typedef unsigned char  u8;
struct Ctx;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02188C54(u8 *p);
extern void *func_02188C7C(u8 *p);
extern void *func_02010F7C(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0216D9A0(void *map);

void func_021F5390(Work *p, int a1, int a2)
{
    p->f2 = 0x15;
    p->f4 = (p->f2 & 0x7FFF) | 0x8000;
    p->f10 = a2;
    p->f8 = a1;
    p->fC = (int)func_020120F4((const struct Ctx *)a1);
    p->f14 = func_02188C54((u8 *)p->f10);
    p->f1C = (int)func_02188C7C((u8 *)p->f10);
    p->f30 = (int)func_02010F7C(p->f2);
    p->f28 = (int)func_02045B38(0, 3, 0x108, p->f2);
    p->f2C = (int)func_0201EC64(p->f2);
    p->f34 = (int)func_020457B0(0x81, p->f2);
    p->f38 = (int)func_020457B0(0x81, p->f2);
    func_0216D9A0((void *)p->f1C);
}
