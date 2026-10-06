/*
 * file:     unit_0207FD34_p03.c
 * unit:     yes
 * function: func_0208040C, func_020804E8, func_020805E8, func_0208068C, func_020806B0, func_0208074C, func_020807BC, func_0208083C, func_020808BC, func_020808F4, func_02080908, func_0208091C, func_02080940, func_02080964, func_02080978, func_0208098C, func_020809A0, func_020809B4, func_020809C8, func_020809F0, func_02080A18, func_02080AD8, func_02080AEC, func_02080B00, func_02080B24, func_02080B48, func_02080B5C, func_02080B70, func_02080B84, func_02080B98, func_02080BAC, func_02080BC0, func_02080BD4, func_02080BFC
 * address:  0x0208040C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GX_VRAMCNT_SetLCDC_   0x0207FD34  arm
 *   gGXState              0x02150E4C  data
 *   g_02150E4C 0x02150E4C data
 *   func_0207FD34 0x0207FD34 arm
 *   g_02150E5A 0x02150E5A data
 *   g_02150E5C 0x02150E5C data
 *   g_02150E62 0x02150E62 data
 *   g_02150E64 0x02150E64 data
 *   OSi_UnlockVram    0x02087EDC  arm
 *   GXi_VRamLockId    0x02150E0E  data
 *   disableBankForX_   0x02080A18  arm
 */
typedef long fx32;

typedef short fx16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef volatile u8 vu8;

typedef volatile u16 vu16;

typedef volatile u32 vu32;

typedef union {
    struct {
        fx32 _00, _01;
        fx32 _10, _11;
    };
    fx32 m[2][2];
    fx32 a[4];
} MtxFx22;

typedef struct {
    u16 lcdc;
    u16 bg;
    u16 obj;
    u16 arm7;
    u16 tex;
    u16 texPltt;
    u16 clrImg;
    u16 bgExtPltt;
    u16 objExtPltt;
    u16 sub_bg;
    u16 sub_obj;
    u16 sub_bgExtPltt;
    u16 sub_objExtPltt;
} GX_VRAMCnt_;

typedef struct {
    GX_VRAMCnt_ vramCnt;
} GX_State;

typedef enum {
    GX_VRAM_NONE = 0x0000,
    GX_VRAM_A = 0x0001,
    GX_VRAM_B = 0x0002,
    GX_VRAM_C = 0x0004,
    GX_VRAM_D = 0x0008,
    GX_VRAM_E = 0x0010,
    GX_VRAM_F = 0x0020,
    GX_VRAM_G = 0x0040,
    GX_VRAM_H = 0x0080,
    GX_VRAM_I = 0x0100
} GXVRam;

extern void GX_VRAMCNT_SetLCDC_(int lcdc);
extern void g_02150E4C(void);
extern void func_0207FD34(void);
extern void g_02150E5A(void);
extern void g_02150E5C(void);
extern void g_02150E62(void);
extern void g_02150E64(void);
extern void OSi_UnlockVram(u16 bank, u16 lockId);
extern int disableBankForX_(u16 *g3bit);
void func_0208040C(int texPltt);
void func_020804E8(int clrImg);
void func_020805E8(int arm7);
asm void GX_SetBankForLCDC(void);
void func_020806B0(int sub_bg);
void func_0208074C(int sub_obj);
void func_020807BC(int sub_bgExtPltt);
void func_0208083C(int sub_objExtPltt);
int func_020808BC(u16 *g3bit);
int func_020808F4(void);
void func_02080908(void);
asm void GX_DisableBankForBGExtPltt(void);
asm void GX_DisableBankForOBJExtPltt(void);
int func_02080964(void);
void func_02080978(void);
void func_0208098C(int a0, int a1, int a2, int a3);
int func_020809A0(void);
void func_020809B4(void);
asm void GX_DisableBankForSubBGExtPltt(void);
asm void GX_DisableBankForSubOBJExtPltt(void);
int func_02080A18(u16 *g3bit);
GXVRam func_02080AD8(void);
GXVRam func_02080AEC(void);
GXVRam func_02080B00(void);
GXVRam func_02080B24(void);
GXVRam func_02080B48(void);
GXVRam func_02080B5C(void);
GXVRam func_02080B70(void);
GXVRam func_02080B84(void);
void func_02080B98(void);
void func_02080BAC(int a0, int a1, int a2, int a3);
void func_02080BC0(int a0, int a1, int a2, int a3);
GXVRam func_02080BD4(void);
GXVRam func_02080BFC(void);
extern GX_State gGXState;
extern u16 GXi_VRamLockId;






