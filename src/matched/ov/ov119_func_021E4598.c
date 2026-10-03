/*
 * function: func_021E4598
 * address: 0x021E4598
 * packet: pkt_ov119_021E4598
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arithmetic: full-word index and scroll ADD/SUB/MUL use modulo-2^32 arithmetic; casts restore the original signed comparisons.
 * symbols:
 *   func_02042FB0 0x02042FB0 arm
 *   func_02045780 0x02045780 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02042FB0(u32, u32, u32, u16);
struct Cfg;
struct Descriptor;
extern void func_02045780(struct Descriptor *p, u8 v);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32);
void func_021E4598(char *p)
{
    int x, y, scroll, first, i, n, pos, idx;
    int off1, off2, bound;
    char *q;
    scroll = *(short *)(p + 0x107C) / 8;
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 64; x++) {
            func_02042FB0(5, x, y, 0);
        }
    }
    if (*(short *)(p + 0x107C) < 96) first = *(int *)(p + 0x630);
    else first = (*(short *)(p + 0x107C) - 96) / 160;
    i = 0;
    off1 = 0x638; off1 = 0x6B8;
    off2 = 0x638; off2 = 0x6B8;
    bound = 0x638; bound = 0x630;
    for (; i < 3; i++) {
        idx = (int)((u32)first+(u32)i);
        n = *(int *)(p + bound);
        if (idx > n) idx = (int)((u32)idx-(u32)n-1u);
        else if (idx < 0) idx = (int)((u32)idx+(u32)n+1u);
        if (idx == n) {
            pos = (int)(*(u32 *)(p+0x638)-(u32)scroll);
            if (scroll > pos) scroll = (int)((u32)scroll-*(u32 *)(p+0x638));
            else pos = (int)(0u-(u32)scroll);
        } else pos = (int)((u32)idx*20u+12u-(u32)scroll);
        if (pos >= -10 && pos <= 33) {
            q = (char *)((u32)p+(u32)idx*4u);
            func_02045780(*(void **)(q + off1), pos + 1);
            func_02045374(*(void **)(q + off2));
        }
    }
    func_02041B6C(5);
}
