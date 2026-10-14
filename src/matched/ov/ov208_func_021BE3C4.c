/*
 * function: ZUKAN_DETAIL_TOUCHBAR_LoadLeftArrowResources
 * address:  0x021BE3C4
 * packet:   pkt_ov208_021BE3C4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_021BD148  0x021BD148  thumb
 *   ZKND_TBAR_GetButtonActor  0x021BD3C0  thumb
 *   data_021C8390  0x021C8390  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ov208ActDesc {
    int f0;
    s16 x;
    s16 y;
    u16 h8;
    u16 ha;
    u16 hc;
    u16 he;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 h16;
    u32 f18;
    u32 f1c;
};

struct Ov208ActList {
    struct Ov208ActDesc *descs;
    u32 count;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

struct Ov208ActSrc {
    int id;
    u16 x;
    u16 y;
    u16 h8;
    u16 pad;
    u32 fc;
    u32 f10;
};

struct Ov208Slot {
    struct Ov208ActSrc *src;
    u32 obj;
};

struct Ov208Scene {
    u16 heap;
    u16 pad2;
    u32 pad4[9];
    u32 f28;
    u32 f2c;
    u32 mgr;
    u32 pad34[7];
    u32 f50;
    u32 f54;
    u32 f58;
    u32 pad5c[3];
    u8  count;
    u8  pad69[3];
    struct Ov208Slot slots[10];
};

extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern u32  func_021BD148(struct Ov208ActList *list, u32 heap);
extern int ZKND_TBAR_GetButtonActor(void *mgr, int key);
extern struct Ov208ActSrc data_021C8390[];

void ZUKAN_DETAIL_TOUCHBAR_LoadLeftArrowResources(struct Ov208Scene *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[1];
    void *h;
    u8 i;

    h = func_020490F4(0x55, p->heap);
    p->f50 = CLACT_RegisterPaletteEx(h, 2, 0, 0x160, 2, 3, p->heap);
    p->f54 = CLACT_RegisterCharacter(h, 8, 0, 0, p->heap);
    p->f58 = CLACT_RegisterCellAnim(h, 0xc, 0x13, p->heap);
    ARC_TOOL_DeleteHandle(h);
    p->count = 1;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C8390[i];
    for (i = 0; i < p->count; i++) {
        descs[i].f0 = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].h8 = p->slots[i].src->h8;
    }
    MI_CpuFill8(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 1;
    list.f8 = p->f28;
    list.fc = 1;
    list.f10 = 0xd;
    list.f14 = 8;
    list.f18 = 2;
    p->mgr = func_021BD148(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = ZKND_TBAR_GetButtonActor((void *)p->mgr, p->slots[i].src->id);
}
