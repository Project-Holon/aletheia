/*
 * function: func_020643A4
 * address:  0x020643A4
 * packet:   pkt_02064364
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02062F90  0x02062F90  arm
 *   func_0206419C  0x0206419C  arm
 *
 * Restarts one node's cell animation from frame 0, forces its active flag at
 * +0x0C on and marks the node's OAM cache dirty unconditionally.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020643A4.c  *       --func func_020643A4 --addr 0x020643A4 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct CellAnim {
    u8 pad00[0xC];
    u32 active;
};

extern void func_02062F90(struct CellAnim *anim);
extern void func_0206419C(struct CellAnim *anim);

void func_020643A4(struct CellAnim *anim)
{
    func_02062F90(anim);
    anim->active = 1;
    func_0206419C(anim);
}
