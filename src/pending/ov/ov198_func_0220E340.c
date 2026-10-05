/*
 * function: func_0220E340
 * address:  0x0220E340
 * packet:   pkt_ov198_0220E340
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note 2026-10-05 (wD5 lane18): tried arr only at the use site (`((int *)(p+0x24A4))[i]`, 180 B, 143 differ), arr assigned inside the loop, and `for (i = 0, arr = ...)` with `*arr++` (176 B, 75 differ). The r6/r7 swap of arc and arr stays only in the 9-byte form.
 * 2026-10-05 (wD4 lane16): also tried arr = (int *)p + 0x929, int loop counter (much worse), arc/arr/x declaration orders, and a temp for the call result before arr[i]: all 9 bytes, r6/r7 swap unchanged.
 * symbols:
 *   func_0220E340  0x0220E340  thumb  ov198
 *   func_020490F4  0x020490F4  arm
 *   func_020185F4  0x020185F4  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCEC  0x0201BCEC  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 */
/*
 * 2026-10-04 (wave D2 lane03): DIFF, unchanged (9 bytes, pure r6/r7 swap of arc and arr). Also tried:
 * arr as a u8 * base with `*(int *)(arr + i*4)`, and `register void *arc`: still 9 bytes.
 * In the original the BC78 result is held in r6 (arr's register) across the BCEC call, same as mine in r7.
 */
/*
 * 2026-10-04 (wave D1 lane07): DIFF, same size (176), logic matches. Residue: r6/r7 swapped
 * everywhere: the original has arc in r7 and the p+0x24A4 array base in r6, mine the reverse.
 * Tried: declaration order arc/arr, arr computed before the arc call (hoists everything, worse),
 * no arr local with raw *(int *)(p + 0x24A4 + i * 4) (worse).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_020185F4(void *p);
extern u32 func_0201BA68(void *mon);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *h, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);

void func_0220E340(u8 *p)
{
    int *arr;
    void *arc;
    u16 i;
    u32 x;

    arc = func_020490F4(7, (*(u16 *)(*(u8 **)p + 0x10) & 0x7FFF) | 0x8000);
    arr = (int *)(p + 0x24A4);
    for (i = 0; i < 6; i++) {
        u8 *e = p + i * 0x4C;
        if (*(u16 *)(e + 8) != 0) {
            x = func_0201BA68(func_020185F4(*(void **)(e + 4)));
        } else {
            x = func_0201BABC(0, 0, 0, 0);
        }
        arr[i] = func_0204A6C8(arc, x, 0, 1, *(u16 *)(*(u8 **)p + 0x10));
    }
    *(int *)(p + 0x250C) = func_0204ACEC(arc, func_0201BC3C(), 1, 0, *(u16 *)(*(u8 **)p + 0x10));
    *(s32 *)(p + 0x2524) = func_0204AF28(arc, func_0201BC78(), func_0201BCEC(), *(u16 *)(*(u8 **)p + 0x10));
    func_02049238(arc);
}
