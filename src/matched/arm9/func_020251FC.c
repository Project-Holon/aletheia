/*
 * function: func_020251FC
 * address:  0x020251FC
 * packet:   pkt_020251FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4       0x020490F4  arm
 *   func_0203FA08       0x0203FA08  arm
 *   func_02049B68       0x02049B68  arm
 *   func_02049658       0x02049658  arm
 *   ENV_SetResourceSet  0x02049238  arm
 *   func_02041300       0x02041300  arm
 *   func_020409B4       0x020409B4  arm
 *   gSysState           0x0214693C  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sys {
    u32 field_0;
    u16 field_4;
    u16 field_6;
    u32 field_8;
    u32 field_C;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u8  field_1C;
    u8  field_1D;
    u8  field_1E;
    u8  field_1F;
};

extern struct Sys *gSysState;

extern void *func_020490F4(u32 a, u32 b);
extern u32   func_0203FA08(u32 a, u32 b, u32 c);
extern void  func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void  func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void  ENV_SetResourceSet(void *a);
extern void  func_02041300(u32 a, u16 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void  func_020409B4(u32 a);

void func_020251FC(u32 a, u32 b, u32 c)
{
    void *env;
    u32 sel = 0;

    if (a > 3) {
        sel = 4;
    }

    env = func_020490F4(0x32, c);
    gSysState->field_0 = func_0203FA08(a, 1 << 12, 1);
    func_02049B68(env, 0, sel, b << 5, 0x20, c);
    func_02049658(env, 1, a, gSysState->field_0, 0, 0, c);
    ENV_SetResourceSet(env);
    func_02041300(a, (u16)(gSysState->field_0 + 0xf), 0, 0, 0x20, 1, b);
    func_02041300(a, (u16)(gSysState->field_0 + 0x1f), 0, 1, 0x20, 1, b);
    func_020409B4(a);
}
