/*
 * function: DSP_MapAndLoadProcessImage
 * address:  0x02705ACC
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DSPi_MapAndLoadProcessImageCallback 0x027054E4 arm twl
 *   DSP_EnumSections 0x02705980 arm twl
 *   DSP_SwitchProcessMemory 0x02705A4C arm twl
 *   MI_GetWramMapStart_B 0x027303C4 arm twl
 *   MI_GetWramMapStart_C 0x027303EC arm twl
 *   DC_FlushRange  0x020862F0  arm  arm9
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef struct Chan {
    u32 pad[5];
    void *file;
    u16 f18;
    u16 f1a;
    u32 f1c;
    u32 busy[2];
    u32 tabA[8];
    u32 tabB[8];
} Chan;
typedef struct Hdr {
    u16 pad0;
    u16 count;
    u32 pad4;
    u32 f8;
    u32 fC;
    u16 base;
} Hdr;
typedef struct Ent {
    u32 name0;
    u32 nameOff;
    u32 f8;
    u32 fC;
    u32 len;
    u32 off;
    u32 pad18[3];
    u32 flags;
} Ent;

extern void DC_FlushRange(void *, u32);
extern void *MI_GetWramMapStart_B(void);
extern void *MI_GetWramMapStart_C(void);
s32 DSPi_MapAndLoadProcessImageCallback(Chan *c, Hdr *h, Ent *e);
u32 DSP_EnumSections(Chan *c, s32 (*cb)(Chan *, Hdr *, Ent *));
u32 DSP_SwitchProcessMemory(Chan *c, s32 sel, u32 start, u32 count, u32 mode);

u32 DSP_MapAndLoadProcessImage(Chan *c, void *file, u16 a, u16 b)
{
    u32 ok;
    c->file = file;
    c->f18 = a;
    c->f1a = b;
    ok = 0;
    if (DSP_EnumSections(c, DSPi_MapAndLoadProcessImageCallback)) {
        DC_FlushRange(MI_GetWramMapStart_B(), 0x40000);
        DC_FlushRange(MI_GetWramMapStart_C(), 0x40000);
        if (DSP_SwitchProcessMemory(c, 1, 0, 0x20000, 2)) {
            if (DSP_SwitchProcessMemory(c, 2, 0, 0x20000, 2)) {
                ok = 1;
            }
        }
    }
    return ok;
}
