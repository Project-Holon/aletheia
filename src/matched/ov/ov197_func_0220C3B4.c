/*
 * function: B_BAG_MAIN_CreateItemActor
 * address: 0x0220C3B4
 * packet: pkt_ov197_0220C3B4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * matching: const indices restores the load/store scheduling; mutable indices differ in 29 bytes.
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 */
#include "../include/Obj00315.h"
#include "../include/Obj25033.h"
typedef unsigned short u16;
typedef struct { u16 a,b,c; unsigned char d,e; } Config;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Obj *B_BAG_MAIN_CreateItemActor(char *p,const int *indices)
{
    Config c;
    c.a=0;c.b=0;c.c=0;c.d=1;c.e=1;
    return CLACT_CreateActor((void *)*(unsigned *)&((struct Obj00315 *)p)->f420,*(unsigned *)(p+indices[0]*4+0x544),*(unsigned *)(p+indices[1]*4+0x568),*(unsigned *)(p+indices[2]*4+0x58c),&c,1,((struct Obj25033 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
}
