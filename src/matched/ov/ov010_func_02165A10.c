/*
 * function: func_02165A10
 * address:  0x02165A10
 * packet:   pkt_ov010_02165A10
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Ring-buffer variant of the queue insert (func_021659F0 maps a logical
 * index to a slot): replaces the record with the same f10 if present
 * before the first empty slot, else pushes a new head; the count byte
 * saturates at 30. *flag (optional) is 1 when a new slot was taken.
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

int func_02165A10(struct Queue *q, struct Rec *rec, u16 tag, int *flag)
{
    int i;
    int idx;

    if (flag)
        *flag = 0;
    for (i = 0; i < 30; i++) {
        idx = func_021659F0((u8 *)q, i);
        if (q->r[idx].f00 == 0)
            break;
        if (rec->f10 == q->r[idx].f10) {
            q->r[idx] = *rec;
            q->tag[idx] = tag;
            return i;
        }
    }
    if (flag)
        *flag = 1;
    idx = func_021659F0((u8 *)q, -1);
    q->r[idx] = *rec;
    q->tag[idx] = tag;
    q->head = idx;
    if (q->count < 30)
        q->count++;
    return 0;
}
