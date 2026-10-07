/*
 * file:     shinka_demo_view_p05.c
 * unit:     yes
 * function: func_02206044, func_0220604C, func_02206050, func_02206058, func_0220605C, func_02206064, func_0220606C, func_02206070, func_02206074, func_02206078, func_0220609C, func_022060BC, func_022060C8
 * address:  0x02206044
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0220673C  0x0220673C  thumb
 *   func_02206750  0x02206750  thumb
 *   func_02014B08 0x02014B08 thumb
 *   func_02016020 0x02016020 thumb
 *   func_02015BF0 0x02015BF0 thumb
 *   func_02014BA8 0x02014BA8 thumb
 *   func_02017E1C 0x02017E1C thumb
 */
#include "../../matched/include/Obj08349.h"
#include "../../matched/include/Obj02911.h"

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

typedef int fx32;

extern void *func_02014B08(u32 id, void *heap);
extern void func_02016020(void *p, u32 v);
extern void func_02015BF0(void *obj);
extern void func_02014BA8(u8 *a0);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
void func_02206044(int *p);
int func_0220604C(int *p);
void func_02206050(int *p);
int func_02206058(int *p);
void func_0220605C(int *p);
void func_02206064(int *p);
int func_0220606C(int *p);
int func_02206070(int *p);
int func_02206074(int *p);
int func_02206078(int *p);
void func_0220609C(char *a);
void func_022060BC(char *p);
fx32 func_022060C8(void *p);

/*
 * Setter for the +0x1c flag word of the ov195 scene object driven by
 * func_022040E0.  Unlabelled in the listing (a leaf that saves no lr, so it
 * prints inside a .word run); region-qualified because ov094 overlaps.
 */
void func_02206044(int *p)
{
    p[7] = 1;
}

/*
 * Getter for the +0x20 word of the ov195 scene object (unlabelled leaf).
 */
int func_0220604C(int *p)
{
    return p[8];
}

/*
 * Setter for the +0x24 flag word of the ov195 scene object (unlabelled leaf).
 */
void func_02206050(int *p)
{
    p[9] = 1;
}

/*
 * Getter for the +0x28 word of the ov195 scene object (unlabelled leaf).
 */
int func_02206058(int *p)
{
    return p[10];
}

/*
 * Setter for the +0x2c flag word of the ov195 scene object (unlabelled leaf).
 */
void func_0220605C(int *p)
{
    p[11] = 1;
}

/*
 * Setter for the +0x30 flag word of the ov195 scene object (unlabelled leaf).
 */
void func_02206064(int *p)
{
    p[12] = 1;
}

/*
 * Getter for the +0x34 word of the ov195 scene object (unlabelled leaf).
 */
int func_0220606C(int *p)
{
    return p[13];
}

/*
 * Getter for the +0x38 word of the ov195 scene object (unlabelled leaf).
 */
int func_02206070(int *p)
{
    return p[14];
}

/*
 * Getter for the +0x3c word of the ov195 scene object (unlabelled leaf).
 */
int func_02206074(int *p)
{
    return p[15];
}

/*
 * Leaf of the func_022040E0 dependency tree: on a positive func_0220673C
 * probe it sets the +0x40 word and the +0x14 state word of the scene object
 * and notifies func_02206750; returns 1, else 0.
 */
int func_02206078(int *p)
{
    int func_0220673C(int *);
    void func_02206750(int *);

    if (func_0220673C(p) != 0) {
        p[0x10] = 1;
        p[5] = 0xc;
        func_02206750(p);
        return 1;
    }
    return 0;
}


/*
 * 0x02016020 (arm9 Thumb leaf `str r1,[r0,#0x30]; bx lr`) resolves as label
 * since its function_starts seed (2026-09-27). EXACT*: the listing extent
 * includes the 2 bytes of alignment padding at 0x022060BA.
 */
void func_0220609C(char *a)
{
    ((struct Obj08349 *)a)->f4C = (u32)func_02014B08(2, (void *)(((struct Obj08349 *)a)->f0));
    func_02016020((void *)(((struct Obj08349 *)a)->f4C), 0x30000);
    func_02015BF0((void *)(((struct Obj08349 *)a)->f4C));
}

void func_022060BC(char *p){func_02014BA8(((struct Obj02911 *)p)->f4C);}


fx32 func_022060C8(void *p)
{
    int v = func_02017E1C(p, 5, 0);
    fx32 r = -0x12000;

    switch (v) {
    case 0x260:
        r = -0x1b000;
        break;
    case 0x261:
        r = -0x27000;
        break;
    case 0x40:
        r = -0x11e66;
        break;
    }
    return r;
}
