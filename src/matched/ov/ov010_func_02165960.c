/*
 * function: GAME_BEACON_ACCESSOR_TableAdd
 * address:  0x02165960
 * packet:   pkt_ov010_02165960
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Inserts a record into the 30-slot queue (see GAME_BEACON_ACCESSOR_TablePop): reuses the
 * first empty slot or the slot with the same f10; otherwise, when the
 * mode is 1, drops slot 0 by shifting everything down and appends.
 * Returns the slot used, or 30 when full and mode is not 1.
 *
 * symbols:
 *   MIi_CpuCopy32  0x02082A90  arm
 *   MIi_CpuCopy16  0x02082A60  arm
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

extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);

int GAME_BEACON_ACCESSOR_TableAdd(struct Queue *q, struct Rec *rec, int tag, int mode)
{
    int i;

    for (i = 0; i < 30; i++) {
        if (q->r[i].f00 == 0 || rec->f10 == q->r[i].f10) {
            q->r[i] = *rec;
            q->tag[i] = tag;
            return i;
        }
    }
    if (mode == 1) {
        MIi_CpuCopy32(&q->r[1], &q->r[0], 29 * 0x5c);
        MIi_CpuCopy16(&q->tag[1], &q->tag[0], 58);
        q->r[29] = *rec;
        q->tag[29] = tag;
        return 29;
    }
    return 30;
}
