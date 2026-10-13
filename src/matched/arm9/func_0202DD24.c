/*
 * unit:     no
 * function: PMS_DRAW_Copy
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
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_CopyPixels  0x02043814  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_GetActorAnimSeq  0x0204B898  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
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
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *h);
struct Bmp;
extern void BMP_CopyPixels(struct Bmp *dst, const struct Bmp *src);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
struct Actor;
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

void PMS_DRAW_Copy(struct PmsDraw *p, u32 i, u32 j)
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
    dx = BMP_WIN_GetPosX(dst->handle) - BMP_WIN_GetPosX(src->handle);
    dy = BMP_WIN_GetPosY(dst->handle) - BMP_WIN_GetPosY(src->handle);
    BMP_CopyPixels((struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)src->handle)), (const struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)dst->handle)));
    h = dst->handle;
    BMP_WIN_TransferChars(h);
    BMP_WIN_MakeScreen(h);
    func_02041B6C(BMP_WIN_GetBgLayer(h));

    for (k = 0; k < 2; k++) {
        v = sub_0202E430(BMP_WIN_GetBgLayer(src->handle));
        CLACT_GetActorSurfacePos(src->actor[k], (struct PtS *)&pt, (u16)v);
        pt.x += dx * 8;
        pt.y += dy * 8;
        CLACT_AddActorSurfacePos(dst->actor[k], (const struct Vec2 *)(&pt), (u16)v);
        CLACT_SetActorAnimSeq(dst->actor[k], CLACT_GetActorAnimSeq(src->actor[k]));
        CLACT_SetActorDrawEnable(dst->actor[k], src->enabled[k]);
    }
    dst->live = src->live;
    dst->flags.b0 = src->flags.b0;
    dst->flags.b1 = src->flags.b1;
    for (k = 0; k < 2; k++) {
        dst->enabled[k] = src->enabled[k];
    }
}
