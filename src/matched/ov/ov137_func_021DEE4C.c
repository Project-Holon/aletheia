/*
 * function: func_021DEE4C
 * address: 0x021DEE4C
 * packet: pkt_ov137_021DEE4C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: unlabelled follower at 021DEED8, filed separately.
 * lever: raw unsigned byte-table address and a named row byte offset restore r6.
 * symbols:
 *   func_021E16C0 0x021E16C0 thumb ov137
 *   func_021E0C08 0x021E0C08 thumb ov137
 *   d_021E1FDC 0x021E1FDC data a2
 */
typedef unsigned short u16;
extern int *func_021E16C0(char *);
extern void func_021E0C08(char *,int,int,int,int,int,int *);
extern const u16 d_021E1FDC[][5];
int func_021DEE4C(char *p)
{
    int *r;
    int value, a, row;
    if (--*(int *)(p+12)>0) return 0;
    *(int *)(p+12)=15;
    r=func_021E16C0(p);
    row=r[5]*10;
    value=*(const u16 *)((unsigned)d_021E1FDC+row+r[4]*2);
    a=*(u16 *)(p+0x7e + r[4]*4);
    *(u16 *)(p+0x60+r[4]*2)=value;
    func_021E0C08(p,a,r[4],r[0],value,r[1],(int *)(p+0x2e0+r[4]*0xb4));
    r[4]++;
    r[4]%=r[5];
    if (++r[0]==r[5]) {
        *(int *)(p+12)=0;
        *(int *)p=18;
    }
    return 0;
}
