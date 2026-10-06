/*
 * function: func_021DD368
 * address: 0x021DD368
 * packet: pkt_ov093_021DD368
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D5584 0x021D5584 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct QG;
extern void *func_021C7CF4(int *p, int i);
extern u8 func_021D5448(struct QG *p);
struct UtilWork;
extern u8 func_021D5584(struct UtilWork *p, u32 i);
u8 func_021DD368(void *a, int b)
{
    void *m;
    u32 n, i;
    m = func_021C7CF4(a, b);
    n = func_021D5448(m);
    for (i = 0; i < n; i++) {
        if (func_021D5584(m, (u8)i) == 0) return (u8)i;
    }
    return 4;
}
