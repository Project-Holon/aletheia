/*
 * function: NAMEIN_SETUP_MainHostProc
 * address:  0x0216C8CC
 * packet:   pkt_ov010_0216C8CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 *
 * blockers: d_021F03C4 and d_021EFDAC data pointers outside ov010 window; no witness
 * (tried ov006/008/011/187/199/ov010 hints)
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 *
 * symbols:
 *   PROCSYS_Main  0x02031330  arm
 *   func_02034AC4  0x02034AC4  arm
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_StartTimingSync  0x0203D594  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   GFL_NET_CheckTimingSync  0x0203D5A0  arm
 *   PROCSYS_Push  0x02031348  arm
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   id_0000005D    0x0000005D  data  a1
 *   d_021F03C4     0x021F03C4  data  a4 ov093
 *   d_021EFDAC     0x021EFDAC  data  a4 ov026
 */

typedef signed int     s32;
typedef unsigned int   u32;
struct Entry;
extern unsigned int PROCSYS_Main(void *p);
extern int func_02034AC4(s32 handle);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_StartTimingSync(int, int);
extern u32 func_0200FB24(void);
extern int GFL_NET_CheckTimingSync(int, int);
extern void PROCSYS_Push(int, int, char *, int);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern void func_02034A5C(s32 handle);
extern char id_0000005D[];
extern char d_021F03C4[];
extern char d_021EFDAC[];

int NAMEIN_SETUP_MainHostProc(int a, int *st, int *o, int *x)
{
    int r = PROCSYS_Main((void *)x[0]);
    switch (*st) {
    case 0:
        func_02034AC4((s32)id_0000005D);
        GFL_NET_COMMAND_AddCommandTable(0x100, (u32)d_021F03C4, 9, 0);
        GFL_NET_StartTimingSync((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xc8);
        *st = 1;
        break;
    case 1:
        if (func_0200FB24() != 0) {
            *st = 4;
            break;
        }
        if (GFL_NET_CheckTimingSync((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xc8) == 0)
            break;
        *st = 2;
        break;
    case 2:
        PROCSYS_Push(x[0], ~0, d_021EFDAC, o[1]);
        *st = 3;
        break;
    case 3:
        if (r == 1)
            break;
        *st = 4;
        break;
    case 4:
        GFL_NET_COMMAND_DeleteCommandTable(0x100);
        func_02034A5C((s32)id_0000005D);
        *st = 5;
        break;
    case 5:
        return 1;
    }
    return 0;
}
