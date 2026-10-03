/*
 * function: func_021C8918
 * address:  0x021C8918
 * packet:   pkt_021C8918
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C8918   0x021C8918  thumb
 *   func_021B9940   0x021B9940  thumb ov093
 *   func_021C8C6C   0x021C8C6C  thumb ov093
 *   func_021C8CBC   0x021C8CBC  thumb ov093
 *   func_021C8D0C   0x021C8D0C  thumb ov093
 *   func_021C8D2C   0x021C8D2C  thumb ov093
 *   func_021C8DE4   0x021C8DE4  thumb ov093
 *   func_021C8E58   0x021C8E58  thumb ov093
 *   func_021C8F24   0x021C8F24  thumb ov093
 *   func_021C8FA4   0x021C8FA4  thumb ov093
 *   func_021C9010   0x021C9010  thumb ov093
 *   func_021C9068   0x021C9068  thumb ov093
 *   func_021C9178   0x021C9178  thumb ov093
 *   func_021C9250   0x021C9250  thumb ov093
 *   func_021C9394   0x021C9394  thumb ov093
 *   func_021C9448   0x021C9448  thumb ov093
 *   func_021C947C   0x021C947C  thumb ov093
 *   func_021C94C8   0x021C94C8  thumb ov093
 *   func_021C95D0   0x021C95D0  thumb ov093
 *   func_021C962C   0x021C962C  thumb ov093
 *   func_021C96D4   0x021C96D4  thumb ov093
 *   func_021C9728   0x021C9728  thumb ov093
 *   func_021C9750   0x021C9750  thumb ov093
 *   func_021C9778   0x021C9778  thumb ov093
 *   func_021C97A4   0x021C97A4  thumb ov093
 *   func_021C97D0   0x021C97D0  thumb ov093
 *   func_021C9828   0x021C9828  thumb ov093
 *   func_021C9898   0x021C9898  thumb ov093
 *   func_021C98C4   0x021C98C4  thumb ov093
 *   func_021C98E4   0x021C98E4  thumb ov093
 *   func_021C9A24   0x021C9A24  thumb ov093
 *   func_021C9A60   0x021C9A60  thumb ov093
 *   func_021C9BB8   0x021C9BB8  thumb ov093
 *   func_021C9CC0   0x021C9CC0  thumb ov093
 *   func_021C9DCC   0x021C9DCC  thumb ov093
 *   func_021C9DE8   0x021C9DE8  thumb ov093
 *   func_021C9E3C   0x021C9E3C  thumb ov093
 *   func_021C9ECC   0x021C9ECC  thumb ov093
 *   func_021C9F0C   0x021C9F0C  thumb ov093
 *   func_021C9F4C   0x021C9F4C  thumb ov093
 *   func_021C9F6C   0x021C9F6C  thumb ov093
 *   func_021CA128   0x021CA128  thumb ov093
 *   func_021CA158   0x021CA158  thumb ov093
 *   func_021CA1D0   0x021CA1D0  thumb ov093
 *   func_021CA248   0x021CA248  thumb ov093
 *   func_021CA270   0x021CA270  thumb ov093
 *   func_021CA2E8   0x021CA2E8  thumb ov093
 *   func_021CA318   0x021CA318  thumb ov093
 *   func_021CA370   0x021CA370  thumb ov093
 *   func_021CA394   0x021CA394  thumb ov093
 *   func_021CA3AC   0x021CA3AC  thumb ov093
 *   func_021CA3D0   0x021CA3D0  thumb ov093
 *   func_021CA47C   0x021CA47C  thumb ov093
 *   func_021CA570   0x021CA570  thumb ov093
 *   func_021CA5CC   0x021CA5CC  thumb ov093
 *   func_021CA6C4   0x021CA6C4  thumb ov093
 *   func_021CA6FC   0x021CA6FC  thumb ov093
 *   func_021CA738   0x021CA738  thumb ov093
 *   func_021CA748   0x021CA748  thumb ov093
 *   func_021CA7C4   0x021CA7C4  thumb ov093
 *   func_021CA7D4   0x021CA7D4  thumb ov093
 *   func_021CC960   0x021CC960  thumb ov093
 *   func_021CC96C   0x021CC96C  thumb ov093
 *   func_021CC974   0x021CC974  thumb ov093
 *   func_021CC99C   0x021CC99C  thumb ov093
 *   func_021D5B68   0x021D5B68  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 id : 8;
    u32 client : 5;
    u32 unk13 : 11;
    u32 ignoreIfBusy : 1;
    u32 checkFainted : 1;
    u32 unk26 : 6;
} BtlCmd;

typedef struct {
    u8 unk0[8];
    void *party;        /* 0x0008 */
    u8 unk0C[0x1D68];
    u8 queue[4];        /* 0x1D74 */
} BattleCtx;

