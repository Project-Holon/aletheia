/*
 * function: func_021D657C
 * address: 0x021D657C
 * packet: pkt_ov131_021D657C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4418 0x021D4418 thumb ov131
 *   func_02012704 0x02012704 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj01255.h"
#include "../include/Obj23132.h"
typedef unsigned char u8;
struct S020315D4;
extern int func_021D4418(char *p);
extern void func_02012704(u8 *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
int func_021D657C(struct S020315D4 *handle, int unused, int mode, char *p)
{
    if (!func_021D4418(p)) return 0;
    if (!mode) {
        func_02012704(*(u8 * *)&((struct Obj23132 *)(*(char * *)&((struct Obj01255 *)p)->f8))->f8);
        func_020307B0(*(void **)*(char * *)&((struct Obj01255 *)p)->f8);
        func_020307B0(((struct Obj01255 *)p)->f8);
    }
    func_020315D4(handle);
    func_020306F0(0x42);
    return 1;
}
