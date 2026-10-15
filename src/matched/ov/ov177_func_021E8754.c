/*
 * function: func_021E8754
 * address:  0x021E8754
 * packet:   pkt_ov177_021E8754
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note 2026-10-02: all code matches except the case 2 arm: original ends it with an
 *   explicit `b` onto the immediately following case 0 block (+2 bytes, 238 vs 240).
 *   Fallthrough case 2 -> case 0 emits no such branch. Tried default arm, goto, guarded if.
 *
 * note 2026-10-05: orig layout is dispatch (cmp 0 beq A; cmp 1 beq B; cmp 2 bne end), case 2 block,
 * `b .+2` (0xE7FF), case 0 block A, case 1 block B, join store. Tried: if/else chain with `goto L0` into A (240 B
 * but A laid out first, wrong order); switch with case 2 first and `goto L0` before `case 0: L0:` (the
 * goto to the next label is deleted, 236 B); case 0 body under `if (mode == 0 || mode == 2)` (244 B).
 * None emits the branch to the next instruction. Still DIFF (residue is the 2-byte branch plus shifted offsets).
 *
 * note 2026-10-05 (wD9 lane20): EXACT. Case 2 repeats the whole case 0 body and its own break; cross-jumping
 *   then replaces that copy with a branch to the case 0 block, which is laid out next (the `b .+2`).
 *
 * symbols:
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   func_021E8848  0x021E8848  thumb  ov177
 *   func_020056BC  0x020056BC  thumb
 *   TIME_ICON_Create  0x0202EE30  thumb
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 *   func_02034714  0x02034714  arm
 *   PRINTSYS_CTRL_Init  0x02028470  thumb
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   d_021E8DEC     0x021E8DEC  data
 */

typedef struct {
    int            f0;
    int            f4;
    int            f8;
    int            fc;
    int            f10;
    int            f14;
    int            f18;
    unsigned short f1c;
    unsigned short f1e;
    int            f20;
    unsigned char  f24;
    char           pad0[3];
    int            f28;
    int            f2c;
    int            f30;
    int            f34;
    char           f38[1];
} S;

extern unsigned char d_021E8DEC[];

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct PrintSys;
struct Rec3;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern int APP_KEYCURSOR_Delete(int a0);
extern void func_021E8848(S *);
extern u32 func_020056BC(void);
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void PRINTSYS_CTRL_Init(u8 *p, u32 v);
extern int  APP_KEYCURSOR_CreateDefault(int, int, int, int);
extern signed char MSG_SPEED_GetWait(void);
extern int  PRINTSYS_PrintStream(int, int, int, int, int, int, int, int, int, int);

void func_021E8754(S *p, int mode)
{
    int q;

    PRINTSYS_QUE_Clear((struct PrintSys *)p->f28);
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)p->f14), (unsigned char)p->f1c);
    if (p->f8 != 0) {
        PRINTSYS_PrintStreamDelete((struct Rec3 *)p->f8);
        p->f8 = 0;
    }
    if (p->f34 != 0) {
        APP_KEYCURSOR_Delete(p->f34);
        p->f34 = 0;
    }
    func_021E8848(p);
    switch (mode) {
    case 2:
        p->f10 = (int)TIME_ICON_Create((void *)func_020056BC(), (void *)p->f14, (unsigned char)p->f1c, 0x10, p->f1e);
        q = p->f28;
        PRINTSYS_PrintQue((struct PrintSys *)q, (u32)BMP_WIN_GetBmp((struct Descriptor *)p->f20), 0, 0, (void *)p->f18, p->f4);
        p->f24 = 1;
        p->f2c = 0;
        break;
    case 0:
        q = p->f28;
        PRINTSYS_PrintQue((struct PrintSys *)q, (u32)BMP_WIN_GetBmp((struct Descriptor *)p->f20), 0, 0, (void *)p->f18, p->f4);
        p->f24 = 1;
        p->f2c = 0;
        break;
    case 1:
        if (p->f34 != 0) {
            func_02034714((const char *)d_021E8DEC, 0, (const char *)d_021E8DEC);
        }
        PRINTSYS_CTRL_Init((u8 *)p->f38, 2);
        p->f34 = APP_KEYCURSOR_CreateDefault(p->f1c, 1, 0, p->f1e);
        p->f8 = PRINTSYS_PrintStream(p->f14, 0, 0, p->f18, p->f4, MSG_SPEED_GetWait(), p->fc, 0, p->f1e, p->f1c);
        p->f2c = 1;
        break;
    }
    p->f30 = 0;
}
