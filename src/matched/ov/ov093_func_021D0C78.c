/*
 * function: func_021D0C78
 * address:  0x021D0C78
 * packet:   pkt_ov093_021D0C78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEC20  0x021EEC20  thumb  ov093
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
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

extern int func_021EEC20(int, int *);
extern unsigned char func_021B8DE4(char *p, int i);

u8 func_021D0C78(BattleSeq *s, u8 *out)
{
    int arr;
    u8 n;
    u32 i;
    u32 cnt;

    n = func_021EEC20(*(int *)((u8 *)s + 0x50), &arr);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        if (s->unk1A6 == func_021B8DE4(s->battle, ((u8 *)arr)[i])) {
            out[cnt] = ((u8 *)arr)[i];
            cnt++;
        }
    }
    return cnt;
}
