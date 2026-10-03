/*
 * function: func_021F9BF4
 * address: 0x021F9BF4
 * packet: pkt_ov186_021F9BF4
 * region: ov186
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_021F9C84 0x021F9C84 thumb
 *   d_02200D14 0x02200D14 data a1
 */
typedef struct { unsigned words[4]; } Info;
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021F9C84(Info *, unsigned, void *);
extern char d_02200D14[];
void func_021F9BF4(unsigned *ctx, unsigned index)
{
    Info info;
    char *base = (char *)ctx[1];
    char *entry = base + index * 20;
    if (index >= *(unsigned short *)((char *)ctx + 8))
        func_02034714(d_02200D14, 0, d_02200D14);
    func_021F9C84(&info, index, entry);
    if (ctx[25] >= 6)
        func_02034714(d_02200D14, 0, d_02200D14);
    ((unsigned (*)[6])((char *)ctx + 0x4c))[0][ctx[25]] = index;
    ctx[25]++;
    *(Info *)((char *)ctx + 0x3c) = info;
}
