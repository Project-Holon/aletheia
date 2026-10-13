/*
 * function: GAME_BEACON_ACCESSOR_TablePop
 * address:  0x021658D4
 * packet:   pkt_ov010_021658D4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pops the front record of a 30-slot queue (0x5c-byte records, then a
 * u16 tag per slot at +0xAC8): copies out slot 0 and its tag, shifts the
 * rest down one and clears the last record. Returns 0 when empty.
 *
 * symbols:
 *   MI_CpuFill8   0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Rec {
    u8 f00;
    u8 pad01[15];
    u16 f10;
    u8 pad12[0x46];
    u32 tail;
};

struct Queue {
    struct Rec r[30];
    u16 tag[30];
    u8 head;
    u8 count;
};

extern void MI_CpuFill8(void *dst, u32 v, u32 size);

int GAME_BEACON_ACCESSOR_TablePop(struct Queue *q, struct Rec *out, u16 *tag)
{
    int i;

    if (q->r[0].f00 == 0)
        return 0;
    *out = q->r[0];
    *tag = q->tag[0];
    for (i = 1; i < 30; i++) {
        q->r[i - 1] = q->r[i];
        q->tag[i - 1] = q->tag[i];
    }
    MI_CpuFill8(&q->r[29], 0, 0x5c);
    return 1;
}
