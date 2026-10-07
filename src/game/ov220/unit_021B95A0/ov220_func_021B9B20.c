/*
 * function: func_021B9B20
 * address: 0x021B9B20
 * packet: pkt_ov220_021B9B20
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 66-byte body, then zero alignment at 021B9B62..021B9B64.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
typedef unsigned char u8;
typedef struct {unsigned a,b,c;} Row;
typedef struct {char pad0[24];u8 count;char pad19[3];Row rows[4];void *objects[4];} Context;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(unsigned),func_0204A8D4(unsigned),func_0204ADA4(unsigned);
void func_021B9B20(Context *p)
{
    u8 i;
    for(i=0;i<p->count;i++) {
        func_0204B3B4(p->objects[i]);
        func_0204AFD8(p->rows[i].c);
        func_0204A8D4(p->rows[i].a);
        if(i==0) func_0204ADA4(p->rows[i].b);
    }
}
