/*
 * function: WIFI_BSUBWAY_Delete
 * address: 0x021D6918
 * packet: pkt_ov116_021D6918
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFI_BSUBWAY_GRAPHIC_DeleteTextParam 0x021D730C thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_Noop 0x021D73D0 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_NoopRetry 0x021D7420 thumb ov116
 *   WIFI_BSUBWAY_StatusDelete 0x021D6B70 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_DeleteWindow 0x021D7C58 thumb ov116
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000072 data
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb  arm9
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb  arm9
 *   GFL_USE_PopBgm  0x02005E9C  thumb  arm9
 */
typedef unsigned char u8;
struct Proc;
extern void WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(u8 *p);
extern void WIFI_BSUBWAY_GRAPHIC_Noop(void *);
extern void WIFI_BSUBWAY_GRAPHIC_NoopRetry(void *);
extern void WIFI_BSUBWAY_StatusDelete(unsigned char *a);
extern void WIFI_BSUBWAY_GRAPHIC_DeleteWindow(u8 *p);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int);
extern void func_02034A5C(int handle);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *);
extern void GFL_USE_FadeInBgmFull(unsigned);
extern u8 ov_id[];
int WIFI_BSUBWAY_Delete(void *p, int a, int b, u8 *q) {
    WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(q);
    WIFI_BSUBWAY_GRAPHIC_Noop(q);
    WIFI_BSUBWAY_GRAPHIC_NoopRetry(q);
    WIFI_BSUBWAY_StatusDelete(q + 0x1610);
    WIFI_BSUBWAY_GRAPHIC_DeleteWindow(q + 4);
    func_020315D4(p);
    GFL_HEAP_DeleteChecked(125);
    func_02034A5C((int)ov_id);
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_FadeInBgmFull(60);
    return 1;
}
