/*
 * function: dispPushClear
 * address:  0x021CC6AC
 * packet:   pkt_ov016_021CC6AC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_CELLlGetObj                 0x021d4fe0 arm
 *   DWCi_CEINlSet                    0x021d52d4 arm
 *   DWCi_CELLlSetPosition            0x021d5118 arm
 *   DWCi_CELLlSetPriority            0x021d51f0 arm
 *   scenesetselectap_bss             0x021de60c data
 *   C_CELL                           0x021da72c data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetselectap), symbol dispPushClear (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CC6AC.c \
 *       --func dispPushClear --addr 0x021CC6AC --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef struct tagCOORD { unsigned short x, y; } COORD;
typedef struct GXOamAttr GXOamAttr;

/* scenesetselectap.o .rodata at 0x021DA72C */
extern const COORD C_CELL[6];

/* scenesetselectap.o .bss at 0x021DE60C, members at their vendor offsets */
typedef struct {
    void          *palette;           /* 0x00 */
    void          *cellA[3];          /* 0x04 */
    void          *cellB[3];          /* 0x10 */
    unsigned char  pad0;              /* 0x1C */
    unsigned char  state;             /* 0x1D */
    unsigned char  pad1[2];
} SSSA;                               /* 0x20 */

typedef struct {
    unsigned char  FocusPos;          /* 0x00 */
    SSSA          *MemSssa;           /* 0x04 */
} SCENESETSELECTAP_BSS;
extern SCENESETSELECTAP_BSS scenesetselectap_bss;

extern GXOamAttr *DWCi_CELLlGetObj(void *cell, int idx);
extern void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);

static void dispPushClear(void)
{
    int fp = scenesetselectap_bss.FocusPos - 4;

    DWCi_CEINlSet(0, 0x32, DWCi_CELLlGetObj(scenesetselectap_bss.MemSssa->cellB[fp], 0));
    DWCi_CELLlSetPosition(scenesetselectap_bss.MemSssa->cellB[fp], -1, C_CELL[fp + 3].x, C_CELL[fp + 3].y);
    DWCi_CELLlSetPriority(scenesetselectap_bss.MemSssa->cellB[fp], -1, 3);
}
