/*
 * function: func_021D7814
 * address: 0x021D7814
 * packet: pkt_ov121_021D7814
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 0x021D79BC writes the display blend register 0x04000050.
 * symbols:
 *   func_021D9750 0x021D9750 thumb ov121
 *   func_02040588 0x02040588 arm
 *   func_021D9744 0x021D9744 thumb ov121
 *   func_021D84D4 0x021D84D4 thumb ov121
 *   func_021D8C1C 0x021D8C1C thumb ov121
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 *   func_021D8D00 0x021D8D00 thumb ov121
 *   func_021D8D18 0x021D8D18 thumb ov121
 *   MYSTERY_DATA_SaveStart 0x0200A2B8 thumb
 *   MYSTERY_DATA_SaveMain 0x0200A2D8 thumb
 *   func_021D8CA8 0x021D8CA8 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021D8380 0x021D8380 thumb ov121
 *   func_021D9790 0x021D9790 thumb ov121
 *   func_02082BCC 0x02082BCC arm
 *   func_021DCFC8 0x021DCFC8 thumb ov121
 *   func_021DD24C 0x021DD24C thumb ov121
 *   MYSTERY_ALBUM_RequestSetup 0x021DE0AC thumb ov121
 *   MYSTERY_ALBUM_StepIntro 0x021DD9CC thumb ov121
 *   MYSTERY_ALBUM_StartIntro 0x021DDF5C thumb ov121
 *   MYSTERY_ALBUM_IsIntroIdle 0x021DE014 thumb ov121
 *   func_020362DC 0x020362DC arm
 *   func_021D93F4 0x021D93F4 thumb ov121
 *   func_021D94B8 0x021D94B8 thumb ov121
 *   func_021D9488 0x021D9488 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D6DF4 0x021D6DF4 thumb ov121
 */
