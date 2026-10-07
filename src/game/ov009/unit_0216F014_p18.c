/*
 * file:     unit_0216F014_p18.c
 * unit:     yes
 * function: func_02173B18, func_02173B74, func_02173BE4, func_02173C84
 * address:  0x02173B18
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021AAA40  0x021AAA40  data
 *   DWC_Free  0x0205A1B0  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02168FF0  0x02168FF0  arm  ov009
 *   func_0219E120  0x0219E120  arm  ov009
 *   g_021A21A4     0x021A21A4  data
 *   g_021A21B0     0x021A21B0  data
 *   g_021A2170     0x021A2170  data
 *   g_021A2164     0x021A2164  data
 *   g_021A20A4     0x021A20A4  data
 *   func_021763AC  0x021763AC  arm  ov009
 */
struct SBServer;
typedef struct {
    int key;
    void *value;
    int type;
} MatchKey;

extern void DWC_Free(int kind, void *p, int size);
extern void MIi_CpuClear32(int v, void *p, int size);
extern char *func_02175F3C(void);
extern int func_02168FF0(int idx);
extern int func_0219E120(struct SBServer *server, char *key, int idefault);
extern unsigned char *func_021763AC(void);
void func_02173B18(void);
int func_02173B74(int profileID);
int func_02173BE4(void *server);
int func_02173C84(void);
extern MatchKey g_021AAA40[];
extern char g_021A21A4[];
extern char g_021A21B0[];
extern char g_021A2170[];
extern char g_021A2164[];
extern char g_021A20A4[];


/*
 * DWCi_ClearGameMatchKeys: frees every game match key value and clears the key table.
 */
void func_02173B18(void)
{
    int i;

    for (i = 0; i < 0x9a; i++) {
        if (g_021AAA40[i].value != 0) {
            DWC_Free(4, g_021AAA40[i].value, 0);
        }
    }
    MIi_CpuClear32(0, g_021AAA40, sizeof(MatchKey) * 0x9a);
}


/*
 * sdk:      DWCi_IsFriendByIdxList (dwc_match.o)
 */
int func_02173B74(int profileID)
{
    int i;
    int id;

    if (*(int *)(func_02175F3C() + 0x68c) == 0)
        return 0;
    for (i = 0; i < *(int *)(func_02175F3C() + 0x6d4); i++) {
        id = func_02168FF0(*(unsigned char *)(func_02175F3C() + i + 0x694));
        if (id > 0 && id == profileID)
            return 1;
    }
    return 0;
}


/*
 * sdk:      DWCi_CheckDWCServer (dwc_match.o)
 */
int func_02173BE4(void *server)
{
    if (func_0219E120(server, g_021A21A4, -1) == -1)
        return 0;
    if (func_0219E120(server, g_021A21B0, -1) == -1)
        return 0;
    if (func_0219E120(server, g_021A2170, -1) == -1)
        return 0;
    if (func_0219E120(server, g_021A2164, -1) == -1)
        return 0;
    return func_0219E120(server, g_021A20A4, 0);
}


/*
 * Byte at +0x16 of the block, or 0xff when there is none.
 */
int func_02173C84(void)
{
    unsigned char *p = func_021763AC();

    return p == 0 ? 0xff : *(unsigned char *)(p + 0x16);
}
