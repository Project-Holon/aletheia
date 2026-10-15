/*
 * function: B_PLIST_MAIN_WaitPrintStream
 * address:  0x022102BC
 * packet:   pkt_022102BC
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetCont  0x0203630C  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   B_PLIST_MAIN_PlaySe2  0x02211984  thumb  ov198
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 */

typedef unsigned int u32;

struct S {
    unsigned char pad[0x1eb0];
    int f1eb0;
    int f1eb4;
};

typedef signed int     s32;
typedef unsigned char  u8;
struct Rec;
struct Rec3;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void PRINTSYS_PrintStreamReleasePause(void *p);
extern int TOUCHPANEL_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern void B_PLIST_MAIN_PlaySe2(u8 **p, u32 b);

int B_PLIST_MAIN_WaitPrintStream(struct S *a)
{
    switch (PRINTSYS_PrintStreamGetState((void *)a->f1eb0)) {
    case 0:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetCont() & 3) != 0)
            PRINTSYS_PrintStreamShortWait((struct Rec *)a->f1eb0, 0);
        a->f1eb4 = 0;
        break;
    case 1:
        if (a->f1eb4 != 0)
            break;
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0) {
            B_PLIST_MAIN_PlaySe2((u8 **)a, 0x547);
            PRINTSYS_PrintStreamReleasePause((void *)a->f1eb0);
            a->f1eb4 = 1;
        }
        break;
    case 2:
        PRINTSYS_PrintStreamDelete((struct Rec3 *)a->f1eb0);
        a->f1eb0 = 0;
        a->f1eb4 = 0;
        return 0x18;
    }
    return 0x17;
}
