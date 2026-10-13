/*
 * function: AREAMAN_AllocAt
 * address:  0x020341F0
 * packet:   pkt_02033CA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   AREAMAN_MarkUsed  0x020343C0  arm
 *   AREAMAN_TraceAlloc  0x02034508  arm
 *
 * areaman.c.  Test-and-report: ask the range checker at 0x020343C0 whether
 * the run [start, start+len) is free, and if it is not, report it through
 * the assert sink at 0x02034508 with line 0x304 before answering.  The
 * three arguments are held in callee-saved registers across the first call
 * precisely because the second call needs them again.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AREAMAN_AllocAt.c \
 *       --func AREAMAN_AllocAt --addr 0x020341F0 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;
typedef signed int    s32;

struct AreaMan {
    u16 unk00;
    u16 unk02;
    u32 *guard;
    u32 unk08;
    u8 bits[1];
};

extern s32 AREAMAN_MarkUsed(struct AreaMan *p, s32 start, u32 len);
extern void AREAMAN_TraceAlloc(struct AreaMan *p, u32 start, u32 len, u32 line);

s32 AREAMAN_AllocAt(struct AreaMan *p, u32 start, u32 len)
{
    if (AREAMAN_MarkUsed(p, start, len) == 0) {
        return 0;
    }

    AREAMAN_TraceAlloc(p, start, len, 0x304);
    return 1;
}
