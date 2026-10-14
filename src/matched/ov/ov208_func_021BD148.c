/*
 * function: ZKND_TBAR_CreateButtonList
 * address:  0x021BD148
 * packet:   pkt_ov208_021BD148
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021BD634 takes its last parameter as u16 and narrows it in its own body;
 * the extern here says u32 because the image passes heap without narrowing it.
 * objChannel starts at 1 after the header stores so it shares their constant.
 *
 * symbols:
 *   func_02030734        0x02030734  arm
 *   MI_CpuFill8        0x02082BCC  arm
 *   ZKND_TBAR_LoadButtonResources  0x021BD444  thumb
 *   func_021BD634        0x021BD634  thumb
 *   data_021C8DD8        0x021C8DD8  data
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
    u32 owner;
    u32 channel;
    u32 pal;
    u32 objPal;
    u32 kind;
    u32 skip;
};

struct Ov208Bg {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
};

struct Ov208ActObj {
    u8 raw[0x38];
};

struct Ov208ActSet {
    u32 f0;
    u32 count;
    u32 f8;
    u32 fc;
    u32 f10;
    struct Ov208Bg bg;
    struct Ov208ActObj objs[1];
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern void ZKND_TBAR_LoadButtonResources(struct Ov208Bg *p, u32 channel, u32 objChannel, u32 palOfs,
                                u32 kind, u8 pal, u8 objPal, u32 skip, u32 heap);
extern void func_021BD634(struct Ov208ActObj *p, u32 owner, struct Ov208Bg *res,
                          struct Ov208ActDesc *desc, u32 prio, u32 mode);
extern const char data_021C8DD8[];

struct Ov208ActSet *ZKND_TBAR_CreateButtonList(struct Ov208ActList *list, u32 heap)
{
    struct Ov208ActSet *set;
    u32 size;
    u32 objChannel;
    u32 palOfs;
    u32 i;

    palOfs = 0;
    size = list->count * sizeof(struct Ov208ActObj) + 0x28;
    set = func_02030734(heap, size, 0, data_021C8DD8, 0x107);
    MI_CpuFill8(set, 0, size);
    set->count = list->count;
    set->f8 = 0;
    set->fc = 1;
    set->f10 = 0;
    objChannel = 1;
    if (list->channel >= 4)
        palOfs = 4;
    else
        objChannel = 0;
    ZKND_TBAR_LoadButtonResources(&set->bg, (u8)list->channel, objChannel, palOfs, list->kind,
                        (u8)list->pal, (u8)list->objPal, list->skip, heap);
    for (i = 0; i < set->count; i++)
        func_021BD634(&set->objs[i], list->owner, &set->bg, &list->descs[i], objChannel, heap);
    return set;
}
