/*
 * function: func_021D9874
 * address: 0x021D9874
 * packet: pkt_ov175_021D9874
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021D98B6..021D98B8 is two zero alignment bytes.
 * symbols:
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_021E7E3C 0x021E7E3C thumb ov177
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 */
extern int func_021E5548(int *);
extern void *func_02012EBC(void *);
extern void *func_0200BAC8(void *);
extern void *func_021E7E3C(void *, int, int, int, int, int, int);
void func_021D9874(char *ctx)
{
    int window;
    if (*(void **)(ctx + 0x24) == 0) {
        window = func_021E5548(*(int **)ctx);
        *(void **)(ctx + 0x24) = func_021E7E3C(func_0200BAC8(func_02012EBC(**(void ***)(*(char **)(ctx + 0x104) + 8))), window, *(int *)(ctx + 4), *(int *)(ctx + 0xc), *(int *)(ctx + 0x10), *(int *)(ctx + 0x14), 87);
    }
}
