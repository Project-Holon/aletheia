/*
 * function: MONOLITH_TOOL_Main
 * address:  0x021B6250
 * packet:   pkt_ov071_021B6250
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Main proc of the ov071 triple (work allocated by MONOLITH_TOOL_Init): fade in,
 * wait on the link state, start the two sound handles (+0x12C/+0x130) off the
 * d_021BA774 pair table, fade out. The link-wait cases are
 * `if (r == 0 || FB24() != 0) seq++; else if (X() == 1) seq++;`: one ||
 * chain of all three conditions lays the branches out 2 B short.
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   INTRUDE_COMM_SendBusyBegin  0x0217440C  thumb  ov011
 *   INTRUDE_COMM_SendBusyEnd  0x0217446C  thumb  ov011
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   GAME_COMM_GetCounter  0x0202648C  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   PROCSYS_Push  0x02031348  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PROCSYS_Main  0x02031330  arm
 *   TCBL_Main  0x020310C4  arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   CLACT_DrawSystem  0x0204A600  arm
 *   d_021BA774     0x021BA774  data  a4
 */
#include "../include/Obj00712.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
} Pair;

extern Pair d_021BA774[];

struct Ctx;
struct PrintSys;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
struct Tcbl;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_0200FB24(void);
extern u32 INTRUDE_COMM_SendBusyBegin(void);
extern u32 INTRUDE_COMM_SendBusyEnd(void);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 GAME_COMM_GetCounter(void *obj);
extern u32 GAME_COMM_GetKind(void *obj);
extern void PROCSYS_Push(int h, int id, int a, void *b);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern u32 PROCSYS_Main(void *h);
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void CLACT_DrawSystem(void);

int MONOLITH_TOOL_Main(int a, int *seq, void **pwk, u8 *mywk)
{
    void *h;
    u8 *r;
    int s1;
    int s2;
    u8 k;

    h = (void *)GAMESYSTEM_GetGameComm(*pwk);
    r = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)h);
    switch (*seq) {
    case 0:
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x8061);
        (*seq)++;
        break;
    case 1:
        if (r == 0 || func_0200FB24() != 0)
            (*seq)++;
        else if (INTRUDE_COMM_SendBusyBegin() == 1)
            (*seq)++;
        break;
    case 2:
        if (WIPE_SYS_EndCheck() == 1)
            (*seq)++;
        break;
    case 3:
        if (func_0200FB24() != 0 || (r == 0 && GAME_COMM_GetCounter(h) != 0) || (r == 0 && GAME_COMM_GetKind(h) == 2))
            mywk[0x126] = 1;
        if (mywk[0x126] == 0) {
            if (mywk[0x135] == 0) {
                PROCSYS_Push(((struct Obj00712 *)mywk)->f12C, -1, d_021BA774[mywk[0x134]].a, mywk + 0xF8);
                mywk[0x135] = 1;
            }
            if (mywk[0x136] == 0) {
                GF_FONT_SetTextColor(0xF, 2, 0);
                PROCSYS_Push(((struct Obj00712 *)mywk)->f130, -1, d_021BA774[mywk[0x134]].b, mywk + 0xF8);
                mywk[0x136] = 1;
            }
        }
        s2 = PROCSYS_Main((void *)((struct Obj00712 *)mywk)->f130);
        k = mywk[0x124];
        if (k == 4 || (s2 != 1 && mywk[0x126] == 1)) {
            mywk[0x125] = 1;
        } else if (mywk[0x134] != k && d_021BA774[mywk[0x134]].a != d_021BA774[k].a) {
            mywk[0x125] = 1;
        }
        s1 = PROCSYS_Main((void *)((struct Obj00712 *)mywk)->f12C);
        if (s1 == 1 && s2 == 1)
            break;
        if (mywk[0x126] == 1 || mywk[0x124] == 4) {
            if (s1 == 0 && s2 == 0)
                (*seq)++;
        } else {
            mywk[0x134] = mywk[0x124];
            if (s1 != 1) {
                mywk[0x135] = 0;
                mywk[0x125] = 0;
            }
            if (s2 != 1)
                mywk[0x136] = 0;
        }
        break;
    case 4:
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x8061);
        (*seq)++;
        break;
    case 5:
        if (r == 0 || func_0200FB24() != 0)
            (*seq)++;
        else if (INTRUDE_COMM_SendBusyEnd() == 1)
            (*seq)++;
        break;
    case 6:
        if (WIPE_SYS_EndCheck() == 1)
            (*seq)++;
        break;
    case 7:
        return 1;
    }
    TCBL_Main(((struct Obj00712 *)mywk)->f18);
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj00712 *)mywk)->f8));
    CLACT_DrawSystem();
    return 0;
}
