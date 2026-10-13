/*
 * function: INTRUDE_SUBDISP_PrintTitle
 * address:  0x0217E638
 * packet:   pkt_ov018_0217E638
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   GAME_DATA_GetPlayerStatus  0x02012950  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 */

typedef unsigned char u8;

typedef struct {
    int f00;
    u8 pad04[0x1C - 0x04];
    int f1C;
    u8 pad20[0x24 - 0x20];
    int f24;
    int f28;
    int f2C;
    u8 pad30[0x38 - 0x30];
    int f38;
    u8 pad3C[0x40 - 0x3C];
    int f40;
    int f44;
    u8 f48;
    u8 pad49[0xD8 - 0x49];
    u8 fD8;
    u8 padD9[0x10C - 0xD9];
    u8 f10C;
} Obj;

typedef unsigned int   u32;
struct BigObj;
struct CharBuf;
struct Ctx;
struct MsgBank;
struct PrintSys;
struct Rec44;
struct Sub24;
struct WordSet;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Descriptor;
void *func_02045770(struct Descriptor *a0);
u32 func_0201C6C4(struct PrintSys *p, void *v);
int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
u8 GAME_DATA_GetExitMode(const struct BigObj *p);
void BMP_Clear(struct CharBuf *buf, u8 value);
void BMP_WIN_TransferChars(struct Descriptor *a0);
struct Rec44 *GAME_DATA_GetPlayerStatus(struct Sub24 *p, u32 i);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
void func_0201F250(struct WordSet *ws, void *dst, void *src);
typedef unsigned short u16;
void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void INTRUDE_SUBDISP_PrintTitle(Obj *p)
{
    int h;
    int anim;
    int mode;
    int v;

    h = (int)GAMESYSTEM_GetGameData((const struct Ctx *)p->f00);
    if (func_0201C6C4((struct PrintSys *)p->f28, (void *)((int)func_02045770((struct Descriptor *)p->f44))) == 1) {
        return;
    }
    if (GAME_DATA_GetIntrudeCount((const struct BigObj *)h) == 1) {
        v = p->fD8;
        if (v == GAME_DATA_GetExitMode((const struct BigObj *)h)) {
            mode = 2;
            anim = 0x43;
        } else {
            mode = v + 3;
            anim = 0x44;
        }
    } else {
        mode = 7;
    }
    if (p->f10C == mode || mode == 0) {
        return;
    }
    p->f10C = mode;
    if (mode == 7) {
        BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)p->f44)), 0);
        BMP_WIN_TransferChars((struct Descriptor *)p->f44);
        return;
    }
    if (mode >= 3 && mode <= 6) {
        func_0201F02C((struct WordSet *)p->f24, 0, GAME_DATA_GetPlayerStatus((struct Sub24 *)h, p->fD8));
    }
    MSGDATA_ReadString((struct MsgBank *)p->f2C, anim, (void *)p->f38);
    func_0201F250((struct WordSet *)p->f24, (void *)p->f40, (void *)p->f38);
    BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)p->f44)), 0);
    v = p->f28;
    PRINTSYS_PrintQueColor((void *)v, (int)func_02045770((struct Descriptor *)p->f44), 0, 0, p->f40, p->f1C, 0x3C40);
    p->f48 = 1;
}
