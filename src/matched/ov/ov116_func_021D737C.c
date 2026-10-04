/*
 * function: func_021D737C
 * address: 0x021D737C
 * packet: pkt_ov116_021D737C
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120B4 0x020120B4 thumb
 *   d_021D6338 0x021D6338 data ov115 a4
 *   ov115_id 0x73 data
 */
#include "../include/Obj00671.h"
#include "../include/Obj22627.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct IcaAnime;
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 d_021D6338[];
extern u8 ov115_id[];
void func_021D737C(u8 *p) {
    ((struct Obj00671 *)p)->f9B0=*(u32 *)&((struct Obj00671 *)p)->f1844;
    ((struct Obj00671 *)p)->f9B4=0;
    ((struct Obj00671 *)p)->f9C8=1;
    ((struct Obj00671 *)p)->f9B8=1;
    ((struct Obj00671 *)p)->f9BC=44;
    ((struct Obj00671 *)p)->f9C0=p+0x9f4;
    func_020120B4(((struct Obj22627 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f4,(u32)ov115_id,d_021D6338,p+0x9b0);
}
