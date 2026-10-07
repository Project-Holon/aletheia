/*
 * file:     weather_task_p02.c
 * unit:     yes
 * function: func_021A1B50, func_021A1B74, func_021A1BDC, func_021A1BE4
 * address:  0x021A1B50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A21B0  0x021A21B0  thumb  ov021
 *   d_021D886C     0x021D886C  data  ov021  a4
 *   d_021D8868     0x021D8868  data  ov021  a4
 *   func_021A20C8  0x021A20C8  thumb  ov021
 *   func_021A1C04  0x021A1C04  thumb  ov021
 *   func_021A1BF8  0x021A1BF8  thumb  ov021
 *   func_021A1FEC  0x021A1FEC  thumb  ov021
 *   func_021A1C34  0x021A1C34  thumb
 */
#include "../../matched/include/Obj00755.h"
#include "../../matched/include/Obj02701.h"

struct O;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct {
    u8 pad[0x20];
    u32 items[2];
} Obj021A1B50;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

int func_021A21B0(u8 *a0);
extern void func_021A20C8(struct O *p);
extern void func_021A1C04(u8 *p);
extern void func_021A1BF8(u32 *p, u32 v);
extern void func_021A1FEC(struct O *p, u32 v, u8 b, u32 c, u32 d, u32 e, u32 g);
extern void func_021A1C34();
int func_021A1B50(Obj021A1B50 *p);
void func_021A1B74(u8 *p, int a, int f);
void func_021A1BDC(void);
int func_021A1BE4(u32 a, u32 b, u32 c, u32 d);
extern const u32 d_021D886C[];
extern const u32 d_021D8868[];


int func_021A1B50(Obj021A1B50 *p)
{
    int i;

    if (p != 0) {
        for (i = 0; i < 2; i++) {
            if (func_021A21B0((u8 *)p->items[i]) == 1)
                return 1;
        }
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A1B74(u8 *p, int a, int f)
{
    int i;
    u32 t;

    if (a == ((struct Obj00755 *)p)->fC && a != 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        func_021A20C8((struct O *)(*(u32 *)(p + 0x20 + i * 4)));
    }
    func_021A1C04(p);
    ((struct Obj00755 *)p)->fA = 0;
    func_021A1BF8((u32 *)p, d_021D886C[a * 2]);
    t = d_021D8868[a * 2];
    func_021A1FEC((struct O *)(((struct Obj00755 *)p)->f20), t, 0, 0, 1, 1, f);
    ((struct Obj00755 *)p)->fC = a;
    ((struct Obj00755 *)p)->fE = 0xFFFF;
}


/*
 * Tail-call thunk: forwards to func_021A1C34 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A1BDC(void)
{
    func_021A1C34();
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A1BE4(u32 a, u32 b, u32 c, u32 d)
{
func_021A1C34(a, b, c, d);
((struct Obj02701 *)((u8 *)(a)))->f10 = 0;
return 0;
}
