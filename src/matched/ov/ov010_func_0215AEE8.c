/*
 * function: SCRCMD_WORK_CmdRegisterZukanSeen
 * address:  0x0215AEE8
 * packet:   pkt_ov010_0215AEE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *func_0200CA1C(void *a);
extern void *POKE_TOOL_Create(u32 species, u32 level, u64 id, u32 heap);
struct Blk37;
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern u32 func_020307B0(void *p);

int SCRCMD_WORK_CmdRegisterZukanSeen(int a0, int a1)
{
    void *v0;
    int k;
    int m, o;
    void *n;
    v0 = func_0200CA1C((void *)SCRCMD_WORK_GetGameData((void *)a1));
    k = SCRCMD_WORK_GetHeapId((void *)a1);
    m = (int)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    o = (int)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    n = POKE_TOOL_Create(o, 1, 0xFFFFFFFF00000000ULL, k);
    switch (m) {
    case 0:
        func_0200CFA0(v0, n);
        break;
    case 1:
        break;
    }
    func_020307B0(n);
    return 0;
}
