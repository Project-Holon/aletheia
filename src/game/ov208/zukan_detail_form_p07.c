/*
 * file:     zukan_detail_form_p07.c
 * unit:     yes
 * function: func_021C4F78, func_021C4FDC, func_021C5000, func_021C5078, func_021C5090, func_021C50F8
 * address:  0x021C4F78
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
 *   func_02014B08  0x02014B08  thumb
 *   func_02016020  0x02016020  thumb
 *   func_02015BF0  0x02015BF0  thumb
 *   func_0202D060  0x0202D060  thumb
 *   func_02014CB8  0x02014CB8  thumb
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_02014CEC  0x02014CEC  thumb
 *   func_02030734  0x02030734  arm
 *   data_021C8E64  0x021C8E64  data
 *   func_020172AC  0x020172AC  thumb
 *   func_02017168  0x02017168  thumb
 *   func_020159C8  0x020159C8  thumb
 *   func_02015FF0  0x02015FF0  thumb
 *   func_02015E04  0x02015E04  thumb
 *   func_02015CAC  0x02015CAC  thumb
 *   data_021C8804  0x021C8804  data
 *   func_02015EA0  0x02015EA0  thumb
 *   func_02015F14  0x02015F14  thumb
 *   func_02015C78  0x02015C78  thumb
 *   _fflt  0x0209BDBC  arm
 *   _fgr  0x0209BBB0  arm
 *   _fmul  0x0209C77C  arm
 *   _fadd  0x0209C95C  arm
 *   _fsub  0x0209CB8C  arm
 *   _ffix  0x0209C494  arm
 *   func_02015C30  0x02015C30  thumb
 *   data_021C8E40  0x021C8E40  data
 */
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))
struct Sub02014CB8Obj;
struct Ctx;
struct Obj;
struct Rec;
struct Sub150;
struct Stats;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Ov208Menu {
    u32 f0;
    u32 f4;
    u32 cam;
    u8  padc[0x110];
    void *mem;
    void *heap3d;
};

typedef struct {
    int a;
    int b;
    int c;
    int d;
} T;

typedef signed int    fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec_021C5000;

struct Ov208MonArc {
    u8 d[0x24];
};

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec_021C5090;

typedef signed short   s16;

typedef struct {
    int x;
    int y;
    int z;
} Vec_021C50F8;

struct Ov208Cam {
    u32 pad0[6];
    Vec_021C50F8 ofs;
};

extern void *func_02014B08(u32 id, void *heap);
extern void func_02016020(void *p, u32 v);
extern void func_02015BF0(void *obj);
extern int func_0202D060(void);
extern void func_02014CB8(struct Sub02014CB8Obj *o, u32 x);
extern u32  func_02030CB0(u32 n);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_02014CEC(u8 *p, u32 value);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02014CD4(struct Sub02014CB8Obj *o);
extern void func_02014BA8(u8 *a0);
extern void func_02030DA4(int);
extern u32 func_020307B0(void *p);
extern void func_020172AC(int a0, int a1);
extern void func_02017168(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct Stats *out, u32 a6);
extern struct Rec *func_020159C8(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void func_02015FF0(char *p, int v);
extern void func_02015E04(void *p);
extern void func_02015CAC(void *p, u32 *src);
extern void func_02015EA0(void *p);
extern void func_02015BA4(void *sys, void *obj);
extern s16 func_02015F14(void *p);
extern void func_02015C78(void *p, u32 *src);
extern void func_02015C30(void *p, u32 *out);
void ov208_func_021C4F78(u16 *heap, struct Ov208Menu *p);
void func_021C4FDC(int unused, T *p);
u32 ov208_func_021C5000(void *sys, u32 species, u32 gender, u32 side, u32 form, u32 shiny, u32 personality, u32 extra);
void func_021C5078(int a, int b);
void ov208_func_021C5090(u32 obj);
void ov208_func_021C50F8(u32 obj, Vec_021C50F8 *out);
extern const char data_021C8E64[];
extern const Vec_021C5000 data_021C8804;
extern struct Ov208Cam data_021C8E40;


void ov208_func_021C4F78(u16 *heap, struct Ov208Menu *p)
{
    p->cam = (u32)func_02014B08(4, (void *)(*heap));
    func_02016020((void *)p->cam, 0);
    func_02015BF0((void *)p->cam);
    func_02014CB8((struct Sub02014CB8Obj *)p->cam, func_0202D060());
    p->mem = func_02030734(*heap, func_02030CB0(4), 0, data_021C8E64, 0xa53);
    p->heap3d = func_02030CBC(4, p->mem);
    func_02014CEC((u8 *)p->cam, (u32)p->heap3d);
}


/*
 * Releases the file and the two allocations held in the 0x10-byte records.
 */
void func_021C4FDC(int unused, T *p)
{
    func_02014CD4((struct Sub02014CB8Obj *)p[0].c);
    func_02014BA8((u8 *)p[0].c);
    func_02030DA4(p[0x12].a);
    func_020307B0((void *)p[0x11].d);
}


u32 ov208_func_021C5000(void *sys, u32 species, u32 gender, u32 side, u32 form, u32 shiny,
                        u32 personality, u32 extra)
{
    Vec_021C5000 scale;
    struct Ov208MonArc arc;
    u32 obj;

    scale = data_021C8804;
    if (species == 0x147)
        func_020172AC((int)sys, extra);
    func_02017168(species, gender, side, form, shiny, (struct Stats *)(&arc), personality);
    obj = (u32)func_020159C8(sys, 0, 0, 0, (const struct Sub150 *)(&arc));
    func_02015FF0((char *)obj, 1);
    func_02015E04((void *)obj);
    func_02015CAC((void *)obj, (u32 *)(&scale));
    ov208_func_021C5090(obj);
    return obj;
}


/*
 * BLOCKED.  MATCH: the call at +0x08 targets 02015EA0, an ARM address with no label and no pool witness outside the compared range, so the site stays wildcarded.
 */
void func_021C5078(int a, int b)
{
    func_02015EA0((void *)b);
    func_02015BA4((void *)a, (void *)b);
}


void ov208_func_021C5090(u32 obj)
{
    Vec_021C5090 v;
    float y;

    y = 0.25f * -(float)func_02015F14((void *)obj);
    v.x = FX_F32_TO_FX32(y);
    v.y = 0;
    v.z = 0;
    func_02015C78((void *)obj, (u32 *)(&v));
}


void ov208_func_021C50F8(u32 obj, Vec_021C50F8 *out)
{
    Vec_021C50F8 v;

    func_02015C30((void *)obj, (u32 *)(&v));
    out->x = v.x + data_021C8E40.ofs.x;
    out->y = v.y + data_021C8E40.ofs.y;
    out->z = v.z + data_021C8E40.ofs.z;
}
