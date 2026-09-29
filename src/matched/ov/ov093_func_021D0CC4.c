/*
 * function: func_021D0CC4
 * address:  0x021D0CC4
 * packet:   pkt_ov093_021D0CC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021EABC4  0x021EABC4  thumb  ov093
 *   func_021EAC54  0x021EAC54  thumb  ov093
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

extern void func_021EAF18(void *msg, int a, int id);
extern void func_021EABC4(void *win, void *a, void *b, int c);
extern int func_021EAC54(void *win, int *out);

int func_021D0CC4(BattleSeq *s, int *state)
{
    int t;
    u8 *q;
    u8 f;

    switch (*state) {
    case 0:
        func_021EAF18(s->msg, 3, 5);
        func_021EAF18((u8 *)s + 0x7c, 3, 1);
        func_021EABC4(s->msgWin, s->msg, (u8 *)s + 0x7c, 0);
        (*state)++;
        break;
    case 1:
        if (func_021EAC54(s->msgWin, &t)) {
            f = 0;
            if (t != 0)
                f = 1;
            q = (u8 *)s + 0x1ac;
            *q = f;
            *(u8 **)((u8 *)s + 0xd8) = q;
            *(int *)((u8 *)s + 0xdc) = 1;
            return 1;
        }
        break;
    }
    return 0;
}
