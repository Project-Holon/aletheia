/*
 * function: func_021C1850
 * address: 0x021C1850
 * packet: pkt_ov217_021C1850
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declare base before total, preserve both base stores, guard do-loop.
 * symbols:
 *   func_021C1AD4 0x021C1AD4 thumb ov217
 *   func_021C1AFC 0x021C1AFC thumb ov217
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021C1AD4(u8 *p);
extern int func_021C1AFC(u8 *);
void func_021C1850(u8 *p)
{
    u8 *base;
    u32 total=func_021C1AD4(p);
    int count=p[0x1ac];
    int i=0;
    int remaining;
    if (count>0) {
        base=p;
        base=p+0x1c;
        do {
            u8 *record=base+i*20;
            record[8]=(*(u32 *)(record+4)*100)/total;
            i++;
        } while (i<count);
    }
    remaining=100-func_021C1AFC(p);
    i=0;
    while (remaining>0) {
        p[i*20+0x24]+=1;
        remaining--;
        i=(i+1)%count;
    }
}
