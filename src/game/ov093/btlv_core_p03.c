/*
 * file:     btlv_core_p03.c
 * unit:     yes
 * function: func_021E8C50, func_021E8C9C
 * address:  0x021E8C50
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int u32;

union U {
    struct { u32 kind : 3; u32 f : 6; u32 rest : 23; } a;
};

void func_021E8C50(union U *p, u32 v);
void func_021E8C9C(union U *p, int v);

void func_021E8C50(union U *p, u32 v)
{
    if (p->a.kind == 2 && p->a.f < 8) p->a.f = p->a.f + v;
    if (p->a.kind == 4 && p->a.f < 8) p->a.f = p->a.f + v;
}

void func_021E8C9C(union U *p, int v)
{
    if (p->a.kind == 2 && p->a.f < 8) p->a.f = v;
    if (p->a.kind == 4 && p->a.f < 8) p->a.f = v;
}
