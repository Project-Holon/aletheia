/*
 * function: func_021F92F4
 * address: 0x021F92F4
 * packet: pkt_ov186_021F92F4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021FE768 0x021FE768 thumb ov186
 *   func_021FEE00 0x021FEE00 thumb ov186
 *   func_021F9A80 0x021F9A80 thumb ov186
 *   func_021FC4C8 0x021FC4C8 thumb ov186
 *   func_021FF52C 0x021FF52C thumb ov186
 *   func_021F9B98 0x021F9B98 thumb ov186
 */
typedef signed int     s32;
typedef unsigned int   u32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
typedef struct {int x[3];} S;
extern void func_021FE768(S *);
extern void func_021FEE00(int);
extern void func_021F9A80(int);
extern void func_021FC4C8(char *);
extern void func_021FF52C(int);
extern int func_021F9B98(int);
int func_021F92F4(int sys,int *state,int unused,int *p)
{
    switch(*state) {
    case 0: *state=1; break;
    case 1: func_0204E720(3,16,0,0); *state=2; break;
    case 2: if(!func_0204E804()) *state=3; break;
    case 3:
        func_021FE768((S *)p[3]);
        func_021FEE00(p[4]);
        func_021F9A80(p[2]);
        func_021FC4C8((char *)p[0]);
        if(p[5]) func_021FF52C(p[5]);
        if(func_021F9B98(p[2])) *state=4;
        break;
    case 4: func_0204E720(3,0,16,0); *state=5; break;
    case 5: if(!func_0204E804()) *state=6; break;
    case 6: return 1;
    }
    return 0;
}
