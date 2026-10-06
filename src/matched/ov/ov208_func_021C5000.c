/*
 * function: ov208_func_021C5000
 * address:  0x021C5000
 * packet:   pkt_ov208_021C5000
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020172AC  0x020172AC  thumb
 *   func_02017168  0x02017168  thumb
 *   func_020159C8  0x020159C8  thumb
 *   func_02015FF0  0x02015FF0  thumb
 *   func_02015E04  0x02015E04  thumb
 *   func_02015CAC  0x02015CAC  thumb
 *   ov208_func_021C5090  0x021C5090  thumb
 *   data_021C8804  0x021C8804  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec;

struct Ov208MonArc {
    u8 d[0x24];
};

struct Obj;
struct Rec;
struct Sub150;
extern void func_020172AC(int a0, int a1);
struct Stats;
extern void func_02017168(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct Stats *out, u32 a6);
extern struct Rec *func_020159C8(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void func_02015FF0(char *p, int v);
extern void func_02015E04(void *p);
extern void func_02015CAC(void *p, u32 *src);
extern void ov208_func_021C5090(u32 obj);
extern const Vec data_021C8804;

u32 ov208_func_021C5000(void *sys, u32 species, u32 gender, u32 side, u32 form, u32 shiny,
                        u32 personality, u32 extra)
{
    Vec scale;
    struct Ov208MonArc arc;
    u32 obj;

    scale = data_021C8804;
    if (species == 0x147)
        func_020172AC((int)sys, extra);
    func_02017168(species, gender, side, form, shiny, (struct Stats *)(&arc), personality);
    obj = (u32)func_020159C8(sys, 0, 0, 0, (const struct Sub150 *)(&arc));
    func_02015FF0((char *)obj, 1);
    func_02015E04((void *)obj);
    func_02015CAC((void *)obj, (u32 *)(&scale));
    ov208_func_021C5090(obj);
    return obj;
}
