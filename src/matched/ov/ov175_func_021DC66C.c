/*
 * function: func_021DC66C
 * address: 0x021DC66C
 * packet: pkt_ov175_021DC66C
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */
extern void MI_CpuCopy8(const void *,void *,int);
void func_021DC66C(const char *p,void *out)
{
    MI_CpuCopy8(p+0x1230,out,0x160);
}
