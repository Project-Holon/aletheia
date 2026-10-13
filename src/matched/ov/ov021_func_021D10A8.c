/*
 * function: func_021D10A8
 * address:  0x021D10A8
 * packet:   pkt_ov021_021D10A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   SAVE_CONTROL_LoadExtraSaveWithBuffer  0x020072CC  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200E684  0x0200E684  thumb
 *   func_0200E588  0x0200E588  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAME_DATA_PartSaveStart  0x02012E4C  thumb
 *   GAME_DATA_PartSaveMain  0x02012E7C  thumb
 *   func_0200734C  0x0200734C  thumb
 *   func_020307B0  0x020307B0  arm
 *   FIELD_SAVEANIME_Stop  0x021D11D8  thumb  ov021
 *   FIELD_SAVEANIME_Delete  0x021D1194  thumb  ov021
 *   d_021DE674     0x021DE674  data    ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Big;
struct Ctx;
struct Sub020073D8Ctrl;
extern void *func_020120F4(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void SAVE_CONTROL_LoadExtraSaveWithBuffer(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern void func_0200E684(void *obj);
extern u32 func_0200E588(void);
extern void MI_CpuFill8(u32 p, int v, u32 n);
extern void GAME_DATA_PartSaveStart(u8 *a, u32 b);
extern int GAME_DATA_PartSaveMain(char *p, int a1);
struct Sub02007324Ctrl;
extern void func_0200734C(struct Sub02007324Ctrl *a, u32 b);
extern u32 func_020307B0(void *p);
extern void FIELD_SAVEANIME_Stop(u32 *p);
extern int FIELD_SAVEANIME_Delete(void *a);
extern char d_021DE674[];

int func_021D10A8(u32 a, u32 *b, u32 *c)
{
    u32 s4 = (u32)func_020120F4((const struct Ctx *)c[0]);
    u32 r6 = (u32)GAME_DATA_GetSaveControl((struct Big *)s4);
    u32 x;

    switch (b[0]) {
    case 0:
        c[1] = (u32)func_02030734(0x8004, 0x1000, 0, d_021DE674, 0x34C);
        SAVE_CONTROL_LoadExtraSaveWithBuffer(r6, 5, 0x8004, c[1], 0x1000);
        x = (u32)func_020073D8((struct Sub020073D8Ctrl *)r6, 5, 0);
        if (c[2] == 1) {
            func_0200E684((void *)x);
        } else {
            MI_CpuFill8(x, 0, func_0200E588());
        }
        GAME_DATA_PartSaveStart((u8 *)s4, 5);
        b[0] = b[0] + 1;
        break;
    case 1:
        if (GAME_DATA_PartSaveMain((char *)s4, 5) == 2) {
            func_0200734C((struct Sub02007324Ctrl *)r6, 5);
            func_020307B0((void *)c[1]);
            FIELD_SAVEANIME_Stop((u32 *)c[3]);
            FIELD_SAVEANIME_Delete((void *)c[3]);
            return 1;
        }
        break;
    }
    return 0;
}
