/*
 * function: func_021BA438
 * address: 0x021BA438
 * packet: pkt_ov069_021BA438
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow.
 * lever: Inline the getter result into the sum; a named result reverses
 * the final adds operands (one concrete byte).
 * symbols:
 *   func_021BA384 0x021BA384 thumb ov069
 *   func_021BA480 0x021BA480 thumb ov069
 *   func_020260E0 0x020260E0 thumb
 *   func_021B9FF0 0x021B9FF0 thumb ov069
 */
#include "../include/Obj00432.h"
extern void func_021BA384(char *o, int i, int n);
struct Obj;
struct Rec;
extern void func_021BA480(struct Obj *o);
typedef unsigned char  u8;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void func_021B9FF0(char *p, struct Rec *tbl, int idx);
void func_021BA438(char *p, int i)
{
    ((struct Obj00432 *)p)->f160 = i;
    func_021BA384(p, i, ((struct Obj00432 *)p)->f162);
    func_021BA480((struct Obj *)p);
    func_021B9FF0(p, ((struct Obj00432 *)p)->f8, ((struct Obj00432 *)p)->f160 * 10 + func_020260E0(((struct Obj00432 *)p)->f14C));
}
