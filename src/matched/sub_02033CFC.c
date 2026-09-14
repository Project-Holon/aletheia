/*
 * function: sub_02033CFC
 * address:  0x02033CFC
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
 *   func_020342F8  0x020342F8  arm
 *   func_020343C0  0x020343C0  arm
 *   func_02034508  0x02034508  arm
 *
 * areaman.c.  The bit-at-a-time run scanner: the short-run arm of
 * sub_02033CC0's dispatch (see src/pending/unit_02033CA8.c), taken when the
 * requested run is under eight bits.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02033CFC.c \
 *       --func sub_02033CFC --addr 0x02033CFC --cc 1.1p1 --arm
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

extern s32 func_020342F8(u32 byte, u32 bit, u32 len);
extern u32 func_020343C0(struct AreaMan *p, s32 pos, u32 len);
extern void func_02034508(struct AreaMan *p, s32 pos, u32 len, u32 line);

s32 sub_02033CFC(struct AreaMan *p, u32 start, u32 limit, u32 len)
{
    s32 found;
    s32 last;
    s32 lastByte;
    s32 i;
    s32 bit;
    u32 tail;

    last = start + limit + 1 - len;
    lastByte = last / 8;
    i = start >> 3;
    found = -1;

    if ((start & 7) + len <= 8) {
        bit = func_020342F8(p->bits[i], start & 7, len);
        if (bit != -1) {
            found = bit + i * 8;
            goto done;
        }
    }

    while (i <= lastByte) {
        if (g_RunLenAny[p->bits[i]] >= len) {
            bit = func_020342F8(p->bits[i], 0, len);
            if (bit != -1) {
                found = bit + i * 8;
                goto done;
            }
        } else {
            tail = g_RunLenTail[p->bits[i]];
            if (tail != 0 && i < lastByte) {
                if (g_RunLenHead[p->bits[i + 1]] >= len - tail) {
                    found = (8 - tail) + i * 8;
                    goto done;
                }
            }
        }
        i++;
    }

done:
    if (found != -1 && found <= last) {
        if (func_020343C0(p, found, len) == 0) {
            return -1;
        }
        func_02034508(p, found, len, 0x17c);
        return found;
    }
    return -1;
}
