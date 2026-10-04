/*
 * function: func_02159E8C
 * address:  0x02159E8C
 * packet:   pkt_ov010_02159E8C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0202E83C  0x0202E83C  thumb
 *   func_0215843C  0x0215843C  thumb  ov010
 *   func_020143CC  0x020143CC  thumb
 *   d_02170FB0  0x02170FB0  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ent {
    u16 f00;
    u16 f02;
    u16 f04;
} Ent;

struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern int func_0202E83C(void *a0);
extern int func_0215843C(void *p);
extern u32 func_020143CC(u32 a, u32 b);
extern Ent d_02170FB0[];

void func_02159E8C(u8 *out, int obj)
{
    int a = func_0201296C(func_020120F4((const struct Ctx *)obj));
    int b = func_02012138((const struct Ctx *)obj);
    int c = func_0202E83C((void *)obj);
    int i;
    out[0] = c;
    out[1] = (func_0215843C((void *)b) != 0x15);
    out[2] = (out[1] == 0) ? 0 : c + 1;
    for (i = 0; i < 10; i++) {
        Ent *e = &d_02170FB0[i];
        u16 *p = (u16 *)func_020143CC(a, e->f02);
        if (*p == e->f04)
            out[3 + i] = 1;
        else
            out[3 + i] = 0;
    }
}
