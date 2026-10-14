/*
 * function: WORLDTRADE_ENTER_WaitProfileResult
 * address:  0x021F8BE8
 * packet:   pkt_ov135_021F8BE8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: 2026-10-05 wave P19: the sub switch exit (state 0, sub out of range) is a cross-jumped copy of the tail, `b 0x021F8CEC` in the image. Written as `WORLDTRADE_CancelSave(p); goto done;` after the sub switch, with `done: return 0;` at the end. EXACT in c99 and c (296 bytes). Idiom: a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.
 *
 * symbols:
 *   DPW_TR_Main  0x021C7C1C  arm  ov114
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm  ov114
 *   DPW_TR_GetAsyncResult  0x021C86A8  arm  ov114
 *   WORLDTRADE_DeleteTimeIcon  0x021F4FC4  thumb
 *   WORLDTRADE_CancelSave  0x021F513C  thumb
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0x38];
    int err;
    u8 pad3C[0xF7C - 0x3C];
    int state;
    int sub;
    u8 padF84[0xF8C - 0xF84];
    int wait;
} Work;

extern void DPW_TR_Main(void);
extern int DPW_TR_IsAsyncEnd(void);
extern int DPW_TR_GetAsyncResult(void);
extern void WORLDTRADE_DeleteTimeIcon(u8 *p);
extern void WORLDTRADE_CancelSave(u8 *p);
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);

int WORLDTRADE_ENTER_WaitProfileResult(Work *p)
{
    int code;

    DPW_TR_Main();
    if (DPW_TR_IsAsyncEnd() != 0) {
        code = DPW_TR_GetAsyncResult();
        p->wait = 0;
        switch (code) {
        case 0:
            switch (p->state) {
            case 0:
                switch (p->sub) {
                case 0:
                    WORLDTRADE_SetStateAndReturn((u8 *)p, 1, 0);
                    return 1;
                case 3:
                    p->err = -5003;
                    return 2;
                case 1:
                    p->err = -5000;
                    return 2;
                case 2:
                    p->err = -5001;
                    return 2;
                }
                WORLDTRADE_CancelSave((u8 *)p);
                goto done;
            case 1:
                p->err = -5004;
                return 2;
            case 2:
                p->err = -5005;
                return 2;
            default:
                WORLDTRADE_DeleteTimeIcon((u8 *)p);
                break;
            }
            break;
        case 1:
            WORLDTRADE_DeleteTimeIcon((u8 *)p);
            p->err = code;
            return 2;
        case -1:
        case 2:
            WORLDTRADE_DeleteTimeIcon((u8 *)p);
            p->err = code;
            return 2;
        case -15:
        case -12:
            WORLDTRADE_DeleteTimeIcon((u8 *)p);
            p->err = code;
            return 2;
        case -14:
        case -2:
            WORLDTRADE_DeleteTimeIcon((u8 *)p);
            p->err = code;
            return 2;
        default:
            WORLDTRADE_DeleteTimeIcon((u8 *)p);
            break;
        }
        WORLDTRADE_CancelSave((u8 *)p);
    } else if (++p->wait == 0xE10) {
        WORLDTRADE_CancelSave((u8 *)p);
    }
done:
    return 0;
}
