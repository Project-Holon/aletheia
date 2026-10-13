/*
 * function: SCRCMD_PROC_GetPartyMember
 * address:  0x0215B4AC
 * packet:   pkt_0215B4AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);

int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2)
{
    int t4;
    u32 t5;
    void **t6;
    int n;
    void *p;
    void *v0;
    void *v1;

t5 = a1 + 0;
t6 = a2;
    v0 = SCRCMD_WORK_GetGameData(a0);
loc_0215B4B6:
    v1 = GAME_DATA_GetMyParty(v0);
loc_0215B4BA:
    n = func_0201AA18(v1);
loc_0215B4C0:
    if (t5 >= (unsigned)n) goto loc_0215B4C8;
loc_0215B4C4:
t4 = 1;
    goto loc_0215B4CC;
loc_0215B4C8:
t4 = 0;
t5 = 0;
loc_0215B4CC:
    p = func_0201AB28(v1, t5);
loc_0215B4D4:
*t6 = p;
    return t4;}