#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)





#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)





#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)





#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)





#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)





#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)





#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)





#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)





#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)





#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)





#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)






/*
 * sdk:      GX_SetBankForTexPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void func_0208040C(int texPltt)
{
    gGXState.vramCnt.lcdc = (u16)(~texPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.texPltt));
    gGXState.vramCnt.texPltt = (u16)texPltt;

    switch (texPltt) {
    case 0:
        break;
    case 0x060:
        reg_GX_VRAMCNT_G = 0x8b;
        /* fall through */
    case 0x020:
        reg_GX_VRAMCNT_F = 0x83;
        break;
    case 0x040:
        reg_GX_VRAMCNT_G = 0x83;
        break;
    case 0x070:
        reg_GX_VRAMCNT_G = 0x9b;
        /* fall through */
    case 0x030:
        reg_GX_VRAMCNT_F = 0x93;
        /* fall through */
    case 0x010:
        reg_GX_VRAMCNT_E = 0x83;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}






#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)





#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)





#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)





#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)





#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)





#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)





#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)





#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)





#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)





#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)





#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)






#define reg_G3X_DISP3DCNT (*(vu16 *)0x04000060)






/*
 * sdk:      GX_SetBankForClearImage (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void func_020804E8(int clrImg)
{
    gGXState.vramCnt.lcdc = (u16)(~clrImg & (gGXState.vramCnt.lcdc | gGXState.vramCnt.clrImg));
    gGXState.vramCnt.clrImg = (u16)clrImg;

    switch (clrImg) {
    case 0x003:
        reg_GX_VRAMCNT_A = 0x93;
        /* fall through */
    case 0x002:
        reg_GX_VRAMCNT_B = 0x9b;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    case 0x00c:
        reg_GX_VRAMCNT_C = 0x93;
        /* fall through */
    case 0x008:
        reg_GX_VRAMCNT_D = 0x9b;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    case 0:
        reg_G3X_DISP3DCNT &= ~0x4000;
        break;
    case 0x001:
        reg_GX_VRAMCNT_A = 0x9b;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    case 0x004:
        reg_GX_VRAMCNT_C = 0x9b;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}






#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)





#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)





#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)





#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)





#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)





#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)





#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)





#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)





#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)





#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)





#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)






/*
 * sdk:      GX_SetBankForARM7 (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void func_020805E8(int arm7)
{
    gGXState.vramCnt.lcdc = (u16)(~arm7 & (gGXState.vramCnt.lcdc | gGXState.vramCnt.arm7));
    gGXState.vramCnt.arm7 = (u16)arm7;

    switch (arm7) {
    case 0:
        break;
    case 0x004:
        reg_GX_VRAMCNT_C = 0x82;
        break;
    case 0x00c:
        reg_GX_VRAMCNT_D = 0x8a;
        reg_GX_VRAMCNT_C = 0x82;
        break;
    case 0x008:
        reg_GX_VRAMCNT_D = 0x82;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}





asm void GX_SetBankForLCDC(void)
{
    ldr r2, =g_02150E4C
    mov r1, r0, lsl #16
    ldrh r3, [r2]
    ldr ip, =func_0207FD34
    orr r1, r3, r1, lsr #16
    strh r1, [r2]
    bx ip
}






#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)





#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)





#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)





#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)





#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)





#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)





#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)





#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)





#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)





#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)





#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)






/*
 * sdk:      GX_SetBankForSubBG (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void func_020806B0(int sub_bg)
{
    gGXState.vramCnt.lcdc = (u16)(~sub_bg & (gGXState.vramCnt.lcdc | gGXState.vramCnt.sub_bg));
    gGXState.vramCnt.sub_bg = (u16)sub_bg;

    switch (sub_bg) {
    case 0x004:
        reg_GX_VRAMCNT_C = 0x84;
        break;
    case 0x180:
        reg_GX_VRAMCNT_I = 0x81;
        /* fall through */
    case 0x080:
        reg_GX_VRAMCNT_H = 0x81;
        break;
    case 0:
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}





#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)




#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)




#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)




#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)




#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)




#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)




#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)




#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)




#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)




#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)




