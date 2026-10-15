/*
 * function: NNS_G2dInitOamManagerModule
 * address:  0x02063078
 * packet:   pkt_02063000
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The cell/OAM bank reset: nine MIi_CpuClear16 calls that blank all three
 * 0x540-byte bank records of g_02146BC8 -- the OAM mirror at +0x100 (0x400
 * bytes, fill 0xC0) and the two free-slot tables, slotsA at +0x000 (0x100
 * bytes) and slotsB at +0x500 (0x40 bytes), both filled with the 0xFFFF
 * free sentinel that NNSi_G2dReserveOamManagerSpan tests for.
 *
 * COMPILER PIN, ../2.0/sp2, the cluster's "kept constants" tell.  The image
 * rematerialises each call's fill value and size into r0/r2 at every one of
 * the nine sites (`mov r0,#0xc0` at 0x02063080/0x02063090/0x020630A0, then
 * `ldr r0,[pc,#0x68]` naming the same 0xFFFF pool word at 0x0206311C six
 * times over, and `mov r2,#0x40` at 0x020630E4/0x020630F4/0x02063104) and
 * spends no callee-saved register at all: `push {r3, lr}` / `pop {r3, pc}`.
 * dsi/1.1p1 -O4,p CSEs 0xFFFF into r5 and 0x40 into r4 and holds both live
 * across the call chain, widening the prologue to `push {r3, r4, r5, lr}`
 * and replacing each rematerialisation with `mov r0,r5` / `mov r2,r4`:
 * same 192 bytes, 30 concrete out.  Under the pin this identical C is 0
 * mismatches on the first compile.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNS_G2dInitOamManagerModule.c \
 *       --func NNS_G2dInitOamManagerModule --addr 0x02063078 --cc ../2.0/sp2 --arm
 *
 * symbols:
 *   MIi_CpuClear16  0x02082A48  arm
 *   g_02146BC8      0x02146BC8  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct OamEntry { u16 attr0, attr1, attr2, pad; };

struct Bank {
    u16 slotsA[0x80];           /* 0x000 */
    struct OamEntry oam[0x80];  /* 0x100 */
    u16 slotsB[0x20];           /* 0x500 */
};

extern struct Bank g_02146BC8[];
extern void MIi_CpuClear16(u16 data, void *dest, u32 size);

void NNS_G2dInitOamManagerModule(void)
{
    MIi_CpuClear16(0xC0, g_02146BC8[0].oam, 0x400);
    MIi_CpuClear16(0xC0, g_02146BC8[1].oam, 0x400);
    MIi_CpuClear16(0xC0, g_02146BC8[2].oam, 0x400);
    MIi_CpuClear16(0xFFFF, g_02146BC8[0].slotsA, 0x100);
    MIi_CpuClear16(0xFFFF, g_02146BC8[1].slotsA, 0x100);
    MIi_CpuClear16(0xFFFF, g_02146BC8[2].slotsA, 0x100);
    MIi_CpuClear16(0xFFFF, g_02146BC8[0].slotsB, 0x40);
    MIi_CpuClear16(0xFFFF, g_02146BC8[1].slotsB, 0x40);
    MIi_CpuClear16(0xFFFF, g_02146BC8[2].slotsB, 0x40);
}
