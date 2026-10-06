/*
 * function: func_02165AC4
 * address:  0x02165AC4
 * packet:   pkt_ov010_02165AC4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reads the record and tag at a ring offset from the head of the queue
 * (func_021659F0 maps the offset to a slot); returns 0 for an empty slot.
 *
 * Follower 0x02165B04 (ldrb accessor of the count byte) is unlabelled.
 *
 * symbols:
 *   func_021659F0  0x021659F0  thumb  ov010
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

extern int func_021659F0(u8 *q, int delta);

int func_02165AC4(struct Queue *q, struct Rec *out, u16 *tag, int delta)
{
    int idx = func_021659F0((u8 *)q, delta);

    if (q->r[idx].f00 == 0)
        return 0;
    *out = q->r[idx];
    *tag = q->tag[idx];
    return 1;
}
