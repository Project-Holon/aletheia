/*
 * function: LOCAL_TVT_SYS_ApplyStep
 * address: 0x021B6AF8
 * packet: pkt_ov174_021B6AF8
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Write the table element access twice (tbl[idx].b and tbl[idx].c) with no element pointer local; the index shift then schedules before the table load.
 * symbols:
 *   LOCAL_TVT_SYS_PositionActor 0x021B6704 thumb ov174
 *   LOCAL_TVT_SYS_CreateTextWindow 0x021B68F8 thumb ov174
 *   LOCAL_TVT_SYS_PrintMessage 0x021B6A04 thumb ov174
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct E { u8 a, b; u16 c; };
struct P { u8 pad0[0x40]; struct E *tbl; u8 pad1[0x89 - 0x44]; u8 idx; };
extern void LOCAL_TVT_SYS_PositionActor(u8 *p, int index);
extern void LOCAL_TVT_SYS_CreateTextWindow(u8 *p, int a);
extern void LOCAL_TVT_SYS_PrintMessage(u8 *p, int a);
struct WordSet;
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u8 *GAME_DATA_GetMyStatus(void *p);
void LOCAL_TVT_SYS_ApplyStep(u8 *p)
{
    u32 a = ((struct P *)p)->tbl[((struct P *)p)->idx].b;
    u32 b = (u8)((struct P *)p)->tbl[((struct P *)p)->idx].c;
    p[0x88] = a;
    LOCAL_TVT_SYS_PositionActor(p, a);
    if (a < 2) {
        LOCAL_TVT_SYS_CreateTextWindow(p, 1);
    } else {
        LOCAL_TVT_SYS_CreateTextWindow(p, 0);
    }
    if (*(void **)(p + 0x74) != 0) {
        WORDSET_DeleteStrbufED04(*(void **)(p + 0x74));
    }
    *(void **)(p + 0x74) = GF_FONT_Create_EC64(*(u16 *)p);
    func_0201F02C(*(void **)(p + 0x74), 0, GAME_DATA_GetMyStatus(*(void **)(*(u8 **)(p + 0x30) + 4)));
    LOCAL_TVT_SYS_PrintMessage(p, b);
}
