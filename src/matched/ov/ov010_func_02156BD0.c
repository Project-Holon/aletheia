/*
 * function: func_02156BD0
 * address:  0x02156BD0
 * packet:   pkt_ov010_02156BD0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02030734  0x02030734  arm
 *   d_02172730  0x02172730  data
 *   ov133_id  0x00000085  data
 */

typedef unsigned int u32;

typedef struct Obj {
    u32 *f00;
    u32 pad[2];
    u32 *f0c;
} Obj;

extern void func_02034AC4(u32);
extern char ov133_id[];
extern void func_0203064C(int, int, int);
extern Obj *func_0203159C(void *, int, int);
extern u32 *func_02030734(int, int, int, const char *, int);
extern const char d_02172730[];

int func_02156BD0(void *a, u32 *out, u32 *src)
{
    Obj *o;
    *out = 0;
    func_02034AC4((u32)ov133_id);
    func_0203064C(1, 0x2d, 1 << 18);
    o = func_0203159C(a, 0x10, 0x2d);
    o->f00 = func_02030734(0x2d, 0xc, 0, d_02172730, 0x4e);
    o->f0c = src;
    o->f00[0] = src[0];
    o->f00[1] = src[1];
    o->f00[2] = src[2];
    return 1;
}
