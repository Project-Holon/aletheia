/*
 * function: func_021BBB60
 * address: 0x021BBB60
 * packet: pkt_ov093_021BBB60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Lever: declare i before result for stack order; declare j inside the
 * q-tested block for the original q/j register allocation.
 * extent: followed by padding and separately matched accessor 0x021BBC34.
 * symbols:
 *   func_021B8714 0x021B8714 thumb ov093
 *   func_021C3B68 0x021C3B68 thumb ov093
 *   func_021BB878 0x021BB878 thumb ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021BD8F0 0x021BD8F0 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B8750 0x021B8750 thumb ov093
 *   func_021BDA00 0x021BDA00 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021B8714(void *);
extern int func_021C3B68(u8 *, int, u8);
extern u8 *func_021BB878(void *, u8);
extern void *func_021B9BF0(void *, u8);
extern int func_021D5B68(void *);
extern void func_021BD8F0(u8 *, u8, u8, u8);
extern int func_021B8588(void *);
extern void func_021B8750(void *, u8, void *);
extern int func_021BDA00(u8 *);
int func_021BBB60(u8 *p)
{
    u8 *initial;
    u32 i;
    int result;
    void *m;
    u32 *out = *(u32 **)(p + 12);
    out[0] = 0;
    result = 0;
    out[1] = 0;
    initial = func_021B8714(*(void **)(p + 4));
    if (initial[8] && func_021C3B68(p, initial[8], 255)) result = 1;
    for (i = 0; i < 4; i++) {
        u8 *q = func_021BB878(*(void **)p, i);
        if (q) {
            u32 j;
            for (j = 0; j < q[9]; j++) {
                m = func_021B9BF0(*(void **)(q + 4), j);
                if (m && !func_021D5B68(m)) func_021BD8F0(p, i, j, j);
            }
            if (func_021B8588(*(void **)(p + 4)) == 3) {
                for (j = 0; j < 3; j++) {
                    m = func_021B9BF0(*(void **)(q + 4), j);
                    if (m && !func_021D5B68(m)) func_021B8750(*(void **)(p + 4), i, m);
                }
            }
        }
    }
    if (func_021BDA00(p)) result = 1;
    return result;
}
