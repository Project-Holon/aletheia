/*
 * function: func_021FC20C
 * address: 0x021FC20C
 * packet: pkt_ov094_021FC20C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_020113B4 0x020113B4 thumb
 *   func_02048F60 0x02048F60 arm
 */
typedef unsigned short u16;
typedef struct {
    int pad0;
    int f4;
    char pad1[0xdc - 8];
    int fdc;
    int fe0;
    int a0[16];
    int a1[16];
    int a2[16];
    int a3[16];
    int f1e4;
    int *f1e8;
    char pad2[0x238 - 0x1ec];
    u16 h238;
    char pad3[2];
    int f23c;
    char pad4[0x260 - 0x240];
    int f260;
} State;
struct Cursor;
extern unsigned int func_0201134C(struct Cursor *p);
struct Ring;
extern void func_020113B4(struct Ring *r, unsigned int v);
typedef unsigned int   u32;
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);

int func_021FC20C(struct Ring *a, State *s)
{
    int n = func_0201134C((struct Cursor *)a);
    int v = func_0201134C((struct Cursor *)a);
    int w = func_0201134C((struct Cursor *)a);
    int *p;

    s->a0[s->f260] = s->fdc;
    s->a1[s->f260] = s->fe0;
    s->a2[s->f260] = (int)s->f1e8;
    s->a3[s->f260] = s->f4;
    if (v != 14) s->fdc = v;
    if (w != 16) s->fe0 = w;
    s->f4 = 0;
    p = func_02048F60(0x43, n - 0x231, (u16)((s->h238 & 0x7fff) | 0x8000));
    s->f1e8 = p;
    func_020113B4(a, (unsigned int)((char *)p + p[1]));
    s->f260++;
    return s->f23c;
}
