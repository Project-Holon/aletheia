/*
 * function: func_021BD8D8
 * address: 0x021BD8D8
 * packet: pkt_ov099_021BD8D8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021C2864 0x021C2864 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 * return-evidence: caller consumes r0 after both ARM9 calls despite legacy void declarations; four original outgoing registers retained.
 */
#include "../include/Obj07951.h"
#include "../include/Obj22042.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 a, b; } Request;
extern u8 func_021BDD54(int, void *);
extern void func_021C2864(void *, u8);
typedef unsigned int   u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
int func_021BD8D8(char *p, int ret)
{
    Request request;
    request.a = func_021BDD54((int)p, ((struct Obj07951 *)p)->f8);
    request.b = 1 - ((struct Obj22042 *)(*(char * *)&((struct Obj07951 *)p)->f248))->f46;
    if (func_0203D3A8(func_020399A8(), 0xa03, 4, (unsigned)&request) != 0) {
        ((struct Obj07951 *)p)->f1CC = 0x81;
        func_021C2864(((struct Obj07951 *)p)->f8, request.b);
    }
    return ret;
}
