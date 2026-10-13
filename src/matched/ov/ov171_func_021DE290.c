/*
 * function: func_021DE290
 * address: 0x021DE290
 * packet: pkt_ov171_021DE290
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021DE2D2.
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 */
#include "../include/Obj08251.h"
#include "../include/Obj24058.h"
typedef unsigned short u16;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Obj *func_021DE290(char *p, const char *q)
{
    return CLACT_CreateActor((void *)((struct Obj24058 *)p)->fB70, *(int *)(p + 0xbb4 + ((struct Obj08251 *)q)->f8 * 4),
        *(int *)(p + 0xbe8 + ((struct Obj08251 *)q)->fC * 4), *(int *)(p + 0xc1c + ((struct Obj08251 *)q)->f10 * 4),
        q, ((struct Obj08251 *)q)->f16, 0x8c);
}
