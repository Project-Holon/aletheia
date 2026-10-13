/*
 * function: DWCi_MOVFramework
 * address:  0x021D3DC0
 * packet:   pkt_ov016_021D3DC0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * State tick for the object pointed to by 0x021DE668: dispatch on its byte
 * state at +0xa90 (table 0..0x22) and advance the +0xa9c delay counter /
 * +0xa98 frame counter, calling the per-state helper.  Addresses are
 * Black-image addresses.
 * symbols:
 *   gDwcMoveidWork  0x021DE668  data
 *   DWCi_MOVStartAdmitChild 0x021D3D44  arm  ov016
 *   func_021D4148 0x021D4148  arm  ov016
 *   func_021D41F0 0x021D41F0  arm  ov016
 *   func_021D4214 0x021D4214  arm  ov016
 *   func_021D439C 0x021D439C  arm  ov016
 *   func_021D43C8 0x021D43C8  arm  ov016
 *   func_021D455C 0x021D455C  arm  ov016
 *   func_021D4574 0x021D4574  arm  ov016
 *   func_021D3250 0x021D3250  arm  ov016
 *   DWCi_MOV_WH_End 0x021D3AC8  arm  ov016
 *   DWCi_MOV_WH_Finalize 0x021D39C0  arm  ov016
 *   DWCi_DwcMoveidMB_EndToIdle 0x021F5F74  arm
 */

typedef struct Sub021D3DC0 {
    char _a90[0xa90];
    unsigned char state;
    char _a91[0xa98 - 0xa91];
    unsigned int f_a98;
    unsigned int f_a9c;
    char _aa0[0xaac - 0xaa0];
    unsigned char f_aac;
} Sub021D3DC0;

extern Sub021D3DC0 *gDwcMoveidWork;

extern int DWCi_MOVStartAdmitChild(void);
extern void func_021D4148(void);
extern void func_021D41F0(void);
extern void func_021D4214(void);
extern void func_021D439C(void);
extern void func_021D43C8(void);
extern void func_021D455C(void);
extern int func_021D4574(void);
extern unsigned int func_021D3250(void);
extern int DWCi_MOV_WH_End(void);
extern void DWCi_MOV_WH_Finalize(void);
extern void DWCi_DwcMoveidMB_EndToIdle(void);

void DWCi_MOVFramework(void)
{
    switch (gDwcMoveidWork->state) {
    case 1:
        if (gDwcMoveidWork->f_aac == 1) {
            gDwcMoveidWork->f_aac = 0;
            DWCi_MOVStartAdmitChild();
            return;
        }
        if (gDwcMoveidWork->f_aac == 2) {
            gDwcMoveidWork->f_aac = 0;
            gDwcMoveidWork->state = 0x22;
        }
        return;
    case 2:
        func_021D4148();
        return;
    case 3:
        func_021D41F0();
        gDwcMoveidWork->state = 4;
        return;
    case 4:
        gDwcMoveidWork->f_a98++;
        func_021D4214();
        return;
    case 5:
    case 6:
        func_021D4214();
        return;
    case 7:
        func_021D439C();
        return;
    case 8:
    case 9:
    case 10:
        func_021D43C8();
        return;
    case 11:
        func_021D455C();
        return;
    case 16:
        gDwcMoveidWork->f_a9c = 0;
        gDwcMoveidWork->state = 0x11;
        return;
    case 17:
        if (gDwcMoveidWork->f_a9c++ <= 0x1e)
            return;
        func_021D4574();
        return;
    case 18:
        DWCi_DwcMoveidMB_EndToIdle();
        gDwcMoveidWork->f_a9c = 0;
        gDwcMoveidWork->state = 0x16;
        return;
    case 19:
        if (gDwcMoveidWork->f_a9c++ <= 0x1e)
            return;
        if (func_021D3250() != 1)
            return;
        DWCi_MOV_WH_End();
        gDwcMoveidWork->state = 0x14;
        return;
    case 21:
        DWCi_MOV_WH_Finalize();
        gDwcMoveidWork->f_a9c = 0;
        gDwcMoveidWork->state = 0x16;
        return;
    case 22:
        if (gDwcMoveidWork->f_a9c++ <= 0x1e)
            return;
        if (func_021D3250() != 1)
            return;
        DWCi_MOV_WH_End();
        gDwcMoveidWork->state = 0x17;
        return;
    case 24:
        DWCi_MOV_WH_Finalize();
        gDwcMoveidWork->f_a9c = 0;
        gDwcMoveidWork->state = 0x19;
        return;
    case 25:
        if (gDwcMoveidWork->f_a9c++ <= 0x1e)
            return;
        if (func_021D3250() != 1)
            return;
        DWCi_MOV_WH_End();
        gDwcMoveidWork->state = 0x1a;
        return;
    case 27:
        DWCi_MOV_WH_Finalize();
        gDwcMoveidWork->f_a9c = 0;
        gDwcMoveidWork->state = 0x1c;
        return;
    case 28:
        if (gDwcMoveidWork->f_a9c++ <= 0x1e)
            return;
        if (func_021D3250() == 1) {
            DWCi_MOV_WH_End();
            gDwcMoveidWork->state = 0x1d;
            return;
        }
        if (gDwcMoveidWork->f_a9c % 30 != 1)
            return;
        if (gDwcMoveidWork->f_a9c <= 0x37)
            return;
        DWCi_MOV_WH_Finalize();
        return;
    case 32:
        DWCi_MOV_WH_Finalize();
        gDwcMoveidWork->f_a9c = 0;
        gDwcMoveidWork->state = 0x21;
        return;
    case 33:
        if (gDwcMoveidWork->f_a9c++ <= 0x1e)
            return;
        if (func_021D3250() != 1)
            return;
        DWCi_MOV_WH_End();
        gDwcMoveidWork->state = 0x22;
        return;
    case 30:
        DWCi_MOV_WH_Finalize();
        return;
    case 0x22:
        return;
    }
    return;
}
