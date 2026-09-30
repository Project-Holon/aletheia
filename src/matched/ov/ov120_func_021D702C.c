/*
 * function: func_021D702C
 * address: 0x021D702C
 * packet: pkt_ov120_021D702C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pass the named loaded state to out instead of rematerializing 1 or 2.
 * symbols:
 *   func_021D71E8 0x021D71E8 thumb ov120
 */
typedef unsigned char u8;
extern void func_021D71E8(u8 *, int, int);
int func_021D702C(u8 *p, int *out)
{
    int i;
    int state;
    state=*(int *)(p+0x108);
    if (state==2) {
        *(int *)(p+0x104)+=8;
        if (*(int *)(p+0x10c)==*(int *)(p+0x104)) {
            *out=state;
            *(int *)(p+0x108)=0;
            *(int *)(p+0x104)-=48;
        }
        for (i=0;i<6;i++) func_021D71E8(p,i,-8);
        *(int *)(p+0x100)=1;
    }
    state=*(int *)(p+0x108);
    if (state==1) {
        *(int *)(p+0x104)-=8;
        if (*(int *)(p+0x10c)==*(int *)(p+0x104)) {
            *out=state;
            *(int *)(p+0x108)=0;
            *(int *)(p+0x104)+=48;
        }
        for (i=0;i<6;i++) func_021D71E8(p,i,8);
        *(int *)(p+0x100)=1;
    }
    return *(int *)(p+0x108);
}
