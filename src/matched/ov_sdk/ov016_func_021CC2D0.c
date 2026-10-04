/*
 * function: func_021CC2D0
 * address:  0x021CC2D0
 * packet:   pkt_ov016_021CC2D0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a(scenesetselectap))
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021D0A84  0x021D0A84  arm  ov016
 *   func_021BCB58  0x021BCB58  arm  ov016
 *   func_021D4F60  0x021D4F60  arm  ov016
 *   func_021BD5A8  0x021BD5A8  arm  ov016
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D4C68  0x021D4C68  arm  ov016
 *   func_021BD1D4  0x021BD1D4  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021CF404  0x021CF404  arm  ov016
 *   func_021C0E8C  0x021C0E8C  arm  ov016
 *   func_021CA5C0  0x021CA5C0  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   func_0207E51C  0x0207E51C  arm
 *   func_021C1984  0x021C1984  arm  ov016
 *   func_021CC998  0x021CC998  arm  ov016
 *   func_021C82FC  0x021C82FC  arm  ov016
 *   func_021CDCAC  0x021CDCAC  arm  ov016
 *   g_021DE60C  0x021DE60C  data
 *   g_021DE610  0x021DE610  data
 *   @21063  0x021DB760  data
 *
 * The object reaches MemSssa (0x021DE610) through FocusPos (0x021DE60C) + 4, and
 * takes &MemSssa through its own pool word; both spellings are declared.
 */

typedef unsigned char u8;
typedef unsigned long u32;

#define NELEMS(a) (sizeof(a) / sizeof((a)[0]))

typedef struct tagMEMSSSA {
    void *arc;          /* +0x00 */
    void *cellA[3];     /* +0x04 */
    void *cellB[3];     /* +0x10 */
    char pad1c;
    u8 mode;            /* +0x1d */
} MEMSSSA;

typedef struct tagSETTINGINFO {
    char pad[0xe7];
    u8 e7;
} SETTINGINFO;

typedef struct SsaStatics {
    u8 FocusPos;        /* +0x00 */
    MEMSSSA *MemSssa;   /* +0x04 */
} SsaStatics;

extern SsaStatics g_021DE60C;
extern MEMSSSA *g_021DE610;

extern int func_021D5580(int lcd);
extern int func_021D0A84(void);
extern int func_021BCB58(void);
extern void func_021D4F60(u8 *p);
extern void func_021BD5A8(void);
extern int func_021BD138(void);
extern void func_021D4C68(void *file);
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern SETTINGINFO *func_021CF404(void);
extern void func_021C0E8C(unsigned int a, unsigned int b);
extern void func_021CA5C0(unsigned char v);
extern void func_021C0E40(unsigned int v);
extern void func_021D6438(void **mem);
extern void func_0207E51C(void *, u32, u32);
extern void func_021C1984();
extern void func_021CC998();
extern void func_021C82FC();
extern void func_021CDCAC();

static void func_021CC2D0(void)
{
    int i;

    if (func_021D5580(1))
        return;
    if (func_021D5580(0))
        return;
    if (!func_021D0A84())
        return;
    if (!func_021BCB58())
        return;

    for (i = 0; i < NELEMS(g_021DE60C.MemSssa->cellA); i++) {
        if (g_021DE60C.MemSssa->cellA[i])
            func_021D4F60(g_021DE60C.MemSssa->cellA[i]);
    }
    for (i = 0; i < NELEMS(g_021DE60C.MemSssa->cellB); i++) {
        if (g_021DE60C.MemSssa->cellB[i])
            func_021D4F60(g_021DE60C.MemSssa->cellB[i]);
    }
    func_021BD5A8();
    func_021BD138();
    func_021D4C68(g_021DE60C.MemSssa->arc);
    func_021BD1D4("char/ybObjMain.ncl.l", func_0207E51C);
    func_021D6090(1, 1);
    func_021D6090(0, 0x14);

    if (g_021DE60C.MemSssa->mode == 2) {
        func_021C0E50((unsigned int)((void *)0), (unsigned int)((void *)0));
        func_021C0E40((unsigned int)func_021C1984);
    } else {
        switch (g_021DE60C.FocusPos) {
        case 0:
        case 1:
        case 2:
            func_021C0E50((unsigned int)((void *)2), (unsigned int)((void *)0));
            if (func_021CF404()->e7 == 0xff) {
                func_021C0E40((unsigned int)func_021CC998);
            } else {
                func_021C0E8C((unsigned int)((void *)0), (unsigned int)((void *)0));
                func_021CA5C0(0);
                func_021C0E40((unsigned int)func_021C82FC);
            }
            break;
        case 3:
            func_021C0E50((unsigned int)((void *)2), (unsigned int)((void *)1));
            func_021C0E40((unsigned int)func_021CDCAC);
            break;
        }
    }
    func_021D6438((void **)&g_021DE610);
}
