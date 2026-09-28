/*
 * function: func_02064364
 * address:  0x02064364
 * packet:   pkt_02064364
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02062D4C  0x02062D4C  arm
 *   func_0206419C  0x0206419C  arm
 *
 * Advances one multi-cell node's cell animation by a fx32 tick and, only if
 * that actually changed the displayed frame, marks the node's OAM cache dirty
 * through func_0206419C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064364.c  *       --func func_02064364 --addr 0x02064364 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct CellAnim;

extern s32  func_02062D4C(struct CellAnim *anim);
extern void func_0206419C(struct CellAnim *anim);

void func_02064364(struct CellAnim *anim)
{
    if (func_02062D4C(anim) != 0) {
        func_0206419C(anim);
    }
}
