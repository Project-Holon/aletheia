/*
 * function: func_02075A2C
 * address:  0x02075A2C
 * packet:   pkt_02075794
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  MATCH, two unwitnessed sites.  (1) PC24 func_02075968: no
 *           branch anywhere in the image outside 02075A2C..02075A94, so
 *           `label` refuses it - and 0x02075968 is itself only 8 bytes from
 *           EXACT (two BIC destinations), see docs/notes/pkt_02075794.c.txt.
 *           (2) ABS32 g_02150190: the data address is named by exactly one
 *           pool word in the image, this function's own, so `literal` has no
 *           second occurrence either.  The other four sites resolve
 *           (func_02075A94 and func_02075AB8 as `matched`, g_0214EA90 as
 *           `literal x5`).  The body is byte-correct.
 * symbols:
 *   g_02150190  0x02150190  data
 *   g_0214EA90  0x0214EA90  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

extern u8  g_02150190[];
extern u8  g_0214EA90[];

extern void func_02075A94(u8 *o);
extern void func_02075AB8(void *a, u32 v);
extern void func_02075968(u8 *o);

struct Obj {
    u8 pad000[0x118];
    s32 b0:1;
    s32 rest:31;
    u8 pad11C[0x54];
    void (*f170)(u8 *o);
};

void func_02075A2C(struct Obj *o)
{
    u8 *p;

    if (o->b0 == 0) return;
    func_02075A94((u8 *)o);
    o->f170((u8 *)o);
    func_02075AB8(g_02150190, (u32)((u8 *)o));
    p = *(u8 **)(g_0214EA90 + 4);
    if (p != 0) func_02075AB8(p + 0x10e0, (u32)((u8 *)o));
    func_02075968((u8 *)o);
}
