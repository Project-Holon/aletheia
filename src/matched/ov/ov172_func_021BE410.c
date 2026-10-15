/*
 * function: COMM_TVT_SYS_ProcExit
 * address: 0x021BE410
 * packet: pkt_ov172_021BE410
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CTVT_CALL_WorkDelete 0x021BD3B8 thumb ov172
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm  arm9
 */
typedef unsigned int u32;
typedef unsigned char  u8;
extern void CTVT_CALL_WorkDelete(u8 *p);
extern u32 func_020307B0(void *p);
struct Proc;
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int h);
int COMM_TVT_SYS_ProcExit(void *a, void *b, int c, u32 *p)
{
    CTVT_CALL_WorkDelete((u8 *)p);
    if (c == 0) {
        func_020307B0((void *)p[0x7e]);
    }
    func_020315D4(a);
    GFL_HEAP_DeleteChecked(0x6d);
    return 1;
}
