/*
 * function: func_021D9D3C
 * address: 0x021D9D3C
 * packet: pkt_ov123_021D9D3C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wD9r lane50): closed. func_02049658 returns a value (it ends in a call whose r0 it
 *   keeps; ov110 func_021BB328 declares it u32); declared void, it moved the constant 3 into r5 and
 *   tied the late zero arguments to j. The two palette bases are assigned inside the outer loop (mwcc
 *   hoists them after i = 0), and the source row is written inline in the 02021F64 call.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   PALANM_BlendColors 0x02021F64 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021D9F40 0x021D9F40 thumb ov123
 *   func_0207D63C 0x0207D63C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern u32 func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void MI_CpuFill8(void *, u8, u32);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_020307B0(void *p);
extern void PALANM_BlendColors(u16 *, u16 *, int, u8, u16);
extern void func_020862F0(void *, int);
extern void *func_020056A0(void *, void *, int);
extern void func_021D9F40(void *, char *);
extern void func_0207D63C(void *, int, int, int, int);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021D9D3C(char *p)
{
    void *record;
    u16 *base0;
    u16 *base1;
    void *h;
    int done;
    int k;
    int j;
    int i;
    u16 *cur;
    void *allocated;
    int m;
    int t;
    u16 *dst;
    u16 heap;
    h = func_020490F4(0x91, *(u16 *)(p + 0x9e4));
    j = 0;
    func_02049B68(h, 3, 4, 0, j, *(u16 *)(p + 0x9e4));
    func_02049658(h, 4, 4, 0, j, j, *(u16 *)(p + 0x9e4));
    func_020498F4(h, 6, 4, 0, j, j, *(u16 *)(p + 0x9e4));
    func_02049B68(h, 3, 0, 0, j, *(u16 *)(p + 0x9e4));
    func_02049658(h, 4, 0, 0, j, j, *(u16 *)(p + 0x9e4));
    func_020498F4(h, 5, 0, 0, j, j, *(u16 *)(p + 0x9e4));
    func_02049658(h, 4, 3, 0, j, j, *(u16 *)(p + 0x9e4));
    func_020498F4(h, 7, 3, 0, j, j, *(u16 *)(p + 0x9e4));
    heap = *(u16 *)(p + 0x9e4);
    MI_CpuFill8(p + 8, 0, 0x970);
    allocated = func_02049F78(h, 2, (u32)&record, heap);
    func_02082D44(*(void **)((u8 *)record + 0xc), p + 0x10, 0x1e0);
    func_02082D44(*(void **)((u8 *)record + 0xc), p + 0x1f0, 0x1e0);
    func_020307B0(allocated);
    for (i = 0; i < 15; i++) {
        base1 = (u16 *)(p + 0x1f0);
        base0 = (u16 *)(p + 0x10);
        t = i + 1;
        if (t >= 15) t -= 15;
        k = 0;
        done = 0;
        cur = (u16 *)(p + t * 32);
        while (1) {
            dst = base0 + i * 16;
            for (m = 4; m < 11; m++) {
                PALANM_BlendColors(dst + m, base1 + j * 16 + m, 1, (u8)(k >> 8), cur[m + 8]);
            }
            j++;
            if (done == 1) break;
            k += 0x600;
            if (k >= 0x1000) {
                k = 0x1000;
                done = 1;
            }
        }
    }
    func_020862F0(p + 0x1f0, 0x780);
    *(u32 *)(p + 0xc) = 1;
    *(void **)(p + 8) = func_020056A0((void *)func_021D9F40, p + 8, 0x14);
    func_0207D63C((void *)0x04000050, 1, 8, 8, 0x10);
    *(u8 *)(p + 0x974) = 0;
    ARC_TOOL_DeleteHandle(h);
}
