/*
 * Graduated from src/pending/; promoted once its blocker became a manifest entry.
 *
 * Previously blocked at MATCH on `label`: func_0202AEEC has exactly one branch reference
 * image-wide, this function's own call, so no witness exists outside the
 * compared range and no cut helps.  It closes when func_0202AEEC (pkt_0202AEEC)
 * acquires a manifest entry or a second caller appears.
 *
 * function: func_0202AB8C
 * address:  0x0202AB8C
 * packet:   pkt_0202AB8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker 0202AEEC is now a manifest entry (matched class)
 * symbols:
 *   func_02049030  0x02049030  arm
 *   func_02030734  0x02030734  arm
 *   func_0202AEEC  0x0202AEEC  thumb
 *   g_020A76E8     0x020A76E8  data
 */
typedef int s32;
typedef unsigned char u8;
typedef unsigned int  u32;

struct A {
    u8  pad0[0x14];
    u32 *unk14;
    u8  unk18;
};

extern u32 func_02049030(u32 a);
extern void *func_02030734(void *heap, u32 size, u32 flags, const void *file, u32 line);
extern u32  func_0202AEEC(void *a1, u32 i);
extern const char g_020A76E8[];

void func_0202AB8C(struct A *a0, void *a1)
{
    s32 n = func_02049030(0x84);
    s32 i;

    a0->unk18 = n;
    a0->unk14 = func_02030734(a1, n << 2, 0, g_020A76E8, 0x14d);
    for (i = 0; i < n; i++) {
        a0->unk14[i] = func_0202AEEC(a1, i);
    }
}
