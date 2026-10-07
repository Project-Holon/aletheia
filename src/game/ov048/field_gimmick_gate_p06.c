/*
 * file:     field_gimmick_gate_p06.c
 * unit:     yes
 * function: func_021F3BC0, func_021F3C14
 * address:  0x021F3BC0
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02049030  0x02049030  arm
 *   func_02030734  0x02030734  arm
 *   func_021F4DE4  0x021F4DE4  thumb  ov048
 *   d_021F5224     0x021F5224  data  ov048  a1
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj00377.h"
#include "../../matched/include/Obj03645.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u32 func_02049030(u32 a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_021F4DE4(int a, int b, int c);
extern u32 func_020307B0(void *p);
void func_021F3BC0(u8 *p);
void func_021F3C14(char *p);
extern const char d_021F5224[];


void func_021F3BC0(u8 *p)
{
    int n;
    int i;

    if (*(u8 * *)&((struct Obj00377 *)p)->f20 == 0) {
        n = func_02049030(0xa6);
        ((struct Obj00377 *)p)->f20 = func_02030734(((struct Obj00377 *)p)->f0, n * 0x24, 0, d_021F5224, 0x4cb);
        for (i = 0; i < n; i++) {
            func_021F4DE4((int)(*(u8 * *)&((struct Obj00377 *)p)->f20 + i * 0x24), 0xa6, i);
        }
        p[0x24] = n;
    }
}

void func_021F3C14(char *p) { if (((struct Obj03645 *)p)->f20) { func_020307B0(((struct Obj03645 *)p)->f20); ((struct Obj03645 *)p)->f20=0; p[0x24]=0; } }
