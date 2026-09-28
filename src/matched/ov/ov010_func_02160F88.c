/*
 * function: func_02160F88
 * address:  0x02160F88
 * packet:   pkt_ov010_02160F88
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf after func_02160E08's pool (0x02160F88, no func_ label in the
 * listing; reached through a pointer, not a bl).
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Inner {
    u8 pad00[0xC];
    u32 f0c;            /* 0x0C */
} Inner;

typedef struct Seq {
    u8 pad00[0xC];
    u32 state;          /* 0x0C */
    u8 pad10[8];
    Inner *f18;         /* 0x18 */
} Seq;

typedef struct Evt {
    u8 pad00[0x12];
    u8 kind;            /* 0x12 */
} Evt;

int func_02160F88(Seq *s, Evt *e)
{
    switch (e->kind) {
    case 0:
    case 1:
        if (s->f18->f0c == 6)
            return 0;
        s->state = 0;
        return 4;
    case 2:
        return 1;
    }
    return 1;
}
