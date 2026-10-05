/*
 * function: func_021B7968
 * address: 0x021B7968
 * packet: pkt_ov173_021B7968
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`off = 0x114;` before `off = 0x1b8;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 *
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0201BD28 0x0201BD28 thumb
 */
#include "../include/Obj03857.h"
#include "../include/Obj24182.h"
#include "../include/Obj24183.h"
#include "../include/Obj24184.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204B404(void *, u16 *, int);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_0201BD28(u16, u32);
void func_021B7968(char *p)
{
    u16 rect[2];
    u32 off;
    u32 i;
    u32 value;
    off = 0x1b8;
    for (i = 0; i < 4; i++) {
        rect[0] = 0x2f;
        rect[1] = i * 24 + 0x50;
        func_0204B404(*(void **)(p + i * 4 + 0x114), rect, 1);
        if (((struct Obj24182 *)(*(char * *)&((struct Obj03857 *)p)->f0))->f16 + i >= *(u8 *)(p + off)) {
            func_0204B3DC(*(void **)(p + i * 4 + 0x114), 0);
        } else {
            value = func_0201BD28(*(u16 *)(*(char * *)&((struct Obj24183 *)(*(char * *)&((struct Obj03857 *)p)->f0))->f10 + (((struct Obj24184 *)(*(char * *)&((struct Obj03857 *)p)->f0))->f16 + i) * 2), 0);
            func_0204B3DC(*(void **)(p + i * 4 + 0x114), 1);
            func_0204B878(*(void **)(p + i * 4 + 0x114), value);
        }
    }
}
