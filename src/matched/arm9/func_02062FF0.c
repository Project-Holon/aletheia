/*
 * function: func_02062FF0
 * address:  0x02062FF0
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02062F90  0x02062F90  arm
 *
 * Binds a cell data bank to a cell animation and restarts it. The bind is a
 * single store followed by a tail call, so it costs a pool word and a `bx`
 * rather than a branch (one section per function, no displacement branch).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062FF0.c  *       --func func_02062FF0 --addr 0x02062FF0 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct CellAnim {
    u8 pad00[0x1C];
    void *bank;
};

struct NNSG2dAnimController;
extern void func_02062F90(struct NNSG2dAnimController *pAnimCtrl);

void func_02062FF0(struct CellAnim *anim, void *bank)
{
    anim->bank = bank;
    func_02062F90((struct NNSG2dAnimController *)anim);
}
