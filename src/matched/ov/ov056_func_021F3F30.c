/*
 * function: func_021F3F30
 * address:  0x021F3F30
 * packet:   pkt_ov056_021F3F30
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_020143CC  0x020143CC  thumb
 *   func_02028A7C  0x02028A7C  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 *f0;
    u16 f4;
    u32 f8;
    int fc;
} S3F30;

struct BigObj;
struct Ctx;
struct SoundSys2;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
struct BigObj;
extern u32 func_02012A30(const struct BigObj *p);
extern u32 func_020143CC(u32 a, u32 b);
extern void func_02028A7C(struct SoundSys2 *s, u32 id);

void func_021F3F30(int a, int b, S3F30 *c)
{
    int r5;

    r5 = (int)func_020120F4(func_02188C80((void *)b));
    c->f8 = func_0201296C((const struct BigObj *)r5);
    c->fc = func_02012A30((const struct BigObj *)r5);
    c->f0 = (u16 *)func_020143CC(c->f8, 0x4001);
    if (*c->f0 == 0) {
        func_02028A7C((struct SoundSys2 *)c->fc, 0x756);
        c->f4 = 0;
        return;
    }
    c->f4 = 1;
}
