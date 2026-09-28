/*
 * function: func_020178D8
 * address:  0x020178D8
 * packet:   pkt_0201756C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020178D8.c \
 *       --func func_020178D8 --addr 0x020178D8 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern u32  func_02017D30(void *p);
extern void func_02017900(void *p, u32 a);
extern void func_020185C4(void *p);
extern void func_02017D70(void *p, u32 v);

void func_020178D8(void *p, u32 a)
{
    u8 v = (u8)func_02017D30(p);

    func_02017900(p, a);
    func_020185C4(p);
    func_02017D70(p, v);
}

