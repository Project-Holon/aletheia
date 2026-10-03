/*
 * function: func_021BCB8C
 * address: 0x021BCB8C
 * packet: pkt_ov099_021BCB8C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two bytes of alignment padding follow at 0x021BCBAE.
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BBA8 0x0200BBA8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 */
typedef unsigned int u32;
extern void *func_02012EBC(void *);
extern void *func_0200BAC8(void *);
extern u32 func_0200BBA8(void *);
extern int func_0200BAF4(void *, u32);
int func_021BCB8C(void *p)
{
    void *obj = func_0200BAC8(func_02012EBC(p));
    if (func_0200BBA8(obj) == 0) return 0;
    return func_0200BAF4(obj, 0x21);
}
