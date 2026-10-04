/*
 * function: func_021AEFA4
 * address:  0x021AEFA4
 * packet:   pkt_ov021_021AEFA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

struct Ctx;
struct SoundSys;
extern void *func_020120F4(const struct Ctx *p);
struct BigObj;
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);

int func_021AEFA4(u32 *a, u32 *st)
{
    u32 r = func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx *)(*a)));

    switch (*st) {
    case 0:
        func_02028A58((struct SoundSys *)r, 0x7f, 0);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
