/*
 * function: func_021B3B84
 * address:  0x021B3B84
 * packet:   pkt_ov021_021B3B84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B3B84 0x021B3B84 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 */
#include "../include/Obj03599.h"

struct Rec;
struct S02031140;
struct U16Vec;
struct WordSet;
extern void func_02031140(struct S02031140 *p);
extern void func_0201ED04(struct WordSet *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045C04(struct Rec *rec);

void func_021B3B84(char *p)
{
    func_02031140(((struct Obj03599 *)p)->f1B4);
    func_0201ED04(((struct Obj03599 *)p)->f190);
    func_02045808(((struct Obj03599 *)p)->f19C);
    func_02045808(((struct Obj03599 *)p)->f198);
    func_02045808(((struct Obj03599 *)p)->f1A0);
    func_02045808(((struct Obj03599 *)p)->f194);
    func_02045C04(((struct Obj03599 *)p)->f188);
    func_02045C04(((struct Obj03599 *)p)->f18C);
}
