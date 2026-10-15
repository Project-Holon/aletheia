/*
 * function: WIFI_BSUBWAY_GRAPHIC_SetupBgAnim
 * address: 0x021D7D0C
 * packet: pkt_ov116_021D7D0C
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: 2026-10-05 (wD9r lane92): the heap parameter is a signed 16-bit value (`short heap`). With u32
 *   heap the last call hoisted the heap reload above `str r6,[sp]` (10 bytes, waves D3 to D9r). The
 *   image truncates heap only for func_02049F78 (u16 cast); the other callees take it unchanged.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049F78 0x02049F78 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020056A0 0x020056A0 thumb
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207D63C 0x0207D63C arm
 *   BG_SYS_CreateRun 0x0203FA08 arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   PALANM_BlendColors 0x02021F64 thumb
 *   WIFI_BSUBWAY_GRAPHIC_StepBgAnim 0x021D7F54 thumb ov116
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32, u32);
extern void func_02049B68(void *, int, int, int, int, u32);
extern u32 func_02049740(void *, int, int, int, int, u32);
extern void func_02049990(void *, int, int, int, u16, int, int, u32);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void ARC_TOOL_DeleteHandle(void *);
extern int func_02049B40(int, int, int, int, int, u32);
extern void MI_CpuFill8(void *, int, u32);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 func_020307B0(void *p);
extern void *func_020056A0(void *, void *, int);
extern void DWCi_ScreenDC_FlushRange(void *, u32);
extern void func_0207D63C(void *, int, int, int, int);
extern u32 BG_SYS_CreateRun(u32 layer, u32 size, u32 top);
extern void *BMP_MENUWORK_LoadFrameGfx(void *a0, u32 a1, u32 a2, u32 a3);
extern void PALANM_BlendColors(void *, void *, u16, u8, u16);
extern void WIFI_BSUBWAY_GRAPHIC_StepBgAnim(void *unused, u8 *p);
struct Arc { int f0; int f4; int f8; u8 *fC; };
void WIFI_BSUBWAY_GRAPHIC_SetupBgAnim(u8 *p, short heap) {
    struct Arc *res;
    u8 *pa;
    u8 *pb;
    void *arc;
    int done;
    int t;
    int j;
    int k;
    u8 *q;
    void *blk;
    int m;
    int n;
    int sh;
    u8 *a;
    u8 *b;
    arc = func_020490F4(0x91, heap);
    j = 0;
    func_02049B68(arc, 3, 4, 0, j, heap);
    func_02049990(arc, 6, 4, 0, (u16)func_02049740(arc, 4, 4, 0, j, heap), j, j, heap);
    func_02049B68(arc, 3, 0, 0, j, heap);
    func_02049990(arc, 5, 0, 0, (u16)func_02049740(arc, 4, 0, 0, j, heap), j, j, heap);
    func_02049990(arc, 7, 3, 0, (u16)func_02049740(arc, 4, 3, 0, j, heap), j, j, heap);
    MI_CpuFill8(p + 0xc, 0, 0x970);
    blk = func_02049F78(arc, 2, (u32)(&res), (u16)heap);
    MI_CpuCopy8(res->fC, p + 0x14, 0x1e0);
    MI_CpuCopy8(res->fC, p + 0x1f4, 0x1e0);
    func_020307B0(blk);
    k = 0;
    pa = p + 0x1f4;
    pb = p;
    pb += 0x14;
    for (; k < 15; k++) {
        n = k + 1;
        if (n >= 15) n -= 15;
        t = 0;
        done = 0;
        q = p + n * 32;
        for (;;) {
            a = pb + k * 32;
            sh = t >> 8;
            b = pa + j * 32;
            for (m = 4; m < 11; m++) {
                PALANM_BlendColors(a + m * 2, b + m * 2, 1, (u8)sh, *(u16 *)(q + 0x14 + m * 2));
            }
            j++;
            if (done == 1) break;
            t += 0x600;
            if (t >= 0x1000) { t = 0x1000; done = 1; }
        }
    }
    DWCi_ScreenDC_FlushRange(p + 0x1f4, 0x780);
    *(u32 *)(p + 0x10) = 1;
    *(void **)(p + 0xc) = func_020056A0((void *)WIFI_BSUBWAY_GRAPHIC_StepBgAnim, p + 0xc, 0x14);
    func_0207D63C((void *)0x04000050, 1, 8, 8, 0x10);
    p[0x978] = 0;
    ARC_TOOL_DeleteHandle(arc);
    BG_SYS_CreateRun(1, 0x20, 0);
    BG_SYS_CreateRun(2, 0x20, 0);
    *(void **)(p + 0x984) = BMP_MENUWORK_LoadFrameGfx((void *)1, 0xd, 0, heap);
    *(void **)(p + 0x988) = BMP_MENUWORK_LoadFrameGfx((void *)2, 0xd, 0, heap);
    func_02049B40(0x17, 5, 0, 0x180, 0x20, heap);
}
