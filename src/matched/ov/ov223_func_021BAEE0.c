/*
 * function: func_021BAEE0
 * address: 0x021BAEE0
 * packet: pkt_ov223_021BAEE0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing AF2E halfword is zero alignment padding.
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02031140 0x02031140 arm
 *   func_02045C04 0x02045C04 arm
 */
#include "../include/Obj02266.h"
typedef unsigned char u8;
struct Rec3;
struct U16Vec;
struct Descriptor;
struct S02031140;
struct Rec;
extern void func_0201CE48(struct Rec3 *);
extern void func_02045808(struct U16Vec *);
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02031140(struct S02031140 *);
extern u32 func_02045C04(struct Rec *rec);
void func_021BAEE0(char *p)
{
    u8 i;
    if (*(struct Rec3 * *)&((struct Obj02266 *)p)->f250)
        func_0201CE48(*(struct Rec3 * *)&((struct Obj02266 *)p)->f250);
    if (*(struct U16Vec * *)&((struct Obj02266 *)p)->f258)
        func_02045808(*(struct U16Vec * *)&((struct Obj02266 *)p)->f258);
    for (i = 0; i < 3; i++)
        func_020452E8(*(struct Descriptor **)(p + 0x238 + i * 4));
    func_02031140(*(struct S02031140 * *)&((struct Obj02266 *)p)->f254);
    func_02045C04(*(struct Rec * *)&((struct Obj02266 *)p)->f234);
}
