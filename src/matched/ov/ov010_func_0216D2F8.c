/*
 * function: FLDMMDL_SysPopAll
 * address:  0x0216D2F8
 * packet:   pkt_ov010_0216D2F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_RestartMoveTcb  0x0216D244  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_InitMove  0x0216D268  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_CallMoveRecoverProc  0x0216D730  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 *   FLDMMDL_CheckMoveBitDrawInitComp  0x0216DAA0  thumb  ov010
 *   FLDMMDL_InitDraw  0x0216E114  thumb  ov010
 *   FLDMMDL_CallDrawPopProc  0x0216D794  thumb  ov010
 *   FLDMMDL_ResetDrawStatusBits  0x0216E174  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern void FLDMMDL_RestartMoveTcb(u32 x, u8 *o);
extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern int FLDMMDL_InitMove(int a0, int a1);
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern void FLDMMDL_CallMoveRecoverProc(void *a0);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);
extern int FLDMMDL_CheckMoveBitDrawInitComp(void *a0);
extern int FLDMMDL_InitDraw(int a0);
extern void FLDMMDL_CallDrawPopProc(void *a0);
extern void FLDMMDL_ResetDrawStatusBits(void *a0);

void FLDMMDL_SysPopAll(u32 x)
{
    int n;
    u8 *o;
    u32 a = 1;
    u32 b = 4;
    u32 c = 2;

    n = 0;
    if (FLDMMDL_SysSearchUseMmdl((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n)) == 1) {
        do {
            FLDMMDL_RestartMoveTcb(x, o);
            if (FLDMMDL_CheckStatusBit((int)o, c) == 0)
                FLDMMDL_InitMove(x, (int)o);
            if (FLDMMDL_CheckMoveBit(o, a)) {
                FLDMMDL_CallMoveRecoverProc(o);
                FLDMMDL_ClearMoveBit((char *)o, a);
            }
            if (FLDMMDL_CheckMoveBitDrawInitComp(o) == 0)
                FLDMMDL_InitDraw((int)o);
            if (FLDMMDL_CheckMoveBit(o, b)) {
                FLDMMDL_CallDrawPopProc(o);
                FLDMMDL_ClearMoveBit((char *)o, b);
            }
            FLDMMDL_ResetDrawStatusBits(o);
        } while (FLDMMDL_SysSearchUseMmdl((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n)) == 1);
    }
}
