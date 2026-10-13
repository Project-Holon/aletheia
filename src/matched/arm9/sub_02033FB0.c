/*
 * function: AREAMAN_AllocShortDown
 * address:  0x02033FB0
 * packet:   pkt_02033CA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_RunLenAny    0x020A06A0  data
 *   g_RunLenTail   0x020A05A0  data
 *   g_RunLenHead   0x020A04A0  data
 *   AREAMAN_FindClearRunDown  0x02034348  arm
 *   AREAMAN_MarkUsed  0x020343C0  arm
 *
 * areaman.c.  The downward bit-at-a-time run scanner: the short-run arm of
 * AREAMAN_AllocDown's dispatch (see src/pending/AREAMAN_AllocDown.c), the mirror of
 * AREAMAN_AllocShortUp walking towards lower addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AREAMAN_AllocShortDown.c \
 *       --func AREAMAN_AllocShortDown --addr 0x02033FB0 --cc 1.1p1 --arm
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

extern const u8 g_RunLenAny[256];
extern const u8 g_RunLenTail[256];
extern const u8 g_RunLenHead[256];

extern s32 AREAMAN_FindClearRunDown(u32 byte, u32 bit, u32 len);
extern s32 AREAMAN_MarkUsed(struct AreaMan *p, s32 start, u32 len);

s32 AREAMAN_AllocShortDown(struct AreaMan *p, u32 start, u32 limit, u32 len)
{
    s32 i;
    s32 last;
    s32 lastByte;
    s32 found;
    s32 bit;
    u32 head;

    last = start - limit + 1;
    lastByte = last / 8;
    i = start >> 3;
    found = -1;

    if ((start & 7) != 0) {
        bit = AREAMAN_FindClearRunDown(p->bits[i], start & 7, len);
        if (bit != -1) {
            found = bit + i * 8;
            goto done;
        }
    }

    while (i >= lastByte) {
        if (g_RunLenAny[p->bits[i]] >= len) {
            bit = AREAMAN_FindClearRunDown(p->bits[i], 7, len);
            if (bit != -1) {
                found = bit + i * 8;
                goto done;
            }
        } else {
            head = g_RunLenHead[p->bits[i]];
            if (head != 0 && i > lastByte) {
                if (g_RunLenTail[p->bits[i - 1]] >= len - head) {
                    found = (8 - (len - head)) + (i - 1) * 8;
                    goto done;
                }
            }
        }
        i--;
    }

done:
    if (found != -1 && found >= last) {
        if (AREAMAN_MarkUsed(p, found, len) == 0) {
            found = -1;
        }
        return found;
    }
    return -1;
}
