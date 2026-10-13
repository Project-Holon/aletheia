/*
 * function: BMP_MENU_CreateYesNo
 * address:  0x0201FDA0
 * packet:   pkt_0201FC5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02045B38   0x02045B38  arm
 *   BMP_MENUWORK_Create   0x0201F81C  thumb
 *   BMP_MENUWORK_AddMsgItem   0x0201F878  thumb
 *   MSGDATA_Delete   0x02045C04  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   BMP_WIN_Create   0x020450F0  arm
 *   func_02030734   0x02030734  arm
 *   sBmpMenuFile    0x020A7384  data
 *   GF_FONT_Create   0x0201D7EC  thumb
 *   func_0201DC80   0x0201DC80  thumb
 *   PRINTSYS_QUE_Create   0x0201C440  thumb
 *   BMP_MENU_Add   0x0201F9D0  thumb
 *   BMP_WIN_MakeScreen   0x02045374  arm
 *   func_0201F73C   0x0201F73C  thumb
 *   BMP_WIN_GetBgLayer   0x02045730  arm
 *   func_020409B4   0x020409B4  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *
 * bmp_menu.c: the yes/no menu builder (message archive 2 entry 0xE9, a
 * two-item BmpMenuWork list, a BmpMenuHeader filled on the stack, then
 * BMP_MENU_Add and the window upload).  docs/notes/pkt_0201FC5C.c.txt.
 *
 * THE LEVER (wave 18, lane ties_a; it was DIFF 284/284, 2 bytes out for
 * five waves: the r3 home store `str r3, [sp, #0x14]` scheduled after
 * `ldr r4, [sp, #0x50]` / `adds r5, r0, #0`): the fifth (stack) parameter
 * is a heap id and is u16, with u16 on the heap parameter of every callee
 * it is passed to.  docs/idioms/a-u16-stack-parameter-passed-to-a-u16-
 * callee-stays-behind-a-spill-store.md is the same lever; with u16 heap
 * and the old u32 prototypes the body narrows at every call.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct {
    const void *str;    /* +0x00 */
    u32         param;  /* +0x04 */
} BmpMenuWork;

typedef struct {
    void *cell;         /* +0x00 */
    u8    drawn;        /* +0x04 */
} PrintUtil;

typedef struct {
    BmpMenuWork *items; /* +0x00 */
    void *win;          /* +0x04 */
    u8   font;          /* +0x08 */
    u8   xmax;          /* +0x09  columns */
    u8   ymax;          /* +0x0A  rows    */
    u8   lineSpc : 4;   /* +0x0B */
    u8   cDisp   : 2;
    u8   bf0b6   : 2;
    u16  unk0c;         /* +0x0C */
    u16  unk0e;         /* +0x0E */
    u32  unk10;         /* +0x10 */
    PrintUtil *util;    /* +0x14 */
    void *que;          /* +0x18 */
    void *fontH;        /* +0x1C */
    u32  unk20;         /* +0x20 */
} BmpMenuHeader;

typedef struct {
    BmpMenuHeader hdr;  /* +0x00 */
    void *cursor;       /* +0x24 */
    u32 cancel;         /* +0x28 */
    u8  pad2c;
    u8  pos;            /* +0x2D */
    u8  width;          /* +0x2E */
    u8  px;             /* +0x2F */
    u8  py;             /* +0x30 */
    u8  xspc;           /* +0x31 */
    u8  yspc;           /* +0x32 */
    u8  lastDir;        /* +0x33 */
    u16 heap;           /* +0x34 */
    u16 pad36;
} BmpMenu;

extern char  sBmpMenuFile[];
struct Cfg;
struct Descriptor;
struct Font;
struct GfFont;
struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern BmpMenuWork *BMP_MENUWORK_Create(u32 n, u16 heap);
struct Slot;
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201DC80(struct Font *p);
extern u32 PRINTSYS_QUE_Create(void *p);
extern BmpMenu *BMP_MENU_Add(const BmpMenuHeader *hdr, u32 px, u32 py, u32 pos, u16 heap, u32 cancel);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void  func_020409B4(u32 layer);
extern void BMP_WIN_TransferChars(struct Descriptor *d);

static inline void PrintUtil_Init(PrintUtil *util, void *cell)
{
    util->cell = cell;
    util->drawn = 0;
}

typedef struct {
    u8  frame;   /* +0 */
    u8  x;       /* +1 */
    u8  y;       /* +2 */
    u8  pal;     /* +3 */
    u16 chr;     /* +4  callers pass it as base */
} WinDat;

BmpMenu *BMP_MENU_CreateYesNo(const WinDat *winDat, u16 base, u8 pal, u8 pos, u16 heap)
{
    BmpMenuHeader hdr;
    void *msg;
    BmpMenuWork *list;
    BmpMenu *m;

    msg = func_02045B38(0, 2, 0xE9, heap);
    list = BMP_MENUWORK_Create(2, heap);
    BMP_MENUWORK_AddMsgItem((struct Slot *)list, (u32)msg, 0, 0, heap);
    BMP_MENUWORK_AddMsgItem((struct Slot *)list, (u32)msg, 1, -2, heap);
    MSGDATA_Delete(msg);

    MI_CpuFill8(&hdr, 0, sizeof(hdr));
    hdr.items = list;
    hdr.win = (void *)BMP_WIN_Create(winDat->frame, winDat->x, winDat->y, 7, 4, winDat->pal, 1);
    hdr.xmax = 1;
    hdr.ymax = 2;
    hdr.lineSpc = 1;
    hdr.cDisp = 0;
    hdr.bf0b6 = 0;
    hdr.util = func_02030734(heap, sizeof(PrintUtil), 1, sBmpMenuFile, 0x263);
    hdr.fontH = GF_FONT_Create(0x17, 0, 0, 0, heap);
    hdr.unk0e = func_0201DC80(hdr.fontH);
    hdr.unk0c = 10;
    PrintUtil_Init(hdr.util, hdr.win);
    hdr.que = (void *)PRINTSYS_QUE_Create((void *)heap);
    hdr.unk20 = 0;

    m = BMP_MENU_Add(&hdr, 0xE, 0, pos, heap, 2);
    BMP_WIN_MakeScreen(hdr.win);
    func_0201F73C(hdr.win, 0, base, pal);
    func_020409B4(BMP_WIN_GetBgLayer(hdr.win));
    BMP_WIN_TransferChars(hdr.win);
    return m;
}
