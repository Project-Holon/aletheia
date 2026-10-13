/*
 * function: BTLV_SCD_RunTask
 * address:  0x06899E68
 * packet:   pkt_ov095_06899E68
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Slot table of four 16-byte entries at +0x20 with a count at +0x60 (see
 * BTLV_SCD_PushTask, which pushes an entry, and BTLV_SCD_ClearTasks, which clears
 * them).  Services the newest entry.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Slot {
    int (*f0)(void *, int);
    int (*f1)(void *, int);
    int arg;
    int data;
} Slot;

typedef struct Q {
    u8 pad[0x20];
    Slot tab[4];
    int n;
} Q;

int BTLV_SCD_RunTask(Q *q)
{
    Slot *e;
    int done;

    if (q->n != 0) {
    e = &q->tab[q->n - 1];
    if (e->f0 != 0) {
        if (e->f0(&e->data, e->arg) != 0) {
            e->f0 = 0;
            e->data = 0;
        }
        done = 0;
    } else if (e->f1 != 0) {
        if (e->f1(&e->data, e->arg) != 0) {
            e->f1 = 0;
            done = 1;
        } else {
            done = 0;
        }
    } else {
        done = 1;
    }
    if (done) {
        e->f0 = 0;
        e->f1 = 0;
        e->arg = 0;
        e->data = 0;
        q->n--;
    }
    return 0;
    }
    return 1;
}
