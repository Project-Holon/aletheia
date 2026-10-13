/*
 * file:     unit_021CD2A4.c
 * unit:     yes
 * function: func_021CD2A4, func_021CD348, func_021CD3A4
 * address:  0x021CD2A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fld_trade_p01.c and fld_trade_p02.c (lane CL125b): no __FILE__ anchor, original unknown: the name-input event (0x50 work, launches overlay 0xC2) called by scrcmd_proc_fld.c and ov032 beacon_view.c.
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012A54  0x02012A54  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0200C1F4  0x0200C1F4  thumb
 *   func_0200C20C  0x0200C20C  thumb
 *   func_02045924  0x02045924  arm
 *   d_021DB44C     0x021DB44C  data  a1
 *   func_020146F8  0x020146F8  thumb
 *   func_02012374  0x02012374  thumb
 *   abs_id_C2      0x000000C2  data
 *   d_021F5580     0x021F5580  data  ov194  a4
 *   func_0200C1F8  0x0200C1F8  thumb
 *   func_02027198  0x02027198  thumb
 *   func_0200C210  0x0200C210  thumb
 *   func_020275C4  0x020275C4  thumb
 *   func_02045838  0x02045838  arm
 *   func_02165844  0x02165844  thumb  ov010
 */
struct U16Vec;
struct Big;
struct BigObj;
struct Blk34;
struct Ctx;
struct Desc;
struct Strbuf;
struct Sub0200852CObj;
struct Evt;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* Parameter block of the name-input process (overlay 0xC2). */
typedef struct NameInParam {
    u32 mode;               /* 0x00 */
    u16 gender;             /* 0x04 */
    u8 pad06[0x18 - 0x06];
    u32 maxLength;          /* 0x18 */
    u32 cancelled;          /* 0x1C */
    struct Strbuf *name;    /* 0x20 */
    u8 pad24[0x28 - 0x24];
    struct Blk34 *nameSave; /* 0x28 */
    u16 heapId;             /* 0x2C */
} NameInParam;

/* Event work (0x50 bytes). */
typedef struct NameInEvent {
    void *gsys;
    void *gameData;
    struct Blk34 *nameSave;         /* 0x08 */
    void *myStatus;                 /* 0x0C */
    void *fieldmap;                 /* 0x10 */
    void *beaconSave;               /* 0x14 */
    u16 *resultVar;                 /* 0x18 */
    NameInParam param;              /* 0x1C */
    u32 mode;                       /* 0x4C */
} NameInEvent;

extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Desc *event);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *sys);
extern u8 *func_02012944(void *p);
extern void *func_02012A54(const struct BigObj *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u16 *func_0200C1F4(struct Blk34 *p);
extern u16 *func_0200C20C(struct Blk34 *p);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_0200C1F8(struct Blk34 *p, const u16 *src);
extern void func_02027198(void);
extern void func_0200C210(struct Blk34 *p, const u16 *src);
extern int func_020275C4(void *p);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern void func_02165844(void *v);

struct Desc *func_021CD2A4(void *gsys, void *fieldmap, void *parentEvent, u32 mode, u16 *resultVar);
int func_021CD348(struct Evt *event, int *seq, NameInEvent *work);
void func_021CD3A4(NameInEvent *work, NameInParam *param);

/* Maximum name length per mode 5..7. */
extern const u8 d_021DB44C[];
extern char d_021F5580;
extern unsigned char abs_id_C2[];

/*
 * Creates the name-input event. Modes 5 and 6 edit one of two names of a
 * save block, mode 7 the beacon message (ov032 beacon_view.c).
 */
struct Desc *func_021CD2A4(void *gsys, void *fieldmap, void *parentEvent, u32 mode, u16 *resultVar)
{
    struct Desc *event;
    NameInEvent *work;

    event = func_020122C0(gsys, parentEvent, func_021CD348, 0x50);
    work = func_020124E8(event);
    work->gsys = gsys;
    work->gameData = func_020120F4(gsys);
    work->fieldmap = fieldmap;
    work->resultVar = resultVar;
    work->mode = mode;
    work->param.heapId = 4;
    work->nameSave = func_0200C0F0(func_02012EBC(work->gameData));
    work->myStatus = func_02012944(work->gameData);
    work->beaconSave = func_02012A54(work->gameData);
    work->param.mode = mode;
    work->param.gender = func_02008550(work->myStatus);
    work->param.nameSave = work->nameSave;
    work->param.maxLength = d_021DB44C[mode - 5];
    work->param.name = (struct Strbuf *)func_020457B0(work->param.maxLength + 1, work->param.heapId);
    switch (mode) {
    case 5:
        func_02045924(work->param.name, func_0200C1F4(work->nameSave));
        break;
    case 6:
        func_02045924(work->param.name, func_0200C20C(work->nameSave));
        break;
    case 7:
        break;
    }
    return event;
}

/*
 * Event: runs the name-input process (overlay 0xC2, abs_id_C2), then stores
 * the result.
 */
int func_021CD348(struct Evt *event, int *seq, NameInEvent *work)
{
    int proc;

    switch (*seq) {
    case 0:
        proc = (int)func_020146F8(work->gsys, (int)work->fieldmap, (int)abs_id_C2, (int)(&d_021F5580), (int)&work->param);
        func_02012374(event, (struct Evt **)proc);
        (*seq)++;
        break;
    case 1:
        func_021CD3A4(work, &work->param);
        func_02045808((struct U16Vec *)work->param.name);
        return 1;
    }
    return 0;
}

/* Writes 1 to the result variable when a name was entered, then stores the name. */
void func_021CD3A4(NameInEvent *work, NameInParam *param)
{
    u16 *resultVar = work->resultVar;

    if (resultVar) {
        if (param->cancelled == 0)
            *resultVar = 1;
        else
            *resultVar = 0;
    }
    if (param->cancelled == 1)
        return;
    switch (work->mode) {
    case 5:
        func_0200C1F8(work->nameSave, (const u16 *)param->name);
        func_02027198();
        return;
    case 6:
        func_0200C210(work->nameSave, (const u16 *)param->name);
        return;
    case 7:
        func_02045838((struct U16Vec *)func_020275C4(work->beaconSave), (struct U16Vec *)work->param.name);
        func_02165844(param->name);
        return;
    }
}
