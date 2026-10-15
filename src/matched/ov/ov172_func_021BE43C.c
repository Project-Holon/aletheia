/*
 * function: COMM_TVT_SYS_ProcMain
 * address: 0x021BE43C
 * packet: pkt_ov172_021BE43C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_ERR_RequestScreen 0x0200FB38 thumb
 *   CTVT_CALL_WorkMain 0x021BD43C thumb ov172
 */
typedef unsigned int u32;
extern u32 func_0200FB24(void);
extern void GFL_NET_ERR_RequestScreen(void);
extern int CTVT_CALL_WorkMain(char *ctx); /* ov172 definition: src/pending/ov/ov172_func_021BD43C.c (one argument; r1 is overwritten before use) */
int COMM_TVT_SYS_ProcMain(void *a, void *b, void *c, u32 *p)
{
    if (func_0200FB24() != 0 && p[5] == 0) {
        GFL_NET_ERR_RequestScreen();
        p[5] = 1;
    }
    if (CTVT_CALL_WorkMain((char *)p) == 1) {
        return 1;
    }
    return 0;
}
