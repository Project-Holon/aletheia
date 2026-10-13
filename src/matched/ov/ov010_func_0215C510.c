/*
 * function: SCRCMD_PROC_AddMonToParty
 * address:  0x0215C510
 * packet:   pkt_ov010_0215C510
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCapacity  0x0201AA14  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   SCRCMD_PROC_CreateMonFromSpec  0x0215C40C  thumb  ov010
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
struct Blk37;
struct Party;
struct PartyMon;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetCapacity(void *p);
extern u32 POKEPARTY_GetCount(void *p);
struct Spec;
extern void *SCRCMD_PROC_CreateMonFromSpec(void *a, struct Spec *s);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern void *func_0200CA1C(void *a);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern u32 func_020307B0(void *p);

int SCRCMD_PROC_AddMonToParty(void *a, void *b)
{
    void *r6;
    void *r5;

    r6 = GAME_DATA_GetMyParty(a);
    if ((int)POKEPARTY_GetCapacity(r6) <= (int)POKEPARTY_GetCount(r6))
        return 0;
    r5 = SCRCMD_PROC_CreateMonFromSpec(a, b);
    POKEPARTY_Add(r6, r5);
    func_0200CDE0(func_0200CA1C(a), r5);
    func_020307B0(r5);
    return 1;
}
