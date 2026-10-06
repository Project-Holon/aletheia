/*
 * function: func_021D1C40
 * address:  0x021D1C40
 * packet:   pkt_ov093_021D1C40
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021B86C0  0x021B86C0  thumb  ov093
 *   func_021CDEE8  0x021CDEE8  thumb  ov093
 *   func_021B9F70  0x021B9F70  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *battle;         /* 0x00 */
    u8 unk04[0x50];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq;

extern u32 func_021B8588(void **p);
extern u8 func_021B86C0(u8 **p);
extern u32 func_021CDEE8(u8 *p);
extern int func_021B9F70(u8 *p, int i);

int func_021D1C40(BattleSeq *s, u32 x, int *out)
{
    u32 v;

    if (x == s->unk1A6) {
        *out = 0;
        if (func_021B8588(s->battle) == 0 && func_021B86C0(s->battle) == 0) {
            v = func_021CDEE8((u8 *)s);
            if (v >= 0x4b)
                return 0x1d;
            if (v > 0x32)
                return 0x1c;
            if (v > 0x19)
                return 0x1b;
            if (v != 0)
                return 0x1a;
            return 0x19;
        }
        return 0x1a;
    }
    *out = 1;
    if (func_021B9F70(s->battle, x) != 0)
        return 0x1e;
    return 0x1f;
}
