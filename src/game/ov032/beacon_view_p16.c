/*
 * file:     beacon_view_p16.c
 * unit:     yes
 * function: func_021F2404, func_021F253C, func_021F2544
 * address:  0x021F2404
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02158614 0x02158614 thumb ov010
 *   func_020275B8 0x020275B8 thumb
 *   func_020275D0 0x020275D0 thumb
 *   func_021945A4 0x021945A4 thumb ov021
 *   func_021F254C 0x021F254C thumb ov032
 *   func_02164B38 0x02164B38 thumb ov010
 *   func_020124AC 0x020124AC thumb
 *   func_021CD2A4 0x021CD2A4 thumb ov021
 *   func_021F5260 0x021F5260 thumb ov083
 *   func_021F5368 0x021F5368 thumb ov083
 *   ov083_id 0x00000053 data
 */
#include "../../matched/include/Obj20459.h"
#include "../../matched/include/Obj20460.h"

struct Desc;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 b;
} Args;

extern void func_02158614(void *p);
extern void func_020275B8(char *p, int v);
extern void *func_020275D0(char *p);
extern void *func_021945A4(void *a, u32 b, u32 c);
extern void *func_021F254C(char *p, void *task, int a, u32 b);
extern void *func_02164B38(void *a, void *b, u8 c);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern u32 func_021CD2A4(u32 a, u32 b, u32 x, u32 c, u32 d);
extern void *func_021F5260(void *a0, int *a1);
extern void *func_021F5368(void *p, void *q);
void *func_021F2404(char *p, int go);
void func_021F253C(char *p, int v);
void func_021F2544(char *p);
extern u8 ov083_id[];


/*
 * Byte-correct; the only wildcards are the bls to two unlabelled arm9
 * leaves, Ilias's (blocker: no witness outside the range). Verified leaf C
 * (both EXACT, thumb, `one --thumb` with no --region):
 *   0x020275B8 (12 bytes incl. pool word 0x0B0E):
 *     typedef unsigned char u8;
 *     void func_020275B8(char *p, u8 v) { p[0xb0e] = v; }
 *   0x020275D0 (12 bytes incl. pool word 0x0B0C):
 *     void *func_020275D0(char *p) { return p + 0xb0c; }
 * 0x53 is ov083's id (func_021F5260/func_021F5368 are ov083 children).
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/func_020275A8,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 */
void *func_021F2404(char *p, int go)
{
    void *r;
    Args args;

    if (go == 0)
        return 0;
    switch (*(u16 *)(p + 0x70)) {
    case 2:
        func_02158614((void *)(*(int *)(p + 0x1c)));
    case 1:
    case 3:
        func_020275B8(*(void **)(p + 0x34), 0);
        r = func_021F254C(p, func_021945A4(*(void **)p, (u32)(*(void **)(p + 8)), 0), 0, 3);
        break;
    case 4:
        r = func_021F254C(p, func_02164B38(*(void **)p, *(void **)(p + 8), *(u8 *)(p + 0x7e) + *(u8 *)(p + 0x7c)), 1, 0);
        break;
    case 5:
        args.a = *(u8 *)(p + 0x7f);
        args.b = *(u8 *)(p + 0x80);
        r = func_021F254C(p, func_020124AC(*(void **)p, (u32)ov083_id, (void *)func_021F5260, (u32)(&args)), 2, *(u32 *)(p + 0xd0));
        p[0x7f] = 0x30;
        break;
    case 6:
        r = func_021F254C(p, func_020124AC(*(void **)p, (u32)ov083_id, (void *)func_021F5368, (u32)(*(void **)(p + 8))), 2, *(u32 *)(p + 0xc0));
        break;
    case 7:
        r = func_021F254C(p, func_020124AC(*(void **)p, (u32)ov083_id, (void *)func_021F5368, (u32)(*(void **)(p + 8))), 2, *(u32 *)(p + 0xf0));
        p[0x79] = 0;
        break;
    case 8:
        r = func_021F254C(p, (void *)func_021CD2A4((u32)(*(void **)p), (u32)(*(void **)(p + 8)), 0, 7, (u32)func_020275D0((char *)(*(int *)(p + 0x34)))), 0, 1);
        break;
    default:
        return 0;
    }
    func_021F2544(p);
    return r;
}


void func_021F253C(char *p, int v)
{
    ((struct Obj20459 *)p)->f70 = v;
}


void func_021F2544(char *p)
{
    ((struct Obj20460 *)p)->f70 = 0;
}
