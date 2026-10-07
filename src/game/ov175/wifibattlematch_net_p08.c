/*
 * file:     wifibattlematch_net_p08.c
 * unit:     yes
 * function: func_021D63DC, func_021D63F8, func_021D644C, func_021D6460, func_021D646C, func_021D6524
 * address:  0x021D63DC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D639C  0x021D639C  thumb
 *   func_021D63BC  0x021D63BC  thumb
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_021E7520 0x021E7520 thumb ov177
 *   func_021E7710   0x021E7710  thumb
 *   func_021E8AA0   0x021E8AA0  thumb
 *   func_021E8A80   0x021E8A80  thumb
 *   func_021E8A90   0x021E8A90  thumb
 *   func_021E64C8   0x021E64C8  thumb
 *   func_021E8AA8   0x021E8AA8  thumb
 *   func_021E777C 0x021E777C thumb ov177
 *   func_0200DFD8 0x0200DFD8 thumb
 *   func_0200DFE4 0x0200DFE4 thumb
 *   func_0200E008  0x0200E008  thumb
 */
#include "../../matched/include/Obj10680.h"
#include "../../matched/include/Obj14327.h"
#include "../../matched/include/Obj00171.h"

struct Work;
typedef unsigned long u32_021D63DC;

typedef unsigned int u32_021D63F8;

typedef unsigned long u32_021D644C;

typedef unsigned int u32_021D646C;

typedef unsigned int u32_021D6524;

typedef unsigned char  u8;

extern u32_021D63DC func_021D63BC(char *obj);
extern void func_021D639C(char *obj);
extern int func_021E5548(int *);
extern u32_021D63F8 func_021E7520(u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8);
extern void func_021E7710(u32_021D644C p);
extern int func_021E777C(struct Work *);
extern u32_021D646C func_0200DFD8(u32_021D646C, u32_021D646C, u32_021D646C);
extern void func_0200DFE4(u32_021D646C, u32_021D646C, u32_021D646C, u32_021D646C);
extern void func_0200E008(u8 *base, int a, int idx);
void func_021D63DC(char *obj);
void func_021D63F8(u32_021D63F8 *p,u32_021D63F8 arg);
void func_021D644C(char *obj);
int func_021D6460(char *p);
int func_021D646C(u32_021D646C save, u32_021D646C kind, u32_021D646C obj);
void func_021D6524(int a, int b, u32_021D6524 c);


/*
 * Only when the +0x18 pointer is live: spin on func_021D63BC until it
 *     reports ready, then hand the object to the func_021D639C release path.
 */
void func_021D63DC(char *obj)
{
    if (((struct Obj10680 *)obj)->f18 != 0) {
        while (func_021D63BC(obj) == 0)
            ;
        func_021D639C(obj);
    }
}

/*
 * mode: original assigns constructor selectors only for mode 0 or 1.
 */
void func_021D63F8(u32_021D63F8 *p,u32_021D63F8 arg)
{
    u32_021D63F8 b,a;
    if (p[7] == 0) {
        u32_021D63F8 base = func_021E5548((int *)p[0]);
        u32_021D63F8 mode = ((u32_021D63F8 *)p[16])[0];
        if (mode == 0) { a=1; b=2; }
        else if (mode == 1) { a=0; b=3; }
        p[7]=func_021E7520(arg,base,p[1],p[2],p[3],p[4],p[5],b,a,0,87);
    }
}


/*
 * Release path for the ov175 object's 0x1c pointer: free it through
 *     0x021E7710 and clear the field, null-safe.
 */
void func_021D644C(char *obj)
{
    u32_021D644C p = ((struct Obj14327 *)obj)->f1C;

    if (p != 0) {
        func_021E7710(p);
        ((struct Obj14327 *)obj)->f1C = 0;
    }
}

/*
 * Unlabelled blocker leaf for func_021D5908; parent confirmed unowned.
 */
int func_021D6460(char *p)
{
    return func_021E777C(*(struct Work * *)&((struct Obj00171 *)p)->f1C);
}

int func_021D646C(u32_021D646C save, u32_021D646C kind, u32_021D646C obj)
{
    int *q;
    u32_021D646C a;
    u32_021D646C b;
    u32_021D646C c;
    int changed;
    switch (kind) {
    case 0:
        q = *(int **)(*(u32_021D646C *)(obj + 0x40) + 0x38);
        a = q[3];
        b = q[0x40 / 4];
        c = q[0x3C / 4];
        break;
    case 1:
        q = *(int **)(*(u32_021D646C *)(obj + 0x40) + 0x38);
        a = q[0];
        b = q[0x28 / 4];
        c = q[0x24 / 4];
        break;
    case 2:
        q = *(int **)(*(u32_021D646C *)(obj + 0x40) + 0x38);
        a = q[0x10 / 4];
        b = q[0x48 / 4];
        c = q[0x44 / 4];
        break;
    case 3:
        q = *(int **)(*(u32_021D646C *)(obj + 0x40) + 0x38);
        a = q[1];
        b = q[0x30 / 4];
        c = q[0x2C / 4];
        break;
    case 4:
        q = *(int **)(*(u32_021D646C *)(obj + 0x40) + 0x38);
        a = q[2];
        b = q[0x38 / 4];
        c = q[0x34 / 4];
        break;
    }
    changed = (a != func_0200DFD8(save, kind + 5, 0) || b != func_0200DFD8(save, kind + 5, 1) || c != func_0200DFD8(save, kind + 5, 2));
    func_0200DFE4(save, kind + 5, 0, a);
    func_0200DFE4(save, kind + 5, 1, b);
    func_0200DFE4(save, kind + 5, 2, c);
    return changed;
}


/*
 * Thumb jump table over 0..4: modes 1 and 4 pass the constant 1, modes 0 and
 * 3 pass 2, mode 2 and everything above 4 do nothing.
 *
 * func_/sub_ label in asm/arm9/main.s and no other reference anywhere in the
 * listings, so the site reports "unresolved: 0200E008 (arm, from header) has
 * no witness outside 021D6524..021D6550".  Bytes and size are correct
 * (44 bytes, 2 relocation sites, both wildcarded); it needs an entry for the
 * arm9 target to promote.
 */
void func_021D6524(int a, int b, u32_021D6524 c)
{
    switch (c) {
    case 1:
    case 4:
        func_0200E008((u8 *)a, b, 1);
        break;
    case 0:
    case 3:
        func_0200E008((u8 *)a, b, 2);
        break;
    }
}
