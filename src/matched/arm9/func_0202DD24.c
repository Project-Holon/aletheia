/*
 * unit:     no
 * function: func_0202DD24
 * address:  0x0202DD24
 * packet:   pkt_0202DD24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Copies element i onto element j of the pms_draw owner, sprite state
 * included (docs/families/pms_draw.h). EXACT* only because the listing
 * extent runs on over the three unlabelled setters at 0x0202DE5C
 * (src/matched/unit_0202DE5C.c); the function itself is 310 bytes.
 *
 * Closed in wave 14 from the wave-12 note (8 bytes, dst/dy spill slots):
 *   - the handles are read through the element pointers, src->handle and
 *     dst->handle, not e[i]/e[j]; the compiler still folds them to the
 *     image's `ldr r0,[r6,r7]` / `ldr r0,[r6,dj]`, but dst now stays a
 *     named value and takes the image's slot sp+8;
 *   - no `e` local: src = &p->elems[i]; dst = &p->elems[j];
 *   - dx declared before dy (dx at sp+4, dy at sp+0);
 *   - the loop counter k declared FIRST: with src declared ahead of it,
 *     src takes r4 and the call temporaries/k take r5, the mirror image.
 *
 * symbols:
 *   sub_0202E430   0x0202E430  thumb
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045770  0x02045770  arm
 *   func_02043814  0x02043814  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B898  0x0204B898  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Pt { s16 x; s16 y; };
struct PmsFlags { u32 b0 : 1; u32 b1 : 1; u32 b2 : 1; u32 rest : 29; };
struct PmsElem {
    void *handle;
    u8    live;
    u8    pad05[3];
    void *actor[2];
    s32   x;
    s32   y;
    struct PmsFlags flags;
    u32   unk1c;
    u32   enabled[2];
};
struct PmsDraw { u8 pad[0xc]; struct PmsElem *elems; };

extern u32  sub_0202E430(u32 id);
struct Cfg;
struct Descriptor;
struct Obj;
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u32  func_02045770(void *h);
extern void func_02043814(u32 a, u32 b);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *a, struct PtS *p, unsigned int v);
extern void func_0204B404(void *a, struct Pt *p, u16 v);
extern u16 func_0204B898(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);

void func_0202DD24(struct PmsDraw *p, u32 i, u32 j)
{
    int k;
    struct PmsElem *src;
    struct PmsElem *dst;
    s32 dx;
    s32 dy;
    u32 v;
    struct Pt pt;
    void *h;

    src = &p->elems[i];
    dst = &p->elems[j];
    dx = func_02045758(dst->handle) - func_02045758(src->handle);
    dy = func_02045760(dst->handle) - func_02045760(src->handle);
    func_02043814(func_02045770(src->handle), func_02045770(dst->handle));
    h = dst->handle;
    func_02045334(h);
    func_02045374(h);
    func_02041B6C(func_02045730(h));

    for (k = 0; k < 2; k++) {
        v = sub_0202E430(func_02045730(src->handle));
        func_0204B454(src->actor[k], (struct PtS *)&pt, (u16)v);
        pt.x += dx * 8;
        pt.y += dy * 8;
        func_0204B404(dst->actor[k], &pt, v);
        func_0204B878(dst->actor[k], func_0204B898(src->actor[k]));
        func_0204B3DC(dst->actor[k], src->enabled[k]);
    }
    dst->live = src->live;
    dst->flags.b0 = src->flags.b0;
    dst->flags.b1 = src->flags.b1;
    for (k = 0; k < 2; k++) {
        dst->enabled[k] = src->enabled[k];
    }
}
