/*
 * function: func_0201493C
 * address:  0x0201493C
 * packet:   pkt_0201493C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The three-way fallback load of the 0x34-byte time-of-day table (member
 * 0x3e for an explicit id, 0x52 for the id func_02013F2C maps, else 0x3d
 * built through func_0201407C), then func_02014A80 over it and a free.
 *
 * Closed in wave 13 by the declaration, not the body: the seventh
 * parameter is a u16 heap id (the ov094 caller at 0x021F7702 loads it
 * with ldrh), written `(heap & 0x7fff) | 0x8000` at each of the four
 * uses.  The earlier note (docs/notes/pkt_0201493C.c.txt) read it as the
 * low half of a word through `*(u16 *)((char *)&b0 + 8)` and had to spell
 * the first tag as 0x10000000; with the real parameter type both of its
 * "back-end tie-breaks" (the pooled 0x0FFFFFFF + 1 tag and the late b0
 * reload) disappear.
 *
 * symbols:
 *   func_02014A10  0x02014A10  thumb
 *   func_02014A20  0x02014A20  thumb
 *   func_02013F2C  0x02013F2C  thumb
 *   func_02013B38  0x02013B38  thumb
 *   func_0201407C  0x0201407C  thumb
 *   func_020140DC  0x020140DC  thumb
 *   func_020140B4  0x020140B4  thumb
 *   func_02014A80  0x02014A80  thumb
 *   sub_020307B0   0x020307B0  arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef unsigned char  u8;
struct Sub020140BCObj;
extern u16 func_02014A10(u32 i);
extern void *func_02014A20(u32 archive, u32 member, u32 *count, u16 heap);
extern u32 func_02013F2C(u32 id);
extern u32 func_02013B38(u32 id);
extern void *func_0201407C(u16 heap, u32 a, u32 b);
extern u8 func_020140DC(struct Sub020140BCObj *p);
extern void  func_020140B4(void *q);
extern void func_02014A80(u8 *a0, u32 a1, s32 a2, u32 a3, u16 *out);
extern void  sub_020307B0(void *p);
void func_0201493C(u32 id, u32 a1, u32 a2, u32 a3,
                   u32 b0, u16 *b1, u16 heap)
{
    u32 count;
    void *p = 0;
    s32 o2;
    s32 o1;

    o1 = a2 * 0x3c;
    o2 = a1 * 0xe10;

    if (a3 != 0) {
        p = func_02014A20(0x3e, func_02014A10(a3), &count, (heap & 0x7fff) | 0x8000);
    }
    if (p == 0) {
        u32 t = func_02013F2C((u16)id);
        if (t != 0xfffffff)
            p = func_02014A20(0x52, t, &count, (heap & 0x7fff) | 0x8000);
    }
    if (p == 0) {
        void *q = func_0201407C((heap & 0x7fff) | 0x8000, func_02013B38((u16)id), b0);
        p = func_02014A20(0x3d, func_020140DC(q), &count, (heap & 0x7fff) | 0x8000);
        func_020140B4(q);
    }
    func_02014A80(p, count, o1 + o2, b0, b1);
    sub_020307B0(p);
}
