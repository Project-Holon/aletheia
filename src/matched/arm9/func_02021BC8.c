/*
 * function: func_02021BC8
 * address:  0x02021BC8
 * packet:   pkt_02021B6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02021930   0x02021930  thumb
 *   func_02021C20   0x02021C20  thumb
 *   func_02021CA8   0x02021CA8  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 func_02021930(u32 val, int bit);
extern void func_02021C20(void *dst0, void *dst1, void *src, u32 arg);
struct S;
extern void func_02021CA8(u8 *p, u32 idx, struct S *s);

struct S02021BC8 {
    u8  *p0;
    u8  *p1;
    u16  f8;
    u16  fA;
    u16  field0xc;
};

void func_02021BC8(u8 *p, u32 idx, u32 arg)
{
    u32 i;
    struct S02021BC8 *s = (struct S02021BC8 *)(p + idx * 0x14);

    for (i = 0; i < 0x10; i++) {
        if (func_02021930(s->field0xc, (u16)i)) {
            u32 off = (i * arg) * 2;
            func_02021C20(s->p0 + off,
                          s->p1 + off,
                          (u8 *)s + 0xc,
                          arg);
        }
    }

    func_02021CA8(p, (u8)idx, (struct S *)((u8 *)s + 0xc));
}
