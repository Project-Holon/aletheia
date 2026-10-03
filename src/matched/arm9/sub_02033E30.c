/*
 * function: sub_02033E30
 * address:  0x02033E30
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
 *   func_020343C0  0x020343C0  arm
 *   func_02034508  0x02034508  arm
 *
 * areaman.c.  The word-at-a-time run scanner: the long-run arm of
 * sub_02033CC0's dispatch (see src/pending/unit_02033CA8.c), taken when the
 * requested run is eight bits or longer.  Where sub_02033CFC walks bit by
 * bit, this one anchors on the trailing free run of byte `i`, skips whole
 * zero bytes, and then checks the leading free run of the byte the tail
 * lands in.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02033E30.c \
 *       --func sub_02033E30 --addr 0x02033E30 --cc 1.1p1 --arm
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

extern s32 func_020343C0(struct AreaMan *p, s32 start, u32 len);
extern void func_02034508(struct AreaMan *p, s32 pos, u32 len, u32 line);

s32 sub_02033E30(struct AreaMan *p, u32 start, u32 limit, u32 len)
{
    u32 last;
    s32 lastByte;
    s32 run;
    s32 t;
    s32 n;
    s32 i;
    s32 q;
    s32 j;
    s32 r;
    s32 found;

    i = start >> 3;
    last = start + limit - len;
    lastByte = last / 8;

    run = 8 - (start & 7);
    t = g_RunLenTail[p->bits[i]];
    if (t < run) {
        run = t;
    }

    while (i <= lastByte) {
        if (run != 0) {
            n = len - run;
            q = n / 8;
            r = n % 8;
            j = i + 1;
            while (q != 0) {
                if (p->bits[j] != 0) {
                    break;
                }
                j++;
                q--;
            }
            if (q == 0) {
                found = -1;
                if (r == 0) {
                    found = (8 - run) + i * 8;
                } else if (g_RunLenHead[p->bits[j]] >= r) {
                    found = (8 - run) + i * 8;
                }
                if (found != -1) {
                    if (func_020343C0(p, found, len) == 0) {
                        return -1;
                    }
                    func_02034508(p, found, len, 0x1db);
                    return found;
                }
            }
        }
        i++;
        if (i <= lastByte) {
            run = g_RunLenTail[p->bits[i]];
        }
    }

    return -1;
}
