/*
 * function: func_021D73E0
 * address: 0x021D73E0
 * packet: pkt_ov116_021D73E0
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120B4 0x020120B4 thumb
 *   d_021D654C 0x021D654C data ov115 a4
 *   ov115_id 0x73 data
 */
#include "../include/Obj00671.h"
#include "../include/Obj22629.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct IcaAnime;
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 d_021D654C[];
extern u8 ov115_id[];
void func_021D73E0(u8 *p) {
    ((struct Obj00671 *)p)->f9D8=*(u32 *)&((struct Obj00671 *)p)->f1844;
    ((struct Obj00671 *)p)->f9DC=0;
    ((struct Obj00671 *)p)->f9E0=1;
    ((struct Obj00671 *)p)->f9E4=1;
    func_020120B4(((struct Obj22629 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f4,(u32)ov115_id,d_021D654C,p+0x9d8);
}
