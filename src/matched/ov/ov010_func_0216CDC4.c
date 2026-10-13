/*
 * function: FLDMMDL_AddMmdlCore
 * address:  0x0216CDC4
 * packet:   pkt_ov010_0216CDC4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_SysGetFreeMmdl  0x0216DEEC  thumb  ov010
 *   FLDMMDL_InitWork  0x0216D1C8  thumb  ov010
 *   FLDMMDL_InitWithHeader  0x0216D040  thumb  ov010
 *   FLDMMDL_InitDir  0x0216D208  thumb  ov010
 *   FLDMMDL_HasMovedPos  0x0216E51C  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   FLDMMDL_SysCheckStatusBit  0x0216D4D4  thumb  ov010
 *   FLDMMDL_RestartMoveTcb  0x0216D244  thumb  ov010
 *   FLDMMDL_InitMove  0x0216D268  thumb  ov010
 *   FLDMMDL_InitDraw  0x0216E114  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysIncMmdlCount  0x0216D4FC  thumb  ov010
 *   FLDMMDL_SetupRailPosFromHeader  0x0216D0E8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 w[9];
} Rec;

extern int FLDMMDL_SysGetFreeMmdl(int a0);
extern void FLDMMDL_InitWork(u8 *o, u32 a, u32 b);
extern void FLDMMDL_InitWithHeader(u8 *o, u16 *r, u32 b, u32 c);
extern void FLDMMDL_InitDir(void *p);
extern int FLDMMDL_HasMovedPos(void *a);
extern u32 *FLDMMDL_SetStatusBit(u32 *p, u32 v);
extern int FLDMMDL_SysCheckStatusBit(int a0, int a1);
extern void FLDMMDL_RestartMoveTcb(u32 a, u8 *o);
extern int FLDMMDL_InitMove(int a0, int a1);
extern int FLDMMDL_InitDraw(int a0);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern int FLDMMDL_SysIncMmdlCount(int a0);
extern void FLDMMDL_SetupRailPosFromHeader(u8 *o, Rec *r, u32 z);

u8 *FLDMMDL_AddMmdlCore(u32 a, Rec *p, u32 b, u32 c)
{
    Rec r = *p;
    u8 *o;

    o = (u8 *)FLDMMDL_SysGetFreeMmdl(a);
    FLDMMDL_InitWork(o, a, b);
    FLDMMDL_InitWithHeader(o, (u16 *)(&r), c, a);
    FLDMMDL_InitDir(o);
    if (FLDMMDL_HasMovedPos(o) == 1)
        FLDMMDL_SetStatusBit((u32 *)o, 640);
    if (FLDMMDL_SysCheckStatusBit(a, 0x10)) {
        FLDMMDL_RestartMoveTcb(a, o);
        FLDMMDL_InitMove(a, (int)o);
    }
    if (FLDMMDL_SysCheckStatusBit(a, 1))
        FLDMMDL_InitDraw((int)o);
    FLDMMDL_SysIncMmdlCount((int)FLDMMDL_GetMmdlSys(o));
    FLDMMDL_SetupRailPosFromHeader(o, &r, 0);
    return o;
}
