/*
 * function: ITEMMENU_TaskUseNoticeMessage
 * address:  0x021B7640
 * packet:   pkt_ov070_021B7640
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02021350  0x02021350  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   ITEMMENU_ShowMessage  0x021BACF0  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskStartRegisterResult  0x021B761C  thumb  ov070
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Obj {
    unsigned char pad000[0x51C];
    void *f51C;
    unsigned char pad520[0x528 - 0x520];
    unsigned int f528;
    unsigned char pad52C[0x84C - 0x52C];
    unsigned int f84C;
} Obj;

extern u8 func_02021350(u16 id);
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void ITEMMENU_ShowMessage(int p, int mode);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskStartRegisterResult(int p);

void ITEMMENU_TaskUseNoticeMessage(Obj *o)
{
    if (func_02021350(o->f84C) == 0xFF)
        MSGDATA_ReadString(o->f51C, 0x3C, (void *)o->f528);
    else
        MSGDATA_ReadString(o->f51C, 0x3D, (void *)o->f528);
    ITEMMENU_ShowMessage((int)o, 1);
    ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskStartRegisterResult));
}
