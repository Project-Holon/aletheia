/*
 * function: func_02050804
 * address:  0x02050804
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050804.c \
 *       --func func_02050804 --addr 0x02050804 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020500A0(void *p);

void func_02050804(void *p, int idx, u32 v, u16 h)
{
    char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40);

    *(u32 *)(e + 8) = v;
    *(u16 *)(e + 12) = h;
    *(u16 *)(e + 14) = 0;
    func_020500A0(e);
}
