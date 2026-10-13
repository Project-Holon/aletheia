/*
 * function: func_021BCF7C
 * address: 0x021BCF7C
 * packet: pkt_ov110_021BCF7C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021BCFBA.
 *
 * symbols:
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Obj;
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
void func_021BCF7C(u8 *p, int n, int v) {
    int i;
    void **a = (void **)(p + 0x64);
    if (a[n]) {
        for (i = 0; i < 3; i++) {
            if (*(void **)(p + 0x64 + i * 4)) APP_TASKMENU_WIN_SetActive(*(void **)(p + 0x64 + i * 4), 0);
        }
        APP_TASKMENU_WIN_SetActive(a[n], v);
    }
}
