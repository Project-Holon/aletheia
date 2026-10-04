/*
 * function: func_021D9D3C
 * address: 0x021D9D3C
 * packet: pkt_ov123_021D9D3C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note-2026-10-04: DIFF. Whole structure and every slot matches (declaration order base0, base1, h, done, k, j, i, cur reproduces slots 0x18..0x2c; j doubles as the zero args). Residue: compiler hoists constant 3 into r5 (movs r5,#3 after the first func_02049B68 call) and reuses it for the last func_020498F4 r2, so the last call also gets r3=[j slot] instead of movs r3,#0, and +2 bytes shift everything after. Original keeps literals. Also original loads heap into r5 before func_02082BCC (adds r3,r5 for 02049F78); an explicit u16 heap local did not remove the hoist. Tried param types u16 on 49B68/49658/498F4 arg2: no effect. Next: find what stops the const-3 hoist (different source of 3 in calls 1/4 or a call between).
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02021F64 0x02021F64 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021D9F40 0x021D9F40 thumb ov123
 *   func_0207D63C 0x0207D63C arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u16 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern void func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02082BCC(void *, u8, u32);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *, u32);
extern void func_020307B0(void *);
extern void func_02021F64(u16 *, u16 *, int, u8, u16);
extern void func_020862F0(void *, int);
extern void *func_020056A0(void *, void *, int);
extern void func_021D9F40(void *, char *);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_02049238(void *);
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
    u16 *src;
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
    func_02082BCC(p + 8, 0, 0x970);
    allocated = func_02049F78(h, 2, (u32)&record, heap);
    func_02082D44(*(void **)((u8 *)record + 0xc), p + 0x10, 0x1e0);
    func_02082D44(*(void **)((u8 *)record + 0xc), p + 0x1f0, 0x1e0);
    func_020307B0(allocated);
    base1 = (u16 *)(p + 0x1f0);
    base0 = (u16 *)p;
    base0 = (u16 *)(p + 0x10);
    for (i = 0; i < 15; i++) {
        t = i + 1;
        if (t >= 15) t -= 15;
        k = 0;
        done = 0;
        cur = (u16 *)(p + t * 32);
        while (1) {
            dst = base0 + i * 16;
            src = base1 + j * 16;
            for (m = 4; m < 11; m++) {
                func_02021F64(dst + m, src + m, 1, (u8)(k >> 8), cur[m + 8]);
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
    func_02049238(h);
}
