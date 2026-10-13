/*
 * file:     btlv_scd.c
 * unit:     yes
 * function: BTLV_SCD_Create
 * address:  0x06899AF0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   func_02030734  0x02030734  arm
 *   STRBUF_Create  0x020457B0  arm
 *   func_021B9AF8  0x021B9AF8  thumb
 *   func_021D3D70  0x021D3D70  thumb
 *   func_06899E2C  0x06899E2C  thumb  ov095
 *   g_0689E7B8     0x0689E7B8  data    ov095  a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

/* Auxiliary battle view (0xb4 bytes), created once by BTLV_CORE_Create. */
typedef struct BtlvAuxView {
    u8 pad00[8];
    int fontMain;                   /* 0x08 */
    int msgBuffer;                  /* 0x0c, STRBUF of 0x80 characters */
    int netCtx;                     /* 0x10 */
    int printQueue;                 /* 0x14 */
    u8 pad18[0x74 - 0x18];          /* 0x20: four-entry slot table (func_06899E2C clears it) */
    int slotCursor;                 /* 0x74 */
    u8 pad78[0x8f - 0x78];
    u8 stateFlag;                   /* 0x8f */
    u8 viewParam;                   /* 0x90, "param" argument of BTLV_CORE_Create */
    u8 modeFlag;                    /* 0x91 */
    union {
        u8 raw;
        struct {
            u8 mode : 7;
            u8 busy : 1;
        } bits;
    } status;                       /* 0x92 */
    u8 pad93[0x9c - 0x93];
    int core;                       /* 0x9c, owning BtlvCore */
    int mainWork;                   /* 0xa0 */
    int mainRegion;                 /* 0xa4 */
    int clientView;                 /* 0xa8, client data of the local client */
    u16 heapId;                     /* 0xac */
} BtlvAuxView;

extern BtlvAuxView *func_02030734(u16 heapId, int size, int clear, u8 *site, int tag);
extern int func_021D3D70(void);
extern int func_021B9AF8(int mainRegion, int clientIndex);
extern int STRBUF_Create(int size, u16 heapId);
extern int PRINTSYS_QUE_Create(u16 heapId);
extern void func_06899E2C(unsigned char *p);
BtlvAuxView *BTLV_SCD_Create(int core, int mainWork, int mainRegion, int taskList, int fontMain, int netCtx, int viewParam, u16 heapId);
extern u8 g_0689E7B8[];


BtlvAuxView *BTLV_SCD_Create(int core, int mainWork, int mainRegion, int taskList, int fontMain, int netCtx, int viewParam, u16 heapId)
{
    BtlvAuxView *view;

    view = func_02030734(heapId, 0xb4, 1, g_0689E7B8, 0xc8);
    view->core = core;
    view->mainWork = mainWork;
    view->mainRegion = mainRegion;
    view->heapId = heapId;
    view->fontMain = fontMain;
    view->netCtx = netCtx;
    view->clientView = func_021B9AF8(mainRegion, func_021D3D70());
    view->msgBuffer = STRBUF_Create(0x80, heapId);
    view->slotCursor = 0;
    view->viewParam = viewParam;
    view->modeFlag = 0;
    view->status.bits.mode = 0;
    view->status.bits.busy = 0;
    view->stateFlag = 0;
    view->printQueue = PRINTSYS_QUE_Create(view->heapId);
    func_06899E2C((unsigned char *)view);
    return view;
}
