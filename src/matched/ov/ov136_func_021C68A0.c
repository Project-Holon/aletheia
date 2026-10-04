/*
 * function: func_021C68A0
 * address:  0x021C68A0
 * packet:   pkt_ov136_021C68A0
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C4E4            0x0201C4E4  thumb
 *   func_0201C6C4            0x0201C6C4  thumb
 *   func_0202CD94 0x0202CD94 thumb
 *   func_0202DBC4  0x0202DBC4  thumb
 *   func_020310C4            0x020310C4  arm
 *   func_02045334            0x02045334  arm
 *   func_02045770            0x02045770  arm
 *   func_021C6594 0x021C6594 thumb
 *   d_021C7DA8 0x021C7DA8 data a4
 */
#include "../include/Obj01752.h"
#include "../include/Obj08204.h"
#include "../include/Obj08205.h"
#include "../include/Obj23598.h"
#include "../include/Obj23599.h"
#include "../include/Obj23600.h"
#include "../include/Obj23601.h"
#include "../include/Obj23602.h"
#include "../include/Obj23603.h"
#include "../include/Obj23604.h"
#include "../include/Obj23605.h"
#include "../include/Obj23606.h"

typedef unsigned char u8;
typedef unsigned int u32;
struct WinMgr;
extern int (*const d_021C7DA8[])(u8 *);
extern void func_0202CD94(struct WinMgr *mgr);
extern void func_021C6594(u8 *);
struct Descriptor;
struct PrintSys;
struct Tcbl;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02045334(struct Descriptor *d);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_020310C4(struct Tcbl *p);
extern void func_0202DBC4(u8 *p);
int func_021C68A0(u8 *p, int *st)
{
    int i;
    int j;
    *st = d_021C7DA8[*st](p);
    if (*st == 0x1B) {
        return 0;
    }
    if (*(u8 * *)&((struct Obj01752 *)p)->f8 != 0) {
        func_0202CD94(**(struct WinMgr ** *)&((struct Obj01752 *)p)->f8);
        func_021C6594(*(u8 * *)&((struct Obj01752 *)p)->f8);
        if (((struct Obj23598 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f1C4 != 0) {
            func_0201C4E4(((struct Obj23599 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f1C4);
            for (i = 0; i < 0x1B; i++) {
                void *h = ((struct Obj23600 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f1C4;
                u8 *e = *(u8 * *)&((struct Obj01752 *)p)->f8 + 0xC4 + i * 8;
                if (e[4] != 0) {
                    if (func_0201C6C4(h, func_02045770(((struct Obj08204 *)e)->f0)) == 0) {
                        func_02045334(((struct Obj08204 *)e)->f0);
                        e[4] = 0;
                    }
                }
            }
        }
        if (((struct Obj23601 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f1CC != 0) {
            func_020310C4(((struct Obj23602 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f1CC);
        }
        if (((struct Obj23603 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f36C != 0) {
            func_0202DBC4(((struct Obj23604 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f35C);
            func_0201C4E4(((struct Obj23605 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f36C);
            for (j = 0x1B; j < 0x20; j++) {
                void *g = ((struct Obj23606 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f1C4;
                u8 *f = *(u8 * *)&((struct Obj01752 *)p)->f8 + 0xC4 + j * 8;
                if (f[4] != 0) {
                    if (func_0201C6C4(g, func_02045770(((struct Obj08205 *)f)->f0)) == 0) {
                        func_02045334(((struct Obj08205 *)f)->f0);
                        f[4] = 0;
                    }
                }
            }
        }
    }
    return 1;
}
