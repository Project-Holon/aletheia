/*
 * function: func_021DDB90
 * address: 0x021DDB90
 * packet: pkt_ov119_021DDB90
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035C60 0x02035C60 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDB64 0x021DDB64 thumb ov119
 */

extern unsigned func_020399A8(void);
extern int func_021E12AC(void *);
extern int func_020362DC(void);
extern void func_020355D8(int);
extern int func_02035C60(void);
extern void func_02045CAC(int,int,int);
extern void func_021E1024(void *);
extern void func_021E1030(void *);
extern void func_021D8E84(void *,int);
extern void func_021DDB64(void *);

void func_021DDB90(unsigned char *p)
{
    int v;func_020399A8();if(func_021E12AC(p)){v=func_020362DC();if(v)func_020355D8(0);if(v==0){v=func_02035C60();if(v)func_020355D8(1);if(v==0)return;}func_02045CAC(*(int *)(p+0x720),0x88,*(int *)(p+0x738));func_021E1024(p);func_021E1030(p);func_021D8E84(p,(int)func_021DDB64);}
}
