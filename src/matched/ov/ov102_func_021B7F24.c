/*
 * function: func_021B7F24
 * address: 0x021B7F24
 * packet: pkt_ov102_021B7F24
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * declaration: 0200ED48's void legacy declaration is a tail call to pointer-returning 020071CC; preserve the incoming save object and live pointer result through 020120F4/02012EBC/0200ED48.
 * symbols:
 * func_021B7250 0x021B7250 thumb ov101
 * func_021B7264 0x021B7264 thumb ov101
 * func_021B72A0 0x021B72A0 thumb ov101
 * func_021B72A8 0x021B72A8 thumb ov101
 * func_021B63BC 0x021B63BC thumb ov101
 * func_021B6150 0x021B6150 thumb ov101
 * func_021B6254 0x021B6254 thumb ov101
 * func_021B62AC 0x021B62AC thumb ov101
 * func_021B6568 0x021B6568 thumb ov101
 * func_021B657C 0x021B657C thumb ov101
 * func_021B630C 0x021B630C thumb ov101
 * func_021B6518 0x021B6518 thumb ov101
 * func_021B652C 0x021B652C thumb ov101
 * func_021B6540 0x021B6540 thumb ov101
 * func_021B6554 0x021B6554 thumb ov101
 * func_021B63CC 0x021B63CC thumb ov101
 * func_021B6424 0x021B6424 thumb ov101
 * func_021B6480 0x021B6480 thumb ov101
 * func_021B7F08 0x021B7F08 thumb ov102
 * func_021B7DFC 0x021B7DFC thumb ov102
 * func_021B8724 0x021B8724 thumb ov102
 * func_021B8320 0x021B8320 thumb ov102
 * func_021B82DC 0x021B82DC thumb ov102
 * func_021B83E0 0x021B83E0 thumb ov102
 * func_020061E4 0x020061E4 thumb
 * func_020409B4 0x020409B4 arm
 * func_020120F4 0x020120F4 thumb
 * func_02012EBC 0x02012EBC thumb
 * func_0200ED48 0x0200ED48 thumb
 * func_02008530 0x02008530 thumb
 * func_0200ED54 0x0200ED54 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#define W(k) (*(u32 *)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
#define O ((u8 *)W(0x48c))
#define C (*(void **)(O+4))
struct L0200ED54;
extern int func_021B7250(int *p);
extern void func_021B7264(void *),func_021B72A0(void *,int),func_021B72A8(void *,u32);
extern void func_021B63BC(void *),func_021B63CC(void *,int);
extern int func_021B6150(void *),func_021B6254(void *),func_021B62AC(void *),func_021B630C(void *,int);
extern int func_021B6568(void *,u32),func_021B6518(void *,u32,u32);
extern void func_021B657C(void *,u32);
extern int func_021B652C(void *),func_021B6540(void *),func_021B6554(void *),func_021B6424(void *),func_021B6480(void *);
extern void func_021B7F08(u8 *,void (*)(u8 *,u16 *));
extern void func_021B7DFC(u8 *,void *,int,int,short);
extern void func_021B8724(u8 *);
extern void func_021B8320(u8 *,u16 *),func_021B82DC(u8 *,u16 *),func_021B83E0(u8 *,u16 *);
extern void func_020061E4(int),func_020409B4(u32);
extern void *func_020120F4(const void *),*func_02012EBC(void *),*func_0200ED48(void *);
extern u32 func_02008530(const void *);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
void func_021B7F24(u8 *p,u16 *state)
{
    void *save;
    if(*state<14 && func_021B7250((void *)W(0x468))==1) {
        func_021B63BC(C);
        func_021B7F08(p,func_021B8320);
        func_021B7264((void *)W(0x468));
        func_021B72A8((void *)W(0x468),0);
        func_020409B4(0);
        func_021B7DFC(p+0xac,p+0x9c,5,0,0);
        func_021B8724(p+0xc0);
        return;
    }
    switch(*state) {
    case 0: func_021B63BC(C); *state=1; break;
    case 1:
        if(func_021B6150(C)) { func_020061E4(1620); func_021B72A0((void *)W(0x468),1); *state=2; }
        break;
    case 2: if(func_021B6254(C)) *state=3; break;
    case 3: func_021B7DFC(p+0xac,p+0x9c,4,0,0); *state=4; break;
    case 4: if(func_021B62AC(C)) *state=5; break;
    case 5:
        if(func_021B6568(C,*(u32 *)O)) {
            func_021B657C(C,*(u32 *)(O+16));
            if(*(u32 *)O) {
                save=func_0200ED48(func_02012EBC(func_020120F4(*(void **)O)));
                func_0200ED54(save,func_02008530(*(u8 **)(O+16)+12));
            }
            *state=6;
        }
        break;
    case 6: if(func_021B630C(C,0)) *state=8; break;
    case 8:
        W(0x4a0)=1;
        if(func_021B6518(C,W(0x498),W(0x494))) *state=9;
        break;
    case 9: if(func_021B652C(C)) *state=10; break;
    case 10: if(func_021B6540(C)) *state=11; break;
    case 11: if(func_021B6554(C)) *state=12; break;
    case 12: func_021B63CC(C,1); if(func_021B6424(C)) *state=13; break;
    case 13: if(func_021B630C(C,1)) { func_021B72A0((void *)W(0x468),0); *state=14; } break;
    case 14:
        if(H(0x486)>=60) { func_020061E4(1611); func_021B7DFC(p+0xac,p+0x9c,2,0,0); *state=15; }
        break;
    case 15:
        if(W(0x49c)++>=30) { *(u32 *)(O+12)=0; func_021B7F08(p,func_021B82DC); }
        return;
    }
    if(*state>=3 && *state<=14 && H(0x486)<=60) H(0x486)++;
    if(*state<12 && func_021B6480(C)) func_021B7F08(p,func_021B83E0);
}
