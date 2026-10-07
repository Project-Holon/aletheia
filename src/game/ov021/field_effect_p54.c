/*
 * file:     field_effect_p54.c
 * unit:     yes
 * function: func_021AC134, func_021AC140
 * address:  0x021AC134
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
 *   func_021AC178  0x021AC178  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct V3 { int x, y, z; } V3;

typedef struct Obj Obj;

typedef void (*ObjCb)(Obj *o, void *work);

struct Obj {
    u32 active;
    u32 f4;
    u32 f8;
    V3 pos;
    u8 work[0xa4];
    ObjCb init;
    ObjCb exit;
    ObjCb f_c4;
    ObjCb f_c8;
    u32 fcc;
    void *fd0;
};

extern void func_021AC178(u32 v);
void func_021AC134(u32 a, u32 b);
void func_021AC140(Obj *o);


/*
 * Untraced thunk: forwards the second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC134(u32 a, u32 b)
{
    func_021AC178(b);
}


void func_021AC140(Obj *o)
{
    if (o != 0)
        o->init(o, o->work);
}
