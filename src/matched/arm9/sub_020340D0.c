/*
 * function: AREAMAN_AllocLongDown
 * address:  0x020340D0
 * packet:   pkt_02033CA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_RunLenTail   0x020A05A0  data
 *   g_RunLenHead   0x020A04A0  data
 *   AREAMAN_MarkUsed  0x020343C0  arm
 *
 * areaman.c.  The downward word-at-a-time run scanner: the long-run arm of
 * AREAMAN_AllocDown's dispatch (see src/pending/AREAMAN_AllocDown.c), the mirror of
 * AREAMAN_AllocLongUp walking towards lower addresses.  The anchor is the leading
 * free run of byte `i`, whole zero bytes are skipped downwards, and the
 * trailing free run of the byte the remainder lands in closes the request.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AREAMAN_AllocLongDown.c \
 *       --func AREAMAN_AllocLongDown --addr 0x020340D0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct AreaMan {
    u16 unk00;
    u16 unk02;
    u32 *guard;
    u32 unk08;
    u8 bits[1];
};

extern const u8 g_RunLenTail[256];
extern const u8 g_RunLenHead[256];

extern s32 AREAMAN_MarkUsed(struct AreaMan *p, s32 start, u32 len);

s32 AREAMAN_AllocLongDown(struct AreaMan *p, u32 start, u32 limit, u32 len)
{
    s32 i;
    u32 last;
    s32 lastByte;
    s32 run;
    s32 r;
    s32 t;
    s32 n;
    s32 q;
    s32 j;
    s32 found;

    last = start - limit + 1;
    i = start >> 3;
    lastByte = last / 8;

    run = (start & 7) + 1;
    t = g_RunLenHead[p->bits[i]];
    if (t < run) {
        run = t;
    }

    while (i >= lastByte) {
        if (run != 0) {
            n = len - run;
            q = n / 8;
            r = n % 8;
            j = i - 1;
            while (q != 0) {
                if (j < lastByte || p->bits[j] != 0) {
                    break;
                }
                j--;
                q--;
            }
            if (q == 0) {
                found = -1;
                if (r == 0) {
                    found = (j + 1) * 8;
                } else if (j >= lastByte && g_RunLenTail[p->bits[j]] >= r) {
                    found = (8 - r) + j * 8;
                }
                if (found != -1 && found >= last) {
                    if (AREAMAN_MarkUsed(p, found, len) == 0) {
                        found = -1;
                    }
                    return found;
                }
            }
        }
        i--;
        if (i >= lastByte) {
            run = g_RunLenHead[p->bits[i]];
        }
    }

    return -1;
}
