/*
 * unit:     yes
 * function: func_021B69B8, func_021B69BC, func_021B69C8, func_021B69D0, func_021B69D4
 * address:  0x021B69B8
 * packet:   pkt_ov067_021B69B8
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Getter, ARM9 tail call, indirect call, and two setters.  0x021B69BC is also
 * resident in ov172, so the packet id is region-qualified.
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 */

int func_021B69B8(void *p)
{
    return *(int *)((char *)p + 0x18);
}

typedef unsigned int   u32;
struct Obj;
void func_021B69BC(void *p, unsigned int v)
{
    void func_0204B3DC(struct Obj *p, u32 v);
    func_0204B3DC(*(void **)p, v);
}

int func_021B69C8(void *p, int a)
{
    return (*(int (**)(void *, int))((char *)p + 0x10))(p, a);
}

void func_021B69D0(void *p, int v)
{
    *(int *)((char *)p + 0x34) = v;
}

void func_021B69D4(void *p, int v)
{
    *(int *)((char *)p + 0x30) = v;
}
