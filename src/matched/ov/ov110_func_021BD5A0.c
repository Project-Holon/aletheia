/*
 * function: PMS_INPUT_ProcExit
 * address: 0x021BD5A0
 * packet: pkt_ov110_021BD5A0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_Destroy 0x021BD764 thumb ov110
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void PMS_INPUT_Destroy(u8 *,void *);
extern void GFL_HEAP_DeleteChecked(u32);
extern void func_02034A5C(int);
extern char ov067_id[];
int PMS_INPUT_ProcExit(void *a,int b,int c,u8 *p)
{
    PMS_INPUT_Destroy(p,a);
    GFL_HEAP_DeleteChecked(41);
    GFL_HEAP_DeleteChecked(42);
    func_02034A5C((int)ov067_id);
    return 1;
}
