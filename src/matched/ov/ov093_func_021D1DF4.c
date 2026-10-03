/*
 * function: func_021D1DF4
 * address:  0x021D1DF4
 * packet:   pkt_ov093_021D1DF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021B9064  0x021B9064  thumb  ov093
 *   func_021B9920  0x021B9920  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5C44  0x021D5C44  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *battle;         /* 0x00 */
    void *unk04;          /* 0x04 */
    u8 unk08[0x4C];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq;

extern u32 func_021B8588(void **p);
extern u32 func_021B9064(u8 *p, u8 k, int x);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern int func_021D5B68(void *p);
extern int func_021D5C44(void *p);

int func_021D1DF4(BattleSeq *s)
{
    u8 *m;
    u8 t;
    int v;

    if (func_021B8588(s->battle) == 0) {
        t = func_021B9064(s->battle, s->unk1A6, 0);
        m = func_021B9920(s->unk04, t, 0);
        if (func_021D5B68(m) != 0)
            return 0xb;
        v = func_021D5C44(m);
        if (v >= 0x4d800)
            return 0xb;
        if (v >= 0x37000)
            return 0x15;
        if (v >= 0x20800)
            return 0x16;
        if (v >= 0xa000)
            return 0x17;
        return 0x18;
    }
    return 0xb;
}
