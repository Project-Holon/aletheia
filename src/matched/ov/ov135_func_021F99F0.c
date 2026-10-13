/*
 * function: func_021F99F0
 * address:  0x021F99F0
 * packet:   pkt_021F99F0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
 * symbols:
 *   tbl_02203C48  0x02203C48  data  a4
 *   func_02202770  0x02202770  thumb
 *   func_022029F8  0x022029F8  thumb
 *   BGWINFRM_UpdateMoves  0x0202CD94  thumb  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Obj Obj;

struct Obj {
    u8 pad0[0x18];
    void *mgr;
    u8 pad1C[0x34 - 0x1C];
    void *printer;
    u8 pad38[0x48 - 0x38];
    int state;
    u8 pad4C[0x7C - 0x4C];
    u8 g[4];
};

struct WinMgr;
extern int (*const tbl_02203C48[])(Obj *p);

extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern void func_02202770(void *g);
extern void func_022029F8(void *printer);

int func_021F99F0(Obj *p)
{
    int r = tbl_02203C48[p->state](p);

    BGWINFRM_UpdateMoves(p->mgr);
    func_02202770(p->g);
    func_022029F8(p->printer);
    return r;
}
