/*
 * function: func_021BB784
 * address: 0x021BB784
 * packet: pkt_ov217_021BB784
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   func_021BB98C 0x021BB98C thumb ov217
 *   func_021BB990 0x021BB990 thumb ov217
 *   func_021BBB60 0x021BBB60 thumb ov217
 *   func_021BC2D8 0x021BC2D8 thumb ov217
 *   func_021BC338 0x021BC338 thumb ov217
 *   func_021BC43C 0x021BC43C thumb ov217
 *   func_021BC168 0x021BC168 thumb ov217
 *   func_021BC014 0x021BC014 thumb ov217
 *   func_021BBF60 0x021BBF60 thumb ov217
 *   func_021BC2FC 0x021BC2FC thumb ov217
 *   func_021BC5B8 0x021BC5B8 thumb ov217
 *   func_021BC72C 0x021BC72C thumb ov217
 *   func_021BC50C 0x021BC50C thumb ov217
 *   func_021BC55C 0x021BC55C thumb ov217
 *   func_021BB91C 0x021BB91C thumb ov217
 *   func_021C1038 0x021C1038 thumb ov217
 */
struct S { char pad0[0x32]; unsigned char f32; char pad33[0x81]; void *arr[8]; };
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021BB98C(void *p);
extern void func_021BB990(void *p);
extern void func_021BBB60(struct S *p);
extern void func_021BC2D8(struct S *p);
extern void func_021BC338(struct S *p);
extern void func_021BC43C(struct S *p);
extern void func_021BC168(unsigned int p);
extern void func_021BC014(struct S *p);
extern void func_021BBF60(struct S *p);
extern int func_021BC2FC(void *p);
extern u32 func_021BC5B8(u32 a0, u32 a1);
extern void func_021BC72C(u8 *a0, u32 a1, u8 *a2);
extern void func_021BC50C(struct S *p);
extern u32 func_021BC55C(u32 a0);
extern void func_021BB91C(void *p);
extern void func_021C1038(u8 *p, u8 palette);

void func_021BB784(struct S *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBB60(p);
        func_021BB990(p);
        break;
    case 1:
        func_021BC2D8(p);
        func_021BC338(p);
        func_021BC43C(p);
        func_021BC168((unsigned int)p);
        func_021BC014(p);
        func_021BBF60(p);
        if (func_021BC2FC(p) != 0) {
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC5B8((u32)p, 5) != 0) {
            func_021BC72C((u8 *)p, 0, 0);
            func_021BC72C((u8 *)p, 1, 0);
            func_021BC72C((u8 *)p, 2, 0);
            func_021BBF60(p);
            func_021BC50C(p);
            func_021BB990(p);
        }
        break;
    case 3:
        if (func_021BC55C((u32)p) != 0) {
            func_021C1038(p->arr[p->f32], 15);
            func_021BB91C(p);
        }
        break;
    }
}
