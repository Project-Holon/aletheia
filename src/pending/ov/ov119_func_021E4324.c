/*
 * function: func_021E4324
 * address:  0x021E4324
 * packet:   pkt_ov119_021E4324
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02 (wB2 lane08): DIFF, only the loop-invariant halfword d is left: original does two ext pairs (lsls/lsrs r0 then lsls/lsrs r3, d in r6, heap offset in r5) and ours emits one pair; u16/int/u32 parameter, u16 local, double cast, +0 and &0xFFFF forms tried. Rest of the body (struct Buf v[0x300] at +0x24, four reloaded base pointers) matches.
 *
 * symbols:
 *   func_02048F60  0x02048F60  arm
 *   func_021E42B4  0x021E42B4  thumb  ov119
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad00[0x24];
    u16 v[0x300];       /* 0x024 */
} Buf;

extern Buf *func_02048F60(int, int, u16);
extern void func_021E42B4(char *p);

void func_021E4324(char *p, u16 d)
{
    int i;
    u16 e;

    *(Buf **)(p + 0x1174) = func_02048F60(0x66, 0xE, *(u16 *)(p + 0x5F4));
    *(Buf **)(p + 0x1178) = func_02048F60(0x66, 0xF, *(u16 *)(p + 0x5F4));
    *(Buf **)(p + 0x117C) = func_02048F60(0x66, 0x19, *(u16 *)(p + 0x5F4));
    *(Buf **)(p + 0x1180) = func_02048F60(0x66, 0x1A, *(u16 *)(p + 0x5F4));
    e = d;
    for (i = 0; i < 0x300; i++) {
        (*(Buf **)(p + 0x1174))->v[i] += e;
        (*(Buf **)(p + 0x1178))->v[i] += e;
        (*(Buf **)(p + 0x117C))->v[i] += e;
        (*(Buf **)(p + 0x1180))->v[i] += e;
    }
    *(u16 *)(p + 0x107C) = *(u32 *)(p + 0x63C) - 0x50;
    func_021E42B4(p);
}
