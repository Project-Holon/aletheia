/*
 * function: func_021D49F4
 * address:  0x021D49F4
 * packet:   pkt_ov117_021D49F4
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02015FBC  0x02015FBC  thumb
 *   func_02015EB0  0x02015EB0  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_02015E04  0x02015E04  thumb
 *   func_02015CAC  0x02015CAC  thumb
 *   func_02015F50  0x02015F50  thumb
 *
 * The call to 0x02015FBC (arm9 byte insert at +0x140) attests through
 * src/matched/func_02015FBC.c, seeded in layout/function_starts.txt.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

struct McssFade;
extern void func_02015FBC(char *p, int v);
extern void func_02015EB0(void *);
extern void func_02015C48(void *, Vec *);
extern void func_02015E04(void *);
extern void func_02015CAC(void *, void *);
extern void func_02015F50(struct McssFade *w, u8 cur, u8 target, s32 step, u32 e);

void func_021D49F4(void *obj, void *p)
{
    Vec v;
    func_02015FBC(obj, 0x1f);
    func_02015EB0(obj);
    v.x = 0;
    v.y = -0x17000;
    v.z = 0xa000;
    func_02015C48(obj, &v);
    func_02015E04(obj);
    func_02015CAC(obj, (char *)*(void **)((char *)p + 0xc) + 0x48);
    func_02015F50(obj, 0x10, 0x10, 0, 0x7fff);
}
