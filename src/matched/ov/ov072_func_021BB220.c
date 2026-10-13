/*
 * function: TOWNMAP_DrawSelection
 * address:  0x021BB220
 * packet:   pkt_ov072_021BB220
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the centred x assigned back to the s16 local before the call
 * (`cx = cx - hw;`), which truncates it ahead of the argument loads;
 * passing `cx - hw` inline schedules the p[1]/p[2] loads first.
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   TOWNMAP_TownGetField  0x021BA774  thumb  ov072
 *   func_02013E4C  0x02013E4C  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_02045738  0x02045738  arm
 *   func_0201D304  0x0201D304  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   TOWNMAP_TownIsRevealed  0x021BA834  thumb  ov072
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

typedef struct W W;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct StrObj;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern int TOWNMAP_TownGetField(char *p, int i);
extern u32 func_02013E4C(u32 id);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern int TOWNMAP_TownIsRevealed(char *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void TOWNMAP_DrawSelection(u32 *p, W *w)
{
    u32 win;
    s16 cx;
    s16 hw;
    u16 id;
    u32 h;

    win = (u32)func_02045770((struct Descriptor *)p[0]);
    BMP_Clear((struct CharBuf *)win, 0);
    if (w != 0) {
        MSGDATA_ReadString((struct MsgBank *)p[3], func_02013E4C((u16)TOWNMAP_TownGetField((char *)w, 0)), (void *)p[1]);
        cx = ((u32)func_02045738((struct Descriptor *)p[0]) << 3) / 2;
        hw = func_0201D304((struct StrObj *)p[1], p[2], 0) >> 1;
        cx = cx - hw;
        PRINTSYS_Print((void *)win, cx, 0x30, (void *)p[1], (void *)p[2]);
        id = TOWNMAP_TownGetField((char *)w, 0x11);
        if (id != 0xFFFF) {
            MSGDATA_ReadString((struct MsgBank *)p[4], id, (void *)p[1]);
            PRINTSYS_Print((void *)win, 0x1c, 0x50, (void *)p[1], (void *)p[2]);
        }
        if (TOWNMAP_TownIsRevealed((char *)w)) {
            id = TOWNMAP_TownGetField((char *)w, 0x12);
            if (id != 0xFFFF) {
                MSGDATA_ReadString((struct MsgBank *)p[4], id, (void *)p[1]);
                PRINTSYS_Print((void *)win, 0x10, 0x80, (void *)p[1], (void *)p[2]);
            }
            id = TOWNMAP_TownGetField((char *)w, 0x13);
            if (id != 0xFFFF) {
                MSGDATA_ReadString((struct MsgBank *)p[4], id, (void *)p[1]);
                PRINTSYS_Print((void *)win, 0x10, 0x90, (void *)p[1], (void *)p[2]);
            }
            id = TOWNMAP_TownGetField((char *)w, 0x14);
            if (id != 0xFFFF) {
                MSGDATA_ReadString((struct MsgBank *)p[4], id, (void *)p[1]);
                PRINTSYS_Print((void *)win, 0x10, 0xa0, (void *)p[1], (void *)p[2]);
            }
            id = TOWNMAP_TownGetField((char *)w, 0x15);
            if (id != 0xFFFF) {
                MSGDATA_ReadString((struct MsgBank *)p[4], id, (void *)p[1]);
                PRINTSYS_Print((void *)win, 0x88, 0x80, (void *)p[1], (void *)p[2]);
            }
            id = TOWNMAP_TownGetField((char *)w, 0x16);
            if (id != 0xFFFF) {
                MSGDATA_ReadString((struct MsgBank *)p[4], id, (void *)p[1]);
                PRINTSYS_Print((void *)win, 0x88, 0x90, (void *)p[1], (void *)p[2]);
            }
            id = TOWNMAP_TownGetField((char *)w, 0x17);
            if (id != 0xFFFF) {
                MSGDATA_ReadString((struct MsgBank *)p[4], id, (void *)p[1]);
                PRINTSYS_Print((void *)win, 0x88, 0xa0, (void *)p[1], (void *)p[2]);
            }
        }
    }
    h = p[0];
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    func_02041B6C(func_02045730((struct Descriptor *)h));
}
