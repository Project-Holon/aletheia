/*
 * function: func_02092004
 * address:  0x02092004
 * packet:   pkt_02091D38
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocking: label, no outside witness -- the one wildcard site is +0x00D4
 *           PC24 func_02091E44, whose only branch in the image is this call
 *           (match.py: "has no witness outside 02092004..02092120").  Cut
 *           does not help: the site is inside the single function, so
 *           --suggest-split has nothing to offer.  Byte-correct as it
 *           stands: converts with no edit the moment 0x02091E44 has a
 *           manifest entry of its own.
 * symbols:
 *   g_020A8730     0x020A8730  data
 *   g_020A877C     0x020A877C  data
 *   g_020A87C8     0x020A87C8  data
 *   g_02153BD4     0x02153BD4  data
 *   g_02150FEC     0x02150FEC  data
 *   arr_02153B8C   0x02153B8C  data
 *   arr_02153BB0   0x02153BB0  data
 *   func_020860D0  0x020860D0  arm
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   func_02091E44  0x02091E44  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct H { u32 unk00; u32 *unk04; };

extern u8  g_020A8730[];
extern u8  g_020A877C[];
extern u8  g_020A87C8[];
extern u8  g_02153BD4[];
extern struct H g_02150FEC;
extern u32 arr_02153B8C[];
extern u32 arr_02153BB0[];

extern s32 func_020860D0(void *blk);
extern void func_02086028(void *blk);
extern void func_02086078(void *blk);
extern s32 func_02091E44(u32 a0, u32 a1, u32 a2);

s32 func_02092004(u32 a0, u32 a1, u32 a2)
{
    u32 idx = (a0 == (u32)g_020A8730) ? 2 : (a0 == (u32)g_020A877C) ? 3
            : (a0 == (u32)g_020A87C8) ? 4 : 5;
    u8 *blk = g_02153BD4 + idx * 0x18;
    s32 r;

    if (func_020860D0(blk) == 0) {
        arr_02153B8C[idx] = g_02150FEC.unk04[0x1b];
        arr_02153BB0[idx] = 1;
    } else {
        u32 cur = arr_02153B8C[idx];
        u32 ref = g_02150FEC.unk04[0x1b];

        if (cur == ref) {
            arr_02153BB0[idx]++;
        } else {
            func_02086028(blk);
            arr_02153B8C[idx] = g_02150FEC.unk04[0x1b];
            arr_02153BB0[idx] = 1;
        }
    }
    r = func_02091E44(a0, a1, a2);
    arr_02153BB0[idx]--;
    if (arr_02153BB0[idx] == 0) func_02086078(blk);
    return r;
}
