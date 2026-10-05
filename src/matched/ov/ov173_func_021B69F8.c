/*
 * function: func_021B69F8
 * address: 0x021B69F8
 * packet: pkt_ov173_021B69F8
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * 2026-10-05: func_02035C60 is declared int here (as in ov173 func_021B68C8): the listing tests r0 after it,
 * but its matched arm9 definition is void (tail call of func_02035C48, which returns a value).
 */
typedef unsigned int u32;
extern u32 func_0201CE30(void *p);
extern void func_020286C4(void *ctx, void *p, void *cell);
extern u32 func_0203630C(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_0201CE5C(void *p, int v);
extern void func_0201CE48(void *p);
extern void func_0201CE38(void *p);
extern void func_020061E4(unsigned);

int func_021B69F8(char *p)
{
    u32 r = func_0201CE30(*(void **)(p + 0x6c));
    func_020286C4(*(void **)(p + 0x21c), *(void **)(p + 0x6c), *(void **)(p + 0x20));
    if (r == 0) {
        if (func_0203630C() & 1)
            func_0201CE5C(*(void **)(p + 0x6c), 0);
    } else if (r == 2) {
        func_0201CE48(*(void **)(p + 0x6c));
        return *(int *)(p + 0x1b0);
    } else if (r == 1) {
        if ((func_020362DC() & 3) || func_02035C60()) {
            func_0201CE38(*(void **)(p + 0x6c));
            func_020061E4(0x547);
        }
    }
    return 2;
}
