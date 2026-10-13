/*
 * function: SCRCMD_SYMBOL_ApplyLinkRecord
 * address:  0x0216AC40
 * packet:   pkt_ov010_0216AC40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SYMBOL_MAP_CreateLinkRecord  0x021664CC  thumb  ov010
 *   INTRUDE_FIELD_SpawnSymbolMons  0x0217C37C  thumb  ov018
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 lo : 6;
    u32 mid : 12;
    u32 hi : 6;
    u32 rest : 8;
} Bits;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
struct LinkRecord;
extern struct LinkRecord *SYMBOL_MAP_CreateLinkRecord(u16 heap, void *sys, u32 *start);
extern void INTRUDE_FIELD_SpawnSymbolMons();
extern u32 func_020307B0(void *p);

int SCRCMD_SYMBOL_ApplyLinkRecord(int a0, int a1)
{
    void *w;
    void *h;
    u8 *e;
    int key;

    w = SCRCMD_WORK_GetGameSystem((void *)a1);
    h = GAMESYSTEM_GetFieldMap((void *)w);
    GAMESYSTEM_GetGameComm(w);
    e = (u8 *)SYMBOL_MAP_CreateLinkRecord(SCRCMD_WORK_GetHeapId((void *)a1), w, (u32 *)(&key));
    if (e != 0) {
        INTRUDE_FIELD_SpawnSymbolMons(h, key, e, ((Bits *)(e + 0x50))->lo, ((Bits *)(e + 0x50))->hi);
        func_020307B0(e);
    }
    return 0;
}