#include "../include/Obj00297.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w[12]; } Desc;
extern void func_021D9750(u8 *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern unsigned func_021D9744(char *p);
extern void func_021D84D4(u8 *out, void *owner, const u8 *desc, void *save, void *list, void *a5, void *a6, u16 heap);
extern void func_021D8C1C(u8 *p, int mode);
extern void func_021D9F08(u8 *a, int b, int c, int d);
extern unsigned func_021D9FF8(u8 *p);
extern void func_021D8D00(char *p);
extern int func_021D8D18(char *p);
extern void MYSTERY_DATA_SaveStart(void *a0, int a1);
extern int MYSTERY_DATA_SaveMain(void *a0, int a1);
extern void func_021D8CA8(u8 *p);
extern void func_021D9E04(u8 *p);
extern void func_021D8380(char *p);
extern void func_021D9790(char *p);
extern void func_02082BCC(void *,int,int);
extern void *func_021DCFC8(Desc *,u16);
extern void *func_021DD24C(void *,void *,void *,u16);
extern void MYSTERY_ALBUM_RequestSetup(u8 *p, u32 b);
extern void MYSTERY_ALBUM_StepIntro(char *p);
extern void MYSTERY_ALBUM_StartIntro(u8 *p);
extern int MYSTERY_ALBUM_IsIntroIdle(char *p);
extern u32 func_020362DC(void);
extern void func_021D93F4(u8 *p, const void *q, int n, int k, int x, int y, int z, u16 heap);
extern int func_021D94B8(char *p);
extern void func_021D9488(void **p);
extern void func_021DA8B0(u32 *p, u32 a);
extern void func_021D6DF4(void *a, int *state);
void func_021D7814(void *task,u32 *state,u8 *p)
{
    Desc d;
    switch (*state) {
    case 0:
        func_021D9750(((struct Obj00297 *)p)->f394);
        func_02040588(1,1);
        func_02040588(3,1);
        func_021D84D4(p+12,(void *)func_021D9744(((struct Obj00297 *)p)->f394),p+972,(void *)(*(int *)&((struct Obj00297 *)p)->f3B8),p+660,p+912,p+312,29);
        func_021D8C1C(p+12,0);
        func_021D9F08(((struct Obj00297 *)p)->f284,((struct Obj00297 *)p)->f3A4,113,2);
        *state=1;
        break;
    case 1:
        func_02040588(0,1);
        *state=2;
        break;
    case 2:
        if (func_021D9FF8(((struct Obj00297 *)p)->f284)) *state=3;
        break;
    case 3:
        func_021D8D00((char *)(p+12));
        if (func_021D8D18((char *)(p+12))) *state=4;
        break;
    case 4:
        MYSTERY_DATA_SaveStart(((struct Obj00297 *)p)->f3BC,(int)(((struct Obj00297 *)p)->f3B8));
        *state=5;
        break;
    case 5:
        if (MYSTERY_DATA_SaveMain(((struct Obj00297 *)p)->f3BC,(int)(((struct Obj00297 *)p)->f3B8))==2) *state=6;
        break;
    case 6:
        func_021D8C1C(p+12,1);
        *state=7;
        break;
    case 7:
        func_021D8D00((char *)(p+12));
        if (func_021D8D18((char *)(p+12))) *state=8;
        break;
    case 8:
        func_021D9F08(((struct Obj00297 *)p)->f284,((struct Obj00297 *)p)->f3A4,114,1);
        *state=9;
        break;
    case 9:
        if (func_021D9FF8(((struct Obj00297 *)p)->f284)) *state=10;
        break;
    case 10:
        func_021D8CA8(p+12);
        func_021D9E04(((struct Obj00297 *)p)->f284);
        ((struct Obj00297 *)p)->f284=0;
        func_021D8380((char *)p);
        *(volatile u16 *)0x04000050=0;
        func_021D9790(((struct Obj00297 *)p)->f394);
        func_02040588(1,1);
        func_02040588(3,1);
        *state=11;
        break;
    case 11:
        func_02040588(0,1);
        *state=12;
        break;
    case 12:
        func_02040588(1,0);
        func_02082BCC(&d,0,48);
        d.w[0]=2;
        d.w[1]=0;
        d.w[2]=8;
        d.w[3]=15;
        d.w[5]=13;
        d.w[4]=10;
        d.w[6]=(u32)func_021D9744(((struct Obj00297 *)p)->f394);
        d.w[7]=*(u32 *)&((struct Obj00297 *)p)->f3BC;
        d.w[8]=*(u32 *)&((struct Obj00297 *)p)->f3A4;
        d.w[9]=((struct Obj00297 *)p)->f398;
        d.w[10]=((struct Obj00297 *)p)->f39C;
        d.w[11]=((struct Obj00297 *)p)->f3A8;
        ((struct Obj00297 *)p)->f4=func_021DCFC8(&d,29);
        ((struct Obj00297 *)p)->f0=func_021DD24C(p+972,((struct Obj00297 *)p)->f4,((struct Obj00297 *)p)->f3B8,29);
        MYSTERY_ALBUM_RequestSetup(((struct Obj00297 *)p)->f0,0);
        *state=13;
        break;
    case 13:
        MYSTERY_ALBUM_StepIntro(((struct Obj00297 *)p)->f0);
        MYSTERY_ALBUM_StartIntro(((struct Obj00297 *)p)->f0);
        *state=14;
        break;
    case 14:
        MYSTERY_ALBUM_StepIntro(((struct Obj00297 *)p)->f0);
        if (MYSTERY_ALBUM_IsIntroIdle(((struct Obj00297 *)p)->f0)) {
            ((struct Obj00297 *)p)->f3C4=0;
            *state=15;
        }
        break;
    case 15:
        if (func_020362DC()&1) *state=18;
        if ((((struct Obj00297 *)p)->f3C4)++>240) {
            ((struct Obj00297 *)p)->f3C4=0;
            *state=16;
        }
        break;
    case 16:
        func_021D93F4(p+612,p+660,(int)func_021D9744(((struct Obj00297 *)p)->f394),*(int *)&((struct Obj00297 *)p)->f39C,((struct Obj00297 *)p)->f3A4,155,*(int *)&((struct Obj00297 *)p)->f398,29);
        func_021D94B8((char *)(p+612));
        *state=17;
        break;
    case 17:
        func_021D94B8((char *)(p+612));
        if (func_020362DC()&1) {
            func_021D9488((void **)(p+612));
            *state=18;
        }
        break;
    case 18:
        func_021DA8B0(task,(u32)func_021D6DF4);
        break;
    }
}
