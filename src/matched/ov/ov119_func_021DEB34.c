/*
 * function: func_021DEB34
 * address: 0x021DEB34
 * packet: pkt_ov119_021DEB34
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD140 0x021DD140 thumb ov119
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035C60 0x02035C60 arm
 *   func_020355C4 0x020355C4 arm
 *   func_021E68F4 0x021E68F4 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DEA24 0x021DEA24 thumb ov119
 */
extern int func_021DD140(void *);
extern int func_021E12AC(void *);
extern int func_020362DC(void);
extern void func_020355D8(int);
extern int func_02035C60(void);
extern int func_020355C4(void);
extern void func_021E68F4(void *,int);
extern void func_021E1098(void *);
extern void func_021D8980(void *);
extern void func_021D8E84(void *,int);
extern void func_021DEA24(void *);
void func_021DEB34(void *p)
{
    int v;
    if(func_021DD140(p) && func_021E12AC(p)) {
        v=func_020362DC();
        if(v) func_020355D8(0);
        if(v==0) {
            v=func_02035C60();
            if(v) func_020355D8(1);
            if(v==0) return;
        }
        if(func_020355C4()) func_021E68F4(p,-1);
        else func_021E68F4(p,0);
        func_021E1098(p);
        func_021D8980(p);
        func_021D8E84(p,(int)func_021DEA24);
    }
}
