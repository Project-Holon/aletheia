/*
 * function: func_021DA064
 * address: 0x021DA064
 * packet: pkt_ov119_021DA064
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035C60 0x02035C60 arm
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 *   func_021E4E64 0x021E4E64 thumb ov119
 */

extern int func_021E12AC(void *);
extern int func_020362DC(void);
extern void func_020355D8(int);
extern int func_02035C60(void);
extern void func_021E1098(void *);
extern void func_021D8E84(void *,int);
extern void func_021DBE70(void *);
extern void func_021E4E64(int,void *,int);
void func_021DA064(char *p) {
    int v;
    if (func_021E12AC(p)) {
        v=func_020362DC();
        if(v) func_020355D8(0);
        if(!v) {
            v=func_02035C60();
            if(v) func_020355D8(1);
            if(!v) return;
        }
        *(int *)(p+0xF80)=-1;
        *(int *)(p+0xF7C)=-1;
        func_021E1098(p);
        func_021D8E84(p,(int)func_021DBE70);
        *(short *)(p+0x1080)=-1;
        func_021E4E64(*(int *)(p+0x828),p,1);
    }
}
