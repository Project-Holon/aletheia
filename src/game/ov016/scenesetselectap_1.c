/*
 * file:     scenesetselectap_1.c
 * unit:     yes
 * function: func_021CBC90, func_021CBCF0, func_021CBDF8
 * address:  0x021CBC90
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_HEAPlAllocEx                0x021d6414 arm
 *   initGraphics                     0x021cbcf0 arm
 *   DWCi_HLlLoad                     0x021bd674 arm
 *   DWCi_COMMENTlDispEx              0x021bd060 arm
 *   DWCi_CMNlStep                    0x021bd214 arm
 *   initObj                          0x021cbdf8 arm
 *   dispFocus                        0x021cc46c arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   scenesetselectap_bss             0x021de60c data
 *   procInit                         0x021cbf00 arm
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   func_021BD170   0x021BD170  arm  ov016
 *   func_021D4B68   0x021D4B68  arm  ov016
 *   func_021D603C   0x021D603C  arm  ov016
 *   dat_021DA7BC   0x021DA7BC  data
 *   dat_021DB708   0x021DB708  data
 *   dat_0207E51C   0x0207E51C  data
 *   dat_021DB71C   0x021DB71C  data
 *   dat_0207F0B8   0x0207F0B8  data
 *   dat_021DB734   0x021DB734  data
 *   dat_0207E3D0   0x0207E3D0  data
 *   dat_021DB74C   0x021DB74C  data
 *   dat_0207EB78   0x0207EB78  data
 *   dat_021DE60C   0x021DE60C  data
 *   func_021CF7F4  0x021CF7F4 arm   ov016
 *   func_021D5394  0x021D5394 arm   ov016
 *   func_021D5118  0x021D5118 arm   ov016
 *   func_021D51F0  0x021D51F0 arm   ov016
 *   g_021DA72C    0x021DA72C data
 *   g_021DA720    0x021DA720 data
 *   g_021DE60C    0x021DE60C data
 */
#include "../../matched/include/G_SCENESETSELECTAP_BSS.h"

typedef _Bool bool;

/* scenesetselectap.o .bss at 0x021DE60C, members at their vendor offsets */
typedef struct {
    unsigned char  pad0[0x1D];
    unsigned char  state;             /* 0x1D */
    unsigned char  pad1[2];
} SSSA;                               /* 0x20 */

typedef struct {
    unsigned char  FocusPos;          /* 0x00 */
    SSSA          *MemSssa;           /* 0x04 */
} SCENESETSELECTAP_BSS;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    char name[0x14];
    u8 f14;
    u8 f15;
} T22;

struct tagCOORD {
    unsigned short x;
    unsigned short y;
};

struct selobj {
    int f0;
    void *cell[6];
};

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_HLlLoad(int idx);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_CMNlStep(int step);
extern void DWCi_ChangeScene(void (*scene)());
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned char *func_021BD170(unsigned char *name);
extern void *func_021D4B68(char *path, unsigned long *size, int alignment);
extern void func_021D603C(int lcd, int plane);
extern unsigned char func_021CF7F4(unsigned int i);
extern void *func_021D5394(int lcd, int idx, int head);
extern void func_021D5118(void *cell, int idx, int x, int y);
extern void func_021D51F0(void *cell, int idx, int priority);
void DWCi_SceneSetSelectAp(void);
void func_021CBCF0(void);
void func_021CBDF8(void);
extern SCENESETSELECTAP_BSS scenesetselectap_bss;
extern T22 dat_021DA7BC;
extern unsigned char dat_021DB708[];
extern unsigned char dat_0207E51C[];
extern unsigned char dat_021DB71C[];
extern unsigned char dat_0207F0B8[];
extern unsigned char dat_021DB734[];
extern unsigned char dat_0207E3D0[];
extern unsigned char dat_021DB74C[];
extern unsigned char dat_0207EB78[];
extern unsigned char dat_021DE60C[];
extern const struct tagCOORD g_021DA72C[6];
extern unsigned char g_021DA720[4];
extern struct SCENESETSELECTAP_BSS g_021DE60C;


static void initGraphics(void);

static void initObj(void);

static void dispFocus(void);

static void procInit(void);


void DWCi_SceneSetSelectAp(void)
{
    SSSA *p = DWCi_HEAPlAllocEx(0x20, 4);

    scenesetselectap_bss.MemSssa = p;
    p->state = 0;
    initGraphics();
    DWCi_HLlLoad(1);
    DWCi_COMMENTlDispEx(0x2f, -1, 0);
    DWCi_CMNlStep(0);
    initObj();
    dispFocus();
    DWCi_ChangeScene(procInit);
}


/*
 * Copy a 0x16-byte NCL resource path into a stack buffer, load four
 * tilemaps through func_021BD1D4, publish the buffer through
 * func_021BD170/func_021D4B68 into the record held by 0x021DE60C+4, poke
 * func_021D603C, then set the low two bits of the 0x04001008 and
 * 0x0400000A halfword pairs.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CBCF0.c \
 *       --func func_021CBCF0 --addr 0x021CBCF0 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CBCF0(void)
{
    T22 buf;
    u16 *p;
    int r;

    buf = dat_021DA7BC;
    func_021BD1D4((char *)((int)dat_021DB708), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207E51C));
    func_021BD1D4((char *)((int)dat_021DB71C), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207F0B8));
    func_021BD1D4((char *)((int)dat_021DB734), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207E3D0));
    func_021BD1D4((char *)((int)dat_021DB74C), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207EB78));

    r = (int)func_021D4B68((char *)((int)func_021BD170((unsigned char *)(&buf))), 0, 4);
    *(int *)(*(int *)(dat_021DE60C + 4)) = r;
    func_021D603C(1, 0x10);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}


/*
 * notes: EXACT at 264 bytes, 10/10 relocations.  The park's 3-line residue
 *        (+0050..+0058: the image computes the C_CELL index `lsl r2, r3, #2`
 *        before the cell store, the parked source after it) closes on the
 *        table's own qualifier: declaring C_CELL `extern const struct tagCOORD
 *        g_021DA72C[6]` instead of plain makes the load read through a const
 *        table and the front end hoists the scaled index above the store.
 *        Nothing else in the body moves: `j = i + 3` stays.
 *
 * sdk:      initObj (libdwcutil.TWL.HYB.a scenesetselectap.o)
 */
void func_021CBDF8(void)
{
    int j;
    int type;
    int i;

    for (i = 0; i < 3; i++) {
        type = func_021CF7F4(i);
        if (type == 0xff) {
            type = 3;
        } else {
            j = i + 3;
            g_021DE60C.MemSssa->cell[i + 3] = func_021D5394(0, 0x11, 1);
            func_021D5118(g_021DE60C.MemSssa->cell[i + 3], -1, g_021DA72C[j].x, g_021DA72C[j].y);
            func_021D51F0(g_021DE60C.MemSssa->cell[i + 3], -1, 3);
        }
        g_021DE60C.MemSssa->cell[i] = func_021D5394(0, g_021DA720[type], 1);
        func_021D5118(g_021DE60C.MemSssa->cell[i], -1, g_021DA72C[i].x, g_021DA72C[i].y);
        func_021D51F0(g_021DE60C.MemSssa->cell[i], -1, 3);
    }
}
