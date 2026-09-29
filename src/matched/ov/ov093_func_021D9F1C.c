/*
 * function: func_021D9F1C
 * address:  0x021D9F1C
 * packet:   pkt_ov093_021D9F1C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_0201BEB8   0x0201BEB8  thumb
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D5B68   0x021D5B68  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021D7B74   0x021D7B74  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int func_021D775C(int a);
extern int func_0201BEB8(u16 id, u32 bit);
extern void *func_021C7CF4(int a, int b);
extern int func_021D5B68(void *p);
extern void *func_021C88A4(int a, int k, int b);
extern int func_021D7B74(void *p, int k);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, int a);
extern void func_021C88C8(int a, void *p);

void func_021D9F1C(int a, int b, int c)
{
    u8 *p;
    u8 k;
    void *m;

    if (c != func_021D775C(4))
        return;
    if (func_021D5B68(func_021C7CF4(b, c)) == 0)
        return;
    if (func_0201BEB8(func_021D775C(0x12), 0) == 0)
        return;
    k = func_021D775C(3);
    m = func_021C7CF4(b, k);
    p = func_021C88A4(b, 7, c);
    *(u32 *)p |= 4 << 21;
    *(u8 *)(p + 6) = k;
    *(u16 *)(p + 4) = func_021D7B74(m, 4);
    p[7] = (p[7] & ~1) | 1;
    func_021C8838(p + 0xc, 2, 0x192);
    func_021C8860(p + 0xc, k);
    func_021C88C8(b, p);
}
