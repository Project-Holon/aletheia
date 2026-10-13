/*
 * function: GPOWER_EVENT_ListMain
 * address: 0x021F54CC
 * packet: pkt_ov083_021F54CC
 * region: ov083
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note 2026-10-05 (wave P22 lane 10): extent is 160 B (158 B code plus the
 *   trailing nop pad). Bytes equal to the listing in c99 and c. Only the two
 *   FIELD_MSGBG_ClearInfoMsgWin relocations lack a witness: filed the 12-byte ov021 leaf as
 *   src/matched/ov/ov021_func_02190854.c (EXACT). The lane tool does not see it
 *   until the integrator refreshes the manifest; then this should read EXACT.
 *   Callee arity: matched FIELD_MSGBG_DeleteInfoMsgWin is int(u32,u32,u32,u32) and
 *   FIELD_MSGBG_ClearMsgPrint is int(u32,u32,u32,u32), but their callers pass one argument
 *   (r1-r3 are clobbered by FIELD_MSGBG_ClearInfoMsgWin). Declared here with one parameter.
 *   Older draft (docs/notes/pkt_ov083_021F54CC.c.txt) had the same body; its
 *   blocker was the 4-parameter definition conflict.
 * symbols:
 *   FIELD_MSGBG_CreateInfoSysWin 0x02190FA0 thumb ov021
 *   FIELD_MSGBG_InfoSysWinPrintMsg 0x0219103C thumb ov021
 *   FIELD_MSGBG_InfoSysWinMain 0x021910C0 thumb ov021
 *   FIELD_MSGBG_DeleteInfoSysWin 0x02191008 thumb ov021
 *   FIELD_MSGBG_CreateInfoMsgWin 0x021907C4 thumb ov021
 *   FIELD_MSGBG_ClearInfoMsgWin 0x02190854 thumb ov021
 *   FIELD_MSGBG_DeleteInfoMsgWin 0x0219082C thumb ov021
 *   GPOWER_EVENT_PrintPowerList 0x021F55D4 thumb ov083
 *   GPOWER_EVENT_FreeListWork 0x021F5400 thumb ov083
 *   KEY_GetTrg 0x020362DC arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Fx;
struct Obj;
struct Obj2;
extern struct Obj2 *FIELD_MSGBG_CreateInfoSysWin(struct Fx *a, u32 b, u32 c);
extern void FIELD_MSGBG_InfoSysWinPrintMsg(u32 *, u32, u32, u32);
extern u32 FIELD_MSGBG_InfoSysWinMain(u32 *);
extern int FIELD_MSGBG_DeleteInfoSysWin(u32 a);
extern struct Obj *FIELD_MSGBG_CreateInfoMsgWin(struct Fx *a, u32 b, u32 c, u32 d, u16 e, u16 f);
extern void FIELD_MSGBG_ClearInfoMsgWin(u32 *p);
extern int FIELD_MSGBG_DeleteInfoMsgWin(void *a);
extern void GPOWER_EVENT_PrintPowerList(char *);
extern void GPOWER_EVENT_FreeListWork(u8 *);
extern u32 KEY_GetTrg(void);
int GPOWER_EVENT_ListMain(void *task, u32 *st, u8 *p) {
    void *v;
    switch (*st) {
    case 0:
        v = FIELD_MSGBG_CreateInfoSysWin(*(struct Fx **)(p+20),*(u32 *)(p+40),19);
        *(void **)(p+32) = v;
        FIELD_MSGBG_InfoSysWinPrintMsg(v,0,0,3);
        *st += 1;
        break;
    case 1:
        if (FIELD_MSGBG_InfoSysWinMain(*(u32 **)(p+32))) {
            FIELD_MSGBG_DeleteInfoSysWin((u32)(*(void **)(p+32)));
            *st += 1;
        }
        break;
    case 2:
        v = FIELD_MSGBG_CreateInfoMsgWin(*(struct Fx **)(p+20),*(u32 *)(p+40),4,1,24,22);
        *(void **)(p+24) = v;
        FIELD_MSGBG_ClearInfoMsgWin(v);
        GPOWER_EVENT_PrintPowerList((char *)p);
        *st += 1;
        break;
    case 3:
        if (KEY_GetTrg() & 3) *st += 1;
        break;
    default:
        FIELD_MSGBG_ClearInfoMsgWin(*(void **)(p+24));
        FIELD_MSGBG_DeleteInfoMsgWin((void *)(*(void **)(p+24)));
        GPOWER_EVENT_FreeListWork(p);
        return 1;
    }
    return 0;
}