#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)





/*
 * sdk:      GX_SetBankForSubOBJ (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void func_0208074C(int sub_obj)
{
    gGXState.vramCnt.lcdc = (u16)(~sub_obj & (gGXState.vramCnt.lcdc | gGXState.vramCnt.sub_obj));
    gGXState.vramCnt.sub_obj = (u16)sub_obj;

    switch (sub_obj) {
    case 0x008:
        reg_GX_VRAMCNT_D = 0x84;
        break;
    case 0x100:
        reg_GX_VRAMCNT_I = 0x82;
        break;
    case 0:
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}





#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)




#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)




#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)




#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)




#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)




#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)




#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)




#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)




#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)




#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)




#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)





/*
 * sdk:      GX_SetBankForSubBGExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void func_020807BC(int sub_bgExtPltt)
{
    gGXState.vramCnt.lcdc = (u16)(~sub_bgExtPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.sub_bgExtPltt));
    gGXState.vramCnt.sub_bgExtPltt = (u16)sub_bgExtPltt;

    switch (sub_bgExtPltt) {
    case 0x080:
        reg_GXS_DB_DISPCNT |= 0x40000000;
        reg_GX_VRAMCNT_H = 0x82;
        break;
    case 0:
        reg_GXS_DB_DISPCNT &= ~0x40000000;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}





#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)




#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)




#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)




#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)




#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)




#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)




#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)




#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)




#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)




#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)




#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)





/*
 * sdk:      GX_SetBankForSubOBJExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void func_0208083C(int sub_objExtPltt)
{
    gGXState.vramCnt.lcdc = (u16)(~sub_objExtPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.sub_objExtPltt));
    gGXState.vramCnt.sub_objExtPltt = (u16)sub_objExtPltt;

    switch (sub_objExtPltt) {
    case 0x100:
        reg_GXS_DB_DISPCNT |= 0x80000000;
        reg_GX_VRAMCNT_I = 0x83;
        break;
    case 0:
        reg_GXS_DB_DISPCNT &= ~0x80000000;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}





#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)




#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)




#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)




#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)




#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)




#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)




#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)




#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)




#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)




#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)




#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)





/*
 * sdk:      resetBankForX_ (libgx.TWL.HYB.a gx_vramcnt.o)
 */
int func_020808BC(u16 *g3bit)
{
    int rval = *g3bit;

    *g3bit = 0;
    gGXState.vramCnt.lcdc |= rval;
    GX_VRAMCNT_SetLCDC_(rval);
    return rval;
}




int func_020808F4(void){ return func_020808BC((u16 *)((int)0x2150E4E)); }




void func_02080908(void){ func_020808BC((u16 *)((int)0x2150E50)); }





asm void GX_DisableBankForBGExtPltt(void)
{
    mov	r2, #0x4000000
    ldr	r1, [r2]
    ldr r0, =g_02150E5A
    bic	r1, r1, #0x40000000
    ldr ip, =func_020808BC
    str	r1, [r2]
    bx	ip
}





asm void GX_DisableBankForOBJExtPltt(void)
{
    mov	r2, #0x4000000
    ldr	r1, [r2]
    ldr r0, =g_02150E5C
    bic	r1, r1, #0x80000000
    ldr ip, =func_020808BC
    str	r1, [r2]
    bx	ip
}




int func_02080964(void){ return func_020808BC((void *)0x02150E54); }




void func_02080978(void){ func_020808BC((u16 *)((int)0x2150E56)); }




void func_0208098C(int a0, int a1, int a2, int a3){ func_020808BC((u16 *)((int)0x2150E58)); }




int func_020809A0(void){ return func_020808BC((u16 *)((int)0x2150E5E)); }



void func_020809B4(void){ func_020808BC((u16 *)((int)0x2150E60)); }




asm void GX_DisableBankForSubBGExtPltt(void)
{
    ldr r2, =0x04001000
    ldr r0, =g_02150E62
    ldr	r1, [r2]
    ldr ip, =func_020808BC
    bic	r1, r1, #0x40000000
    str	r1, [r2]
    bx	ip
}




asm void GX_DisableBankForSubOBJExtPltt(void)
{
    ldr r2, =0x04001000
    ldr r0, =g_02150E64
    ldr	r1, [r2]
    ldr ip, =func_020808BC
    bic	r1, r1, #0x80000000
    str	r1, [r2]
    bx	ip
}




