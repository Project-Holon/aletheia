/*
 * file:     unit_0207FD34_p04.c
 * unit:     yes
 * function: func_02080C24, func_02080C34, func_02080C44, func_02080C54, func_02080C64, func_02080C74
 * address:  0x02080C24
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gGXState  0x02150E4C  data  a4
 */
typedef unsigned short u16;

typedef struct {
    u16 lcdc;
    u16 bg;
    u16 obj;
    u16 arm7;
    u16 tex;
    u16 texPltt;
    u16 clrImg;
    u16 bgExtPltt;
    u16 objExtPltt;
    u16 sub_bg;
    u16 sub_obj;
    u16 sub_bgExtPltt;
    u16 sub_objExtPltt;
} GX_VRAMCnt;

u16 func_02080C24(void);
u16 func_02080C34(void);
u16 func_02080C44(void);
u16 func_02080C54(void);
u16 func_02080C64(void);
u16 func_02080C74(void);
extern GX_VRAMCnt gGXState;


/*
 * note:     gx_vramcnt.o GX_GetBankForOBJ; gGXState.vramCnt at 0x02150E4C.
 */
u16 func_02080C24(void)
{
    return gGXState.obj;
}


/*
 * note:     gx_vramcnt.o GX_GetBankForOBJExtPltt.
 */
u16 func_02080C34(void)
{
    return gGXState.objExtPltt;
}


/*
 * note:     gx_vramcnt.o GX_GetBankForTex.
 */
u16 func_02080C44(void)
{
    return gGXState.tex;
}


/*
 * note:     gx_vramcnt.o GX_GetBankForLCDC.
 */
u16 func_02080C54(void)
{
    return gGXState.lcdc;
}


/*
 * note:     gx_vramcnt.o GX_GetBankForSubOBJ.
 */
u16 func_02080C64(void)
{
    return gGXState.sub_obj;
}


/*
 * note:     gx_vramcnt.o GX_GetBankForSubOBJExtPltt.
 */
u16 func_02080C74(void)
{
    return gGXState.sub_objExtPltt;
}
