/*
 * file:     box2_seq_p04.c
 * unit:     yes
 * function: func_021E2094, func_021E20D4, func_021E2140, func_021E2154, func_021E216C
 * address:  0x021E2094
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02036270 0x02036270 arm
 *   d_021EFA4C 0x021EFA4C data a4
 *   func_021DCFC0  0x021DCFC0  thumb  ov170
 *   g_021EFA28  0x021EFA28  data  ov170
 *   d_021EFA2C 0x021EFA2C data a4
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj10654.h"

#define W(p) (*(char **)((p) + 0x2C))
struct TaskMenu;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef struct { int (*a)(char *); int (*b)(char *); } Pair;

typedef unsigned short u16;

typedef struct { void (*callback)(u8 *); u32 value; u32 next; } Dispatch;

extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern void func_020061E4(unsigned);
extern void func_02027974(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_02027858(struct TaskMenu *m);
extern int func_02036270(int a0, int a1);
extern int func_021DCFC0(char *p);
int func_021E2094(char *p);
int func_021E20D4(char *p);
int func_021E2140(int p);
int func_021E2154(unsigned char *p);
int func_021E216C(u8 *p);
extern const Pair d_021EFA4C[];
extern Dispatch d_021EFA2C;

int func_021E2094(char *p)
{
    if (func_02035C60() == 1) {
        func_020061E4(0x54C);
        func_020355D8(1);
        return ((struct Obj00000 *)p)->f28;
    }
    if (func_020362DC() & 3) {
        func_020061E4(0x54C);
        func_020355D8(0);
        return ((struct Obj00000 *)p)->f28;
    }
    return 6;
}

int func_021E20D4(char *p)
{
    func_02027974(*(void **)(W(p) + 0x1A0));
    if (func_020279E8(*(void **)(W(p) + 0x1A0)) == 1) {
        int r = func_02027A04(*(void **)(W(p) + 0x1A0));
        func_02027858(*(void **)(W(p) + 0x1A0));
        func_02036270(6, 6);
        if (r == 0)
            return d_021EFA4C[*(unsigned short *)(W(p) + 0x1A4)].a(p);
        else
            return d_021EFA4C[*(unsigned short *)(W(p) + 0x1A4)].b(p);
    }
    return 7;
}

int func_021E2140(int p)
{
    if (func_021DCFC0((char *)p) == 0)
        return ((struct Obj00000 *)p)->f28;
    return 8;
}

extern struct Ent { void (*fn)(void *); int a; int b; } g_021EFA28[];

/*
 * Dispatch through the 12-byte table at 0x021EFA28 keyed by p[0x12].
 *   CLOSES the operand-order residue: the image's `ldr r1,[r1,r3]` (base first)
 *   comes out of a pointer VARIABLE holding the element address; writing the
 *   subscript as a direct member access makes mwccarm encode `[r3,r1]`.
 */
int func_021E2154(unsigned char *p)
{
    struct Ent *e = &g_021EFA28[p[0x12]];
    e->fn(p);
    return 10;
}

int func_021E216C(u8 *p){if(((struct Obj10654 *)p)->f8!=1){(*(void (**)(u8 *))((u32)&d_021EFA2C.callback+p[0x12]*12))(p);((struct Obj10654 *)p)->f28=*(u32 *)((u32)&d_021EFA2C.value+p[0x12]*12);return 0;}return 10;}