extern int func_021CC960(void *q);
extern int func_021CC96C(void *q);
extern int func_021CC99C(void *q);
extern void func_021CC974(void *q, int r);
extern u8 *func_021B9940(void *party, u8 client);
extern int func_021D5B68(void *mon);
extern u8 func_021C9DE8(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8C6C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8CBC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8D0C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C96D4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8D2C(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C8DE4(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C8E58(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8F24(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C8FA4(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C9010(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C9068(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C9178(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9250(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 func_021C9394(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C947C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C94C8(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9448(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C95D0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C962C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9728(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9750(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9778(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C97A4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C97D0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9828(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9898(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C98C4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C98E4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9A24(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9A60(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9BB8(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9DCC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9E3C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9ECC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9CC0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9F0C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9F4C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021C9F6C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA128(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA158(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA1D0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA248(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA270(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA2E8(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA318(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA370(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA394(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA3AC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA3D0(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA47C(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA570(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA5CC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA6C4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA6FC(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA738(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA748(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA7C4(BattleCtx *s, BtlCmd *cmd);
extern u8 func_021CA7D4(BattleCtx *s, BtlCmd *cmd);

void func_021C8918(BattleCtx *s, BtlCmd *cmd)
{
    int arg = func_021CC960(s->queue);
    u8 r;

    if (func_021CC96C(s->queue))
        r = func_021CC99C(s->queue);
    else
        r = 1;

    if (cmd->ignoreIfBusy && r == 0)
        return;
    if (cmd->checkFainted && func_021D5B68(func_021B9940(s->party, cmd->client)))
        return;

    switch (cmd->id) {
    case 1:
        r = func_021C8C6C(s, cmd);
        break;
    case 2:
        r = func_021C8CBC(s, cmd);
        break;
    case 3:
        r = func_021C8D0C(s, cmd);
        break;
    case 0:
        r = func_021C9DE8(s, cmd);
        break;
    case 5:
        r = func_021C8D2C(s, cmd, arg);
        break;
    case 6:
        r = func_021C8DE4(s, cmd, arg);
        break;
    case 7:
        r = func_021C8E58(s, cmd);
        break;
    case 8:
        r = func_021C8F24(s, cmd);
        break;
    case 9:
        r = func_021C8FA4(s, cmd, arg);
        break;
    case 10:
        r = func_021C9010(s, cmd, arg);
        break;
    case 11:
        r = func_021C9068(s, cmd, arg);
        break;
    case 12:
        r = func_021C9178(s, cmd);
        break;
    case 14:
        r = func_021C9250(s, cmd, arg);
        break;
    case 15:
        r = func_021C9394(s, cmd);
        break;
    case 18:
        r = func_021C9448(s, cmd);
        break;
    case 16:
        r = func_021C947C(s, cmd);
        break;
    case 17:
        r = func_021C94C8(s, cmd);
        break;
    case 19:
        r = func_021C95D0(s, cmd);
        break;
    case 20:
        r = func_021C962C(s, cmd);
        break;
    case 4:
        r = func_021C96D4(s, cmd);
        break;
    case 21:
        r = func_021C9728(s, cmd);
        break;
    case 22:
        r = func_021C9750(s, cmd);
        break;
    case 23:
        r = func_021C9778(s, cmd);
        break;
    case 24:
        r = func_021C97A4(s, cmd);
        break;
    case 25:
        r = func_021C97D0(s, cmd);
        break;
    case 26:
        r = func_021C9828(s, cmd);
        break;
    case 27:
        r = func_021C9898(s, cmd);
        break;
    case 29:
        r = func_021C98E4(s, cmd);
        break;
    case 28:
        r = func_021C98C4(s, cmd);
        break;
    case 30:
        r = func_021C9A24(s, cmd);
        break;
    case 31:
        r = func_021C9A60(s, cmd);
        break;
    case 32:
        r = func_021C9BB8(s, cmd);
        break;
    case 33:
        r = func_021C9DCC(s, cmd);
        break;
    case 34:
        r = func_021C9E3C(s, cmd);
        break;
    case 35:
        r = func_021C9ECC(s, cmd);
        break;
    case 36:
        r = func_021C9CC0(s, cmd);
        break;
    case 37:
        r = func_021C9F0C(s, cmd);
        break;
    case 38:
        r = func_021C9F4C(s, cmd);
        break;
    case 39:
        r = func_021C9F6C(s, cmd);
        break;
    case 40:
        r = func_021CA128(s, cmd);
        break;
    case 41:
        r = func_021CA158(s, cmd);
        break;
    case 42:
        r = func_021CA1D0(s, cmd);
        break;
    case 43:
        r = func_021CA248(s, cmd);
        break;
    case 44:
        r = func_021CA270(s, cmd);
        break;
    case 45:
        r = func_021CA2E8(s, cmd);
        break;
    case 46:
        r = func_021CA318(s, cmd);
        break;
    case 47:
        r = func_021CA370(s, cmd);
        break;
    case 48:
        r = func_021CA394(s, cmd);
        break;
    case 49:
        r = func_021CA3AC(s, cmd);
        break;
    case 50:
        r = func_021CA3D0(s, cmd);
        break;
    case 51:
        r = func_021CA47C(s, cmd);
        break;
    case 52:
        r = func_021CA570(s, cmd);
        break;
    case 53:
        r = func_021CA5CC(s, cmd);
        break;
    case 54:
        r = func_021CA6C4(s, cmd);
        break;
    case 55:
        r = func_021CA6FC(s, cmd);
        break;
    case 56:
        r = func_021CA738(s, cmd);
        break;
    case 57:
        r = func_021CA748(s, cmd);
        break;
    case 58:
        r = func_021CA7C4(s, cmd);
        break;
    case 59:
        r = func_021CA7D4(s, cmd);
        break;
    }
    func_021CC974(s->queue, r);
}
