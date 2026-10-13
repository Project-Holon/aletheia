/*
 * function: func_02090F18
 * address:  0x02090F18
 * packet:   pkt_02090F18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02153B80     0x02153B80  data
 *   SVC_CpuSet  0x0200421A  thumb
 *   OS_GetLockID  0x02084EB8  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned char g_02153B80[];
extern void SVC_CpuSet(u32 *out, unsigned char *p, u32 v);
extern u16 OS_GetLockID(void);

void func_02090F18(void)
{
    u32 tmp = 0;

    SVC_CpuSet(&tmp, g_02153B80 + 4, 0x05000001);
    *(u16 *)(g_02153B80 + 6) = OS_GetLockID();
}
