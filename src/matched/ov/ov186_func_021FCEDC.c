/*
 * function: func_021FCEDC
 * address: 0x021FCEDC
 * packet: pkt_ov186_021FCEDC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035BA4 0x02035BA4 arm
 *   func_02035CB8 0x02035CB8 arm
 *   d_02200AF0 0x02200AF0 data a4
 */
extern int func_02035BA4(const void *);
extern void func_02035CB8(int *,int *);
extern const char d_02200AF0[];
int func_021FCEDC(char *p)
{
    int x,y;
    int direction=0;
    int delta,absolute;
    if(func_02035BA4(d_02200AF0)!=-1) {
        func_02035CB8(&x,&y);
        if(*(int *)(p+0x84)==0) {*(int *)(p+0x84)=1;*(unsigned short *)(p+0x88)=y;}
        else {
            delta=y-*(unsigned short *)(p+0x88);
            if(delta<0) absolute=-delta;else absolute=delta;
            if(absolute>8) {
                if(delta<0) direction=-1;else direction=1;
                *(unsigned short *)(p+0x88)=y;
            }
        }
    } else if(*(int *)(p+0x84)) *(int *)(p+0x84)=0;
    return direction;
}
