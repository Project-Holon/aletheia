/*
 * function: NNSi_G2dLoadVramResourceBySel
 * address:  0x02063E54
 * packet:   pkt_0206380C
 * status:   EXACT
 * symbols:
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   func_0207F47C  0x0207F47C  arm
 *   func_0207F4C4  0x0207F4C4  arm
 *   func_0207F560  0x0207F560  arm
 *   GX_LoadOBJPltt  0x0207E51C  arm
 *   func_0207F6A8  0x0207F6A8  arm
 *   func_0207F6C0  0x0207F6C0  arm
 *   func_0207F754  0x0207F754  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207FA0C  0x0207FA0C  arm
 *   func_0207FA40  0x0207FA40  arm
 *   func_0207FADC  0x0207FADC  arm
 *   NNSi_G2dSetVramHandleEx  0x020637F4  arm
 */

typedef unsigned int u32;

typedef struct UnkSelf02063E54 {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
} UnkSelf02063E54;

typedef struct UnkOut02063E54 {
    u32 f0;
    u32 f4;
} UnkOut02063E54;

extern void DWCi_ScreenDC_FlushRange(u32 a, u32 b);
extern void func_0207F47C(u32 a);
extern void func_0207F4C4(u32 a, u32 b, u32 c);
extern void func_0207F560(void);
extern void GX_LoadOBJPltt(u32 a, u32 b, u32 c);
extern void func_0207F6A8(u32 a);
extern void func_0207F6C0(u32 a, u32 b, u32 c);
extern void func_0207F754(void);
extern void func_0207E5D0(u32 a, u32 b, u32 c);
extern void func_0207FA0C(void);
extern void func_0207FA40(u32 a, u32 b, u32 c);
extern void func_0207FADC(void);
extern void NNSi_G2dSetVramHandleEx(UnkOut02063E54 *out, int sel, u32 a1);

void NNSi_G2dLoadVramResourceBySel(UnkSelf02063E54 *self, u32 a1, int sel, UnkOut02063E54 *out)
{
    u32 a = self->fC;
    u32 b = self->f8;

    DWCi_ScreenDC_FlushRange(a, b);

    switch (sel) {
    case 1:
        if (self->f4 != 0) {
            func_0207F47C(self->f4);
            func_0207F4C4(a, a1, b);
            func_0207F560();
        } else {
            GX_LoadOBJPltt(a, a1, b);
        }
        break;
    case 2:
        if (self->f4 != 0) {
            func_0207F6A8(self->f4);
            func_0207F6C0(a, a1, b);
            func_0207F754();
        } else {
            func_0207E5D0(a, a1, b);
        }
        break;
    case 0:
        func_0207FA0C();
        func_0207FA40(a, a1, b);
        func_0207FADC();
        break;
    }

    out->f0 = self->f0;
    out->f4 = self->f4;
    NNSi_G2dSetVramHandleEx(out, sel, a1);
}
