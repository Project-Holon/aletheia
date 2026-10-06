/*
 * function: func_021F0250
 * address:  0x021F0250
 * packet:   pkt_ov031_021F0250
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: 0x021F0288 ldr / 0x021F028E str of 0x04001000 (REG_DB_DISPCNT_SUB read-modify-write); 0x021F0294 strh to 0x04001050 (hardware registers)
 *
 * symbols:
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0204162C  0x0204162C  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02040588  0x02040588  arm
 *   d_021F1050     0x021F1050  data  ov031  a4
 *   d_021F1070     0x021F1070  data  ov031  a4
 *   d_021F1090     0x021F1090  data  ov031  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BgTemplate;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_0204162C(int channel);
extern void *func_02049EF4(void *p, u32 a, u32 b, void **out, u16 d);
extern void func_02082D44(void *src, void *dst, int n);
extern u32 func_020307B0(void *p);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02040588(u32 which, unsigned char enable);

extern const u8 d_021F1050[];
extern const u8 d_021F1070[];
extern const u8 d_021F1090[];

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)

void func_021F0250(void *p, u32 h)
{
    u16 *pal;
    u8 *out;
    void *res;

    func_0203FCA0(5, (const struct BgTemplate *)d_021F1050, 0);
    func_0203FCA0(6, (const struct BgTemplate *)d_021F1070, 0);
    func_0203FCA0(7, (const struct BgTemplate *)d_021F1090, 0);
    func_02082A7C(0, (void *)0x06200000, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    func_02049658((void *)h, 0xF, 7, 0, 0, 0, 0x15);
    func_020498F4((void *)h, 0x11, 7, 0, 0x800, 0, 0x15);
    pal = (u16 *)func_0204162C(6);
    res = func_02049EF4((void *)h, 0x12, 0, (void **)&out, 0x15);
    func_02082D44(out + 0xC, pal, 0x1C0);
    func_020307B0(res);
    func_02049B68((void *)h, 0x10, 4, 0, 0xA0, 0x15);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, 0x15);
    func_02040588(4, 0);
    func_02040588(7, 1);
    func_02040588(6, 1);
    func_02040588(5, 1);
}
