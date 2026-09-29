/*
 * function: func_021C8F24
 * address:  0x021C8F24
 * packet:   pkt_ov093_021C8F24
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021C8F94  0x021C8F94  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C5B74  0x021C5B74  thumb  ov093
 *   func_021C195C  0x021C195C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021B9934(int a, u8 b);
extern int func_021C8F94(int a, u8 b);
extern int func_021D5B68(void *p);
extern void func_021C5B74(int a, int b, int c, int d);
extern void func_021C195C(int a, int b, int c);

typedef struct {
    u32 w; u8 n; u8 b5; u8 b6; u8 ids[9]; u32 v[4];
} Ent;

typedef struct { int pad0; int pad1; int f8; } P;

int func_021C8F24(P *pp, const Ent *e)
{
    int p = (int)pp;
    int r = 0;
    u32 i;
    int a;

    for (i = 0; i < e->n; i++) {
        if (func_021C8F94(p + 0x1ab8, e->ids[i])) {
            a = func_021B9934(pp->f8, e->ids[i]);
            if (func_021D5B68((void *)a) == 0) {
                func_021C5B74(p, a, e->v[i], !e->b5);
                if (e->b6 == 0)
                    func_021C195C(p, a, 1);
                r = 1;
            }
        }
    }
    return r;
}
