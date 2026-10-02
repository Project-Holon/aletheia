/*
 * function: func_021F6F04
 * address: 0x021F6F04
 * packet: pkt_ov112_021F6F04
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: trailing zero halfword at 021F6F12 is alignment padding.
 */
typedef struct {int x,y,z;} Vec;
void func_021F6F04(void *ctx,char *p,Vec *out)
{
    out->x=*(int *)(p+8);
    out->y=*(int *)(p+12);
    out->z=*(int *)(p+16);
}
