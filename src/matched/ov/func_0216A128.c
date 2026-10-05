/*
 * function: func_0216A128
 * address:  0x0216A128
 * packet:   pkt_0216A128
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Three teardown calls on the three arm9 handles the object carries.
 *
 * symbols:
 *   func_02027FD8   0x02027FD8  thumb
 *   func_02045808   0x02045808  arm
 */
#include "../include/Obj09164.h"
#include "../include/Obj17748.h"
#include "../include/Obj17749.h"
#include "../include/Obj17750.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct TaskMenuState;
struct U16Vec;
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_02045808(struct U16Vec *vec);

void func_0216A128(void *p)
{
    func_02027FD8(((struct Obj17748 *)(*(char * *)&((struct Obj09164 *)p)->f18))->f3C);
    func_02045808(((struct Obj17749 *)(*(char * *)&((struct Obj09164 *)p)->f18))->f30);
    func_02045808(((struct Obj17750 *)(*(char * *)&((struct Obj09164 *)p)->f18))->f24);
}

