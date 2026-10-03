/*
 * function: func_021F0E64
 * address:  0x021F0E64
 * packet:   pkt_ov031_021F0E64
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0E64  0x021F0E64  thumb
 *   func_02034714  0x02034714  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u16 cnt;
    u8 idx;
    u8 pad;
} Slot;

typedef struct {
    char pad[0x34];
    Slot s[3];
} A;

typedef struct {
    char pad[0x440];
    int n;
} B;

extern void func_02034714(const char *expr, u32 line, const char *file);

Slot *func_021F0E64(A *p, B *q, int idx)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (p->s[i].cnt != 0 && idx == p->s[i].idx)
            return &p->s[i];
    }
    for (i = 0; i < 3; i++) {
        if (p->s[i].cnt == 0)
            return &p->s[i];
    }
    for (i = 0; i < 3; i++) {
        int v = p->s[i].idx;
        if (v > q->n || v <= q->n - 3)
            return &p->s[i];
    }
    func_02034714((void *)0x021F10D0, 0, (void *)0x021F10D0);
    return 0;
}
