/*
 * function: func_021F9BA0
 * address: 0x021F9BA0
 * packet: pkt_ov186_021F9BA0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F9C84 0x021F9C84 thumb
 *   func_021F9CA4 0x021F9CA4 thumb
 */
typedef unsigned int u32;
typedef struct { u32 words[4]; } Info;
extern void func_021F9C84(Info *, unsigned, void *);
extern void func_021F9CA4(void *);
void func_021F9BA0(unsigned *ctx)
{
    Info info;
    if (ctx[25] != 0) {
        ctx[25]--;
        if (ctx[25] != 0) {
            unsigned idx = (unsigned short)((unsigned *)((char *)ctx + 0x48))[ctx[25]];
            func_021F9C84(&info, idx, (char *)ctx[1] + idx * 20);
            *(Info *)((char *)ctx + 0x3c) = info;
        } else {
            func_021F9CA4((char *)ctx + 0x3c);
        }
    } else {
        func_021F9CA4((char *)ctx + 0x3c);
    }
}
