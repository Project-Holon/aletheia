/*
 * function: COMM_ENTRY_MENU_Create
 * address:  0x021CD48C
 * packet:   pkt_ov021_021CD48C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb  ov021
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   MYSTATUS_Copy  0x02008494  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   COMM_ENTRY_StartNetCommands  0x021CF164  thumb  ov021
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_GetUserArg  0x0203D650  arm
 *   d_021DE5E8     0x021DE5E8  data   ov021  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2C;
    u8 f30[0x51B - 0x30];
    u8 f51B;
    u8 f51C;
    u8 f51D;
    u8 f51E;
    u8 f51F;
    u8 f520;
    u8 pad521[0x528 - 0x521];
    u16 f528;
    u8 pad52A[0x554 - 0x52A];
    u8 f554[0x572 - 0x554];
    signed char f572;
    u8 pad573;
    u16 f574;
    u8 pad576[0x580 - 0x576];
} Work;

typedef struct {
    u8 pad[0x26];
    u16 f26;
} Disp;

typedef struct {
    u8 pad[0x18];
    Disp *(*f18)(u32 a);
} Sys;

struct MsgBank;
struct U16Vec;
struct WordSet;
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern void *func_02030734(u32 heap, u32 size, int a, const char *file, u16 line);
extern struct WordSet *func_0201EC64(u32 heap);
extern int FIELD_MSGBG_CreateMsgData(u32 a, u32 b);
struct Fx;
struct Obj2;
extern struct Obj2 *FIELD_MSGBG_CreateBottomSysWin(struct Fx *a, u32 b);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void MYSTATUS_Copy(void *src, void *dst);
extern void MI_CpuCopy8(void *src, void *dst, u32 n);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void COMM_ENTRY_StartNetCommands(u32 a);
extern void *GFL_NET_GetInitParam(void);
extern u32 GFL_NET_GetUserArg(void);
extern u8 d_021DE5E8[];

Work *COMM_ENTRY_MENU_Create(u32 a0, u32 a1, u32 a2, u32 a3, u32 heap, u32 a5, u32 a6, void *a7)
{
    u32 t;
    Work *w;
    Sys *s;

    t = FIELDMAP_GetMsgBg((u8 *)a1);
    w = func_02030734(heap, 0x580, 1, (const char *)d_021DE5E8, 0x179);
    w->f4 = (u32)func_0201EC64(heap);
    w->f8 = FIELD_MSGBG_CreateMsgData(t, 0x1e);
    w->f14 = (u32)FIELD_MSGBG_CreateBottomSysWin((struct Fx *)t, w->f8);
    w->f18 = (u32)STRBUF_Create(0x64, heap);
    w->f1C = (u32)func_02045EC0((struct MsgBank *)w->f8, 7);
    w->f20 = (u32)STRBUF_Create(0x40, heap);
    if (a6 == 1) {
        w->f24 = (u32)func_02045EC0((struct MsgBank *)w->f8, 3);
    } else {
        w->f24 = (u32)func_02045EC0((struct MsgBank *)w->f8, 2);
    }
    w->f28 = (u32)STRBUF_Create(0x20, heap);
    w->f51C = a2;
    w->f51D = a3;
    w->f0 = a1;
    w->f51F = a5;
    w->f520 = a6;
    w->f528 = heap;
    w->f572 = -1;
    w->f574 = 0xffff;
    MYSTATUS_Copy((void *)a0, w->f30);
    if (a7 != 0) {
        MI_CpuCopy8(a7, w->f554, 6);
    }
    GFL_NET_SetLoginOption(0);
    COMM_ENTRY_StartNetCommands((u32)w);
    if (a6 == 1) {
        w->f51B = 1;
    }
    s = GFL_NET_GetInitParam();
    s->f18(GFL_NET_GetUserArg())->f26 = 0x3a0b;
    return w;
}
