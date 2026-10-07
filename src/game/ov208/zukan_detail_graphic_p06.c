/*
 * file:     zukan_detail_graphic_p06.c
 * unit:     yes
 * function: func_021BD3CC, func_021BD3F8
 * address:  0x021BD3CC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ov208_func_021BD404  0x021BD404  thumb
 *   func_0204B404        0x0204B404  arm
 *   func_021BD404 0x021BD404  thumb  ov208
 */
struct Obj;
struct Vec2;
typedef unsigned short u16;

typedef unsigned int   u32;

struct Ov208Rec {
    u32 f0;
    u32 pad4[5];
    u16 x;
    u16 y;
};

struct Ov208Mgr {
    u32 pad0[8];
    u32 f20;
};

extern struct Ov208Rec *ov208_func_021BD404(struct Ov208Mgr *p, int key);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern char *func_021BD404(void *mgr, int key);
void ov208_func_021BD3CC(struct Ov208Mgr *p, int key, u16 *pos);
void func_021BD3F8(void *mgr, int key);


void ov208_func_021BD3CC(struct Ov208Mgr *p, int key, u16 *pos)
{
    struct Ov208Rec *r = ov208_func_021BD404(p, key);

    r->x = pos[0];
    r->y = pos[1];
    func_0204B404((struct Obj *)r->f0, (const struct Vec2 *)pos, (u16)(p->f20 >= 4 ? 1 : 0));
}


void func_021BD3F8(void *mgr, int key)
{
    *(int *)(func_021BD404(mgr, key) + 0x34) = 1;
}
