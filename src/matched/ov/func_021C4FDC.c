/*
 * function: func_021C4FDC
 * address:  0x021C4FDC
 * packet:   pkt_021C4FDC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Releases the file and the two allocations held in the 0x10-byte records.
 */


typedef unsigned char  u8;
struct Sub02014CB8Obj;
extern void func_02014CD4(struct Sub02014CB8Obj *o);
extern void func_02014BA8(u8 *a0);
extern void func_02030DA4(int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

typedef struct {
    int a;
    int b;
    int c;
    int d;
} T;

void func_021C4FDC(int unused, T *p)
{
    func_02014CD4((struct Sub02014CB8Obj *)p[0].c);
    func_02014BA8((u8 *)p[0].c);
    func_02030DA4(p[0x12].a);
    func_020307B0((void *)p[0x11].d);
}

