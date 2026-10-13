/*
 * function: func_021BAF70
 * address: 0x021BAF70
 * packet: pkt_ov217_021BAF70
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   func_021BC600 0x021BC600 thumb ov217
 *   func_021BC608 0x021BC608 thumb ov217
 *   func_021BC6D0 0x021BC6D0 thumb ov217
 *   func_021BBAD0 0x021BBAD0 thumb ov217
 *   func_021BB934 0x021BB934 thumb ov217
 *   func_021BB91C 0x021BB91C thumb ov217
 *   func_021BB910 0x021BB910 thumb ov217
 *   func_021BC5FC 0x021BC5FC thumb ov217
 *   func_021BBDAC 0x021BBDAC thumb ov217
 *   func_021BBD40 0x021BBD40 thumb ov217
 *   func_021BC6DC 0x021BC6DC thumb ov217
 *   func_021BC580 0x021BC580 thumb ov217
 *   func_021BC6EC 0x021BC6EC thumb ov217
 *   func_021BC6F4 0x021BC6F4 thumb ov217
 *   func_021BBAA4 0x021BBAA4 thumb ov217
 *   func_021BC06C 0x021BC06C thumb ov217
 *   func_021C09B8 0x021C09B8 thumb ov217
 *   func_021BC428 0x021BC428 thumb ov217
 *   func_021BC0E8 0x021BC0E8 thumb ov217
 *   KEY_GetCont 0x0203630C arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj00025.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *p);
extern int TOUCHPANEL_HitCont(const void *p);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void *func_021C09B8(void *p);
extern void func_021BC600(void *p);
extern void func_021BC608(void *p);
extern u32 func_021BC6D0(void *p);
extern u32 func_021BC6DC(void *p);
extern void func_021BBAD0(u32 a0);
extern void func_021BB934(u8 *a0, u32 a1);
extern void func_021BB91C(void *p);
extern void func_021BB910(u8 *a0, u32 a1);
extern u32 func_021BC5FC(void *p);
extern void func_021BBDAC(u8 *p);
extern void func_021BBD40(u8 *p, int a);
extern void func_021BC580(char *p, int i);
extern void func_021BC6EC(void *p, u8 v);
extern u32 func_021BC6F4(u32 a0, u32 a1);
extern u32 func_021BBAA4(u32 a0, u8 a1);
extern int func_021BC06C(char *p);
extern int func_021BC428(void *p);
extern u32 func_021BC0E8(u32 a0);

void func_021BAF70(char *p)
{
    u32 trg = KEY_GetCont();
    u32 keys = KEY_GetTrg();
    int sel = TOUCHPANEL_HitTrg(p + 0x64);
    int flag;
    u32 a;
    u32 b;
    flag = TOUCHPANEL_HitTrg(func_021C09B8(*(void **)p));
    TOUCHPANEL_GetPointCont(&a, &b);
    if (trg & 0xc0) {
        func_021BC600(p);
    } else {
        func_021BC608(p);
    }
    if (func_021BC6D0(p) != 0 || flag == 0) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021BBAD0((u32)p);
        func_021BB934((u8 *)p, (int)1);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)6);
        return;
    }
    if ((keys & 0x40) || ((trg & 0x40) && ((struct Obj00025 *)p)->f32 != 0 && func_021BC5FC(p) > 10)) {
        func_021BBDAC((u8 *)p);
        func_021BBD40((u8 *)p, -1);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)3);
        func_021BB910((u8 *)p, (int)2);
        return;
    }
    if ((keys & 0x80) || ((trg & 0x80) && ((struct Obj00025 *)p)->f32 < (int)func_021BC6DC(p) - 1 && func_021BC5FC(p) > 10)) {
        func_021BBDAC((u8 *)p);
        func_021BBD40((u8 *)p, 1);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)3);
        func_021BB910((u8 *)p, (int)2);
        return;
    }
    if (keys & 1) {
        func_021BC580(p, 2);
        func_021BC6EC(p, ((struct Obj00025 *)p)->f32);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        func_021BB910((u8 *)p, (int)9);
        func_021BB91C(p);
        return;
    }
    if (sel >= 0 && sel <= 9) {
        if (b >= 0x18 && b <= 0xa8 && func_021BC6F4((u32)p, (u8)sel) == 1) {
            func_021BBAA4((u32)p, (u8)sel);
            func_021BC6EC(p, ((struct Obj00025 *)p)->f32);
            func_021BC580(p, 2);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            func_021BC06C(p);
            func_021BB91C(p);
            func_021BB910((u8 *)p, (int)7);
        }
        return;
    }
    if (keys & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021BBAD0((u32)p);
        func_021BB934((u8 *)p, (int)0);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)6);
        return;
    }
    if (TOUCHPANEL_HitCont(p + 0x90) == 0 || TOUCHPANEL_HitTrg(p + 0x90) == 0) {
        if (func_021BC428(p) == 1) {
            func_021BBDAC((u8 *)p);
            func_021BC0E8((u32)p);
            func_021BB91C(p);
            func_021BB910((u8 *)p, (int)4);
            func_021BB910((u8 *)p, (int)1);
        }
    }
}
