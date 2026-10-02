/*
 * function: func_021DAEF0
 * address: 0x021DAEF0
 * packet: pkt_ov119_021DAEF0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020355D8 0x020355D8 arm
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_02045CAC 0x02045CAC arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAEC8 0x021DAEC8 thumb ov119
 *   func_021DBA80 0x021DBA80 thumb ov119
 */

typedef unsigned int u32;
extern int func_021E12AC(void *),func_021D8A24(void *);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_020355D8(int);
extern void func_021E1098(void *),func_021E1024(void *),func_021E1030(void *);
extern void func_02045CAC(int,int,int),func_021D8E84(void *,int),func_021DAEC8(void *),func_021DBA80(void *);
static inline int poll_a(void) {int r=func_020362DC();if(r)func_020355D8(0);return r;}
static inline int poll_b(void) {int r=func_02035C60();if(r)func_020355D8(1);return r;}
void func_021DAEF0(char *p) {
 if(func_021E12AC(p)) {
  if(poll_a() || poll_b()) {
   func_021E1098(p);
   if(func_021D8A24(p)) {
    func_02045CAC(*(int *)(p+0x720),50,*(int *)(p+0x738));func_021E1024(p);func_021E1030(p);func_021D8E84(p,(int)func_021DAEC8);
   } else func_021D8E84(p,(int)func_021DBA80);
  }
 }
}
