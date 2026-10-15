/*
 * function: func_021BDCB8
 * address: 0x021BDCB8
 * packet: pkt_ov172_021BDCB8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * 2026-10-05 (wave D5 lane 02): real extent of func_021BBA94 is 0x021BBA94..0x021BBE50 (956 bytes, pool 0x404, 0x14A,
 * d_021C7234 at 0x021BBE50). A first full draft is parked as src/pending/ov/ov172_func_021BBA94.c, DIFF, so this stays MATCH*.
 * note (2026-10-05, wD4 lane17): still MATCH*, only func_021BBA94 (ov172, no witness, no matched file) is unresolved; it needs its own ov172 file.
 * note 2026-10-04 wD2 lane01: still MATCH*. The only unresolved site is func_021BBA94 (+006C): its extent is larger than 021BBA94..021BBAD4 (64 bytes shown, stale inner label) and needs its own ov172 witness file. Not in lane 01; a lane that owns 021BBA94 closes this.
 * 2026-10-05 (wD6 lane12): still MATCH*, re-run: 10 of 11 relocations resolve, only func_021BBA94 (+006C) is open.
 *   Its draft src/pending/ov/ov172_func_021BBA94.c is DIFF (not in this lane); this file closes when that one is filed.
 * 2026-10-05 (wD7 lane11): still MATCH*, 10 of 11 resolve; func_021BBA94 (+006C) is in wave D7 lane 03.
 *   This file closes with no change once lane 03 files ov172 021BBA94 EXACT.
 * blocker: func_021BBA94 ov172 lacks an outside witness; larger body
 * extends past stale inner label 021BBAD4. No split frees the only call.
 * Extent remainder: zero alignment halfword at 021BDD6A.
 * symbols:
 *   CTVT_TALK_Exit 0x021B8FB8 thumb ov172
 *   func_021BBE5C 0x021BBE5C thumb ov172
 *   CTVT_DRAW_Exit 0x021BA8C4 thumb ov172
 *   CTVT_TALK_Init 0x021B8CC8 thumb ov172
 *   func_021BBA94 0x021BBA94 thumb ov172
 *   CTVT_DRAW_Init 0x021BA2C4 thumb ov172
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   CTVT_COMM_StopSession 0x021B8084 thumb ov172
 *   CTVT_CAMVIEW_StopCapture 0x021B7578 thumb ov172
 *   CTVT_CAMVIEW_RequestShutterSound1 0x021B7B80 thumb ov172
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern void CTVT_TALK_Exit(void *,char *);
extern void func_021BBE5C(void *,char *);
typedef unsigned short u16;
extern void CTVT_DRAW_Exit(u16 *a0, char *p);
extern void CTVT_TALK_Init(void *,char *);
extern void func_021BBA94(void *a0, u8 *p);
extern void CTVT_DRAW_Init(void *a0, u8 *p);
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 color);
extern void CTVT_COMM_StopSession(void *,char *);
extern void CTVT_CAMVIEW_StopCapture(int x, char *p);
extern void CTVT_CAMVIEW_RequestShutterSound1(int x, char *p);
void func_021BDCB8(u8 *p)
{
    switch (*(u32 *)(p+8)) {
    case 1: CTVT_TALK_Exit(p,*(char **)(p+0x1e8)); break;
    case 2: func_021BBE5C(p,*(char **)(p+0x1f0)); break;
    case 3: CTVT_DRAW_Exit((u16 *)p,*(char **)(p+0x1ec)); break;
    }
    *(u32 *)(p+8)=*(u32 *)(p+12);
    switch (*(u32 *)(p+8)) {
    case 0: break;
    case 1: CTVT_TALK_Init(p,*(char **)(p+0x1e8)); break;
    case 2: func_021BBA94(p,(u8 *)(*(char **)(p+0x1f0))); break;
    case 3: CTVT_DRAW_Init(p,(u8 *)(*(char **)(p+0x1ec))); break;
    case 5:
        WIPE_SetBrightnessFadeOut(0,0);
        WIPE_SetBrightnessFadeOut(1,0);
    case 4:
        CTVT_COMM_StopSession(p,*(char **)(p+0x1e4));
        CTVT_CAMVIEW_StopCapture((int)p,*(char **)(p+0x1e0));
        CTVT_CAMVIEW_RequestShutterSound1((int)p,*(char **)(p+0x1e0));
        break;
    }
}
