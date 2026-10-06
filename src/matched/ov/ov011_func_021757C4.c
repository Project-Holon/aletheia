/*
 * function: func_021757C4
 * address:  0x021757C4
 * packet:   pkt_ov011_021757C4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   func_02175B14  0x02175B14  thumb  ov011
 *   func_02175894  0x02175894  thumb  ov011
 *   func_02026478  0x02026478  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02175D34  0x02175D34  thumb  ov011
 *   func_02176158  0x02176158  thumb  ov011
 *   func_02176194  0x02176194  thumb  ov011
 *   func_02175A34  0x02175A34  thumb  ov011
 *   func_02175AE8  0x02175AE8  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0xA8];
    u16 hA8;
    u16 hAA;
    u8 padAC[0xD8 - 0xAC];
    u8 bD8;
    u8 padD9[0xE3 - 0xD9];
    u8 bE3;
    u8 padE4[0x19C - 0xE4];
    u8 b19C;
    u8 pad19D[0x1A5 - 0x19D];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 1;
    u8 f3 : 1;
    u8 f4 : 1;
    u8 f5 : 3;
} Work;

typedef struct {
    u32 w0;
    u32 w4;
} Ctx;

extern u32 func_0203D378(void);
extern int func_02175B14(u8 *p);
extern int func_02175894(u8 *p);
struct BigObj;
extern u32 func_02026478(void *obj);
extern u8 func_02012B58(const struct BigObj *p);
extern void func_02175D34(Ctx *c, Work *w, int a);
extern void func_02176158(int a, u8 *p);
extern void func_02176194(Ctx *c, Work *w);
extern void func_02175A34(void *a, u8 *b);
extern void func_02175AE8(int ctx, u8 *p);

void func_021757C4(Ctx *c, Work *w)
{
    int x;

    if (func_0203D378() == 1 && func_02175B14((u8 *)w) == 1) {
        if (w->bD8 == 4) {
            if (w->hA8 != 0) {
                if (w->b19C == 0 && func_02175894((u8 *)w) > w->hA8) {
                    w->b19C = 1;
                }
            } else if (w->f1 == 1 && func_02175894((u8 *)w) > w->hAA) {
                x = func_02026478((void *)c->w4);
                if (w->bE3 == 0) {
                    func_02175D34(c, w, func_02012B58((const struct BigObj *)x));
                }
            }
        } else if (w->f1 == 1 && func_02175894((u8 *)w) > w->hAA) {
            w->f4 = 1;
        }
    }
    func_02176158((int)c, (u8 *)w);
    func_02176194(c, w);
    func_02175A34(c, (u8 *)w);
    func_02175AE8((int)c, (u8 *)w);
}
