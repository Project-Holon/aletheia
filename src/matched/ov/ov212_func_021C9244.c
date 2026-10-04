/*
 * function: func_021C9244
 * address: 0x021C9244
 * packet: pkt_ov212_021C9244
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 66 bytes of code, then 2 bytes of alignment padding (021C9286);
 *   021C9288 is its own labelled function.
 * behavior: the switch has no default and result is assigned only in cases
 *   0/1, exactly as the original: its default path (021C9268 b 021C927C)
 *   skips every r4 write and 021C9282 returns r4 unset. Writing a defined
 *   default changes the bytes (the previous lane's DIFF32); see
 *   docs/idioms/switch-arms-tail-merge.md for the same no-default shape.
 * symbols:
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CA78 0x0200CA78 thumb
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Blk37;
extern void *func_0200CA1C(void *a);
extern void func_0200CA78(struct Blk37 *p, u32 v);
extern void func_020307B0(void *p);
int func_021C9244(char *p)
{
    struct Blk37 *save;
    char *q;
    int result;
    save = func_0200CA1C(*(void **)*(char **)p);
    q = *(char **)(p + 0x28);
    func_0200CA78(save, (*(u16 **)(q + 8))[*(u16 *)(q + 14)]);
    switch (*(int *)(q + 0x10)) {
    case 0:
        *(u16 *)(*(char **)p + 14) = 1;
        result = 9;
        break;
    case 1:
        *(u16 *)(*(char **)p + 14) = 0;
        result = 3;
        break;
    }
    func_020307B0(*(void **)(p + 0x28));
    return result;
}
