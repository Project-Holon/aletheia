/*
 * function: ZKNSEARCH_MAIN_PollMenuInput
 * address:  0x021BFF68
 * packet:   pkt_ov210_021BFF68
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_020355C4 0x020355C4 arm
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   ZKNSEARCH_MAIN_MoveCursor 0x021C003C thumb ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct Sound;
struct Struct_02025CD0;
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *obj);
extern unsigned KEY_GetTrg(void);
typedef unsigned char  u8;
extern void func_020355D8(u8 v);
extern u8 func_020355C4(void);
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern void ZKNSEARCH_MAIN_MoveCursor(int p, unsigned b);

u32 ZKNSEARCH_MAIN_PollMenuInput(int p)
{
    int *q = (int *)p;
    int r = CURSOR_MOVE_PollRepeatInput((struct Sound *)q[0xac]);
    unsigned k;

    if (r != -1)
        return r;
    k = KEY_GetTrg();
    if (k & 0x400) {
        func_020355D8(0);
        return 8;
    }
    k = KEY_GetTrg();
    if (k & 0x800) {
        if (func_020355C4() == 1)
            CURSOR_MOVE_SetState((struct Struct_02025CD0 *)q[0xac], 1);
        func_020355D8(0);
        return 7;
    }
    k = KEY_GetTrg();
    if (k & 8) {
        if (func_020355C4() == 1)
            CURSOR_MOVE_SetState((struct Struct_02025CD0 *)q[0xac], 1);
        func_020355D8(0);
        ZKNSEARCH_MAIN_MoveCursor(p, 5);
        return 5;
    }
    k = KEY_GetTrg();
    if (k & 4) {
        if (func_020355C4() == 1)
            CURSOR_MOVE_SetState((struct Struct_02025CD0 *)q[0xac], 1);
        func_020355D8(0);
        ZKNSEARCH_MAIN_MoveCursor(p, 6);
        return 6;
    }
    if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        func_020355D8(0);
        CURSOR_MOVE_SetState((struct Struct_02025CD0 *)q[0xac], 1);
        return -4;
    }
    return r;
}
