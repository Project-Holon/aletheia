/*
 * function: func_021AC154
 * address:  0x021AC154
 * packet:   pkt_ov021_021AC154
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
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

struct Node;
extern void func_02030EAC(struct Node *n);

void func_021AC154(Obj *o)
{
    if (o != 0) {
        o->exit(o, o->work);
        func_02030EAC(o->fd0);
        o->active = 0;
    }
}
