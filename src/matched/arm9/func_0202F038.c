/*
 * function: func_0202F038
 * address:  0x0202F038
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020437AC   0x020437AC  arm
 *   func_020307B0   0x020307B0  arm
 *   func_02045770   0x02045770  arm
 *   func_02043B5C   0x02043B5C  arm
 *   func_02045334   0x02045334  arm
 *   func_020452E8   0x020452E8  arm
 *   func_02030EAC   0x02030EAC  arm
 *   func_02031194   0x02031194  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F038.c \
 *       --func func_0202F038 --addr 0x0202F038 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_020437AC(u32 a);
extern void func_020307B0(void *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(u32 a, u32 b);
extern void func_02045334(struct Descriptor *a);
extern void func_020452E8(u32 a);
extern void func_02030EAC(u32 a);
extern void func_02031194(u32 n);

void func_0202F038(u8 *p)
{
    if (*(u32 *)p == 0 && *(u32 *)(p + 4) == 0) {
        func_020437AC(*(u32 *)(p + 0xC));
        func_020307B0(p);
        return;
    }

    *(u32 *)(p + 0x18) = 0;
    func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(p + 8)), *(u8 *)(p + 0x12));
    func_02045334((struct Descriptor *)*(u32 *)(p + 8));
    func_020452E8(*(u32 *)(p + 8));
    func_020437AC(*(u32 *)(p + 0xC));

    if (*(u32 *)p != 0) {
        func_02030EAC(*(u32 *)p);
        func_020307B0(p);
        return;
    }

    if (*(u32 *)(p + 4) != 0)
        func_02031194(*(u32 *)(p + 4));
}
