/*
 * function: func_021B78E0
 * address: 0x021B78E0
 * packet: pkt_ov106_021B78E0
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B84D0 0x021B84D0 thumb ov106
 *   func_021B78D0 0x021B78D0 thumb ov106
 *   func_021B7BC4 0x021B7BC4 thumb ov106
 *   func_021B7984 0x021B7984 thumb ov106
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int     s32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern int func_021B84D0(u8 *);
extern void func_021B78D0(u8 *,u32);
extern void func_021B7BC4(u8 *a, u32 unused, u8 *p);
extern void func_021B7984(u8 *a, u32 unused, u8 *p);
void func_021B78E0(u8 *a, int *state, u8 *p)
{
    switch (*state) {
    case 0: func_0204E720(3,16,0,0); *state = 1; break;
    case 1: if (!func_0204E804()) *state = 2; break;
    case 2:
        if (func_021B84D0(p+0x38) != 65535) func_021B78D0(p+0x28,(u32)func_021B7BC4);
        else func_021B78D0(a,(u32)func_021B7984);
        break;
    }
}