#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)



#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)



#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)



#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)



#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)



#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)



#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)



#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)



#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)



#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)



#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)




/*
 * sdk:      disableBankForX_ (libgx.TWL.HYB.a gx_vramcnt.o)
 */
int func_02080A18(u16 *g3bit)
{
    int rval = *g3bit;

    *g3bit = 0;
    if (rval & GX_VRAM_A) {
        reg_GX_VRAMCNT_A = 0;
    }
    if (rval & GX_VRAM_B) {
        reg_GX_VRAMCNT_B = 0;
    }
    if (rval & GX_VRAM_C) {
        reg_GX_VRAMCNT_C = 0;
    }
    if (rval & GX_VRAM_D) {
        reg_GX_VRAMCNT_D = 0;
    }
    if (rval & GX_VRAM_E) {
        reg_GX_VRAMCNT_E = 0;
    }
    if (rval & GX_VRAM_F) {
        reg_GX_VRAMCNT_F = 0;
    }
    if (rval & GX_VRAM_G) {
        reg_GX_VRAMCNT_G = 0;
    }
    if (rval & GX_VRAM_H) {
        reg_GX_VRAMCNT_H = 0;
    }
    if (rval & GX_VRAM_I) {
        reg_GX_VRAMCNT_I = 0;
    }
    OSi_UnlockVram((u16)rval, GXi_VRamLockId);
    return rval;
}




#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)



#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)



#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)



#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)



#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)



#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)



#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)



#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)



#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)



#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)



#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)




/*
 * sdk:      GX_DisableBankForBG (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam func_02080AD8(void)
{
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.bg);
}




#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)



#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)



#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)



#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)



#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)



#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)



#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)



#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)



#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)



#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)



#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)




/*
 * sdk:      GX_DisableBankForOBJ (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam func_02080AEC(void)
{
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.obj);
}




#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)



#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)



#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)



#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)



#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)



#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)



#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)



#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)



#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)



#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)



#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)




/*
 * sdk:      GX_DisableBankForBGExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam func_02080B00(void)
{
    reg_GX_DISPCNT &= ~0x40000000;
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.bgExtPltt);
}




#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)



#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)



#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)



#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)



#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)



#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)



#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)



#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)



#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)



#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)



#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)




/*
 * sdk:      GX_DisableBankForOBJExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam func_02080B24(void)
{
    reg_GX_DISPCNT &= ~0x80000000;
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.objExtPltt);
}




#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)



#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)



#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)



#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)



#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)



#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)



#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)



#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)



#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)



#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)



#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)




/*
 * sdk:      GX_DisableBankForTex (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam func_02080B48(void)
{
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.tex);
}




#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)



#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)



#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)



#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)



#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)



#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)



#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)



#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)



#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)



#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)



#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)




/*
 * sdk:      GX_DisableBankForTexPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam func_02080B5C(void)
{
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.texPltt);
}




#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)



#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)



#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)



#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)



#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)



#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)



#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)



#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)



#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)



#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)



#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)




/*
 * sdk:      GX_DisableBankForClearImage (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam func_02080B70(void)
{
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.clrImg);
}



#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)


#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)


#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)


#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)


#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)


#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)


#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)


#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)


#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)


#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)


#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)



/*
 * sdk:      GX_DisableBankForARM7 (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam func_02080B84(void)
{
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.arm7);
}


void func_02080B98(void){ func_02080A18((void *)0x02150E4C); }


void func_02080BAC(int a0, int a1, int a2, int a3){ func_02080A18((u16 *)((int)0x2150E5E)); }


void func_02080BC0(int a0, int a1, int a2, int a3){ func_02080A18((u16 *)((int)0x2150E60)); }



#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)


#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)


#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)


#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)


#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)


#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)


#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)


#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)


#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)


#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)


#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)



/*
 * sdk:      GX_DisableBankForSubBGExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam func_02080BD4(void)
{
    reg_GXS_DB_DISPCNT &= ~0x40000000;
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.sub_bgExtPltt);
}



#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)


#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)


#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)


#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)


#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)


#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)


#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)


#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)


#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)


#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)


#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)



/*
 * sdk:      GX_DisableBankForSubOBJExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam func_02080BFC(void)
{
    reg_GXS_DB_DISPCNT &= ~0x80000000;
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.sub_objExtPltt);
}
