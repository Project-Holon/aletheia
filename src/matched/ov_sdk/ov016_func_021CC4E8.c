/*
 * function: func_021CC4E8
 * address:  0x021CC4E8
 * packet:   pkt_ov016_021CC4E8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      moveFocus (libdwcutil.TWL.HYB.a(scenesetselectap))
 *
 * symbols:
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021CC46C  0x021CC46C  arm  ov016
 *   g_021DE60C  0x021DE60C  data
 *
 * FocusPos (0x021DE60C) anchors the statics; MemSssa sits at +4. The DWARF lists
 * only move and clear; the object computes clear + 4 unconditionally before the
 * dir test, which the second local next reproduces.
 */

typedef unsigned char u8;

typedef struct tagMEMSSSA {
    char pad[0x1c];
    u8 column;          /* +0x1c */
} MEMSSSA;

typedef struct SsaStatics {
    u8 FocusPos;        /* +0x00 */
    MEMSSSA *MemSssa;   /* +0x04 */
} SsaStatics;

extern SsaStatics g_021DE60C;

extern void func_021CFFAC(unsigned int v);
extern void func_021CC46C(void);

static void func_021CC4E8(int dir)
{
    int clear;
    int next;
    int move = 1;

    switch (g_021DE60C.FocusPos) {
    case 0:
        g_021DE60C.MemSssa->column = 0;
        if (dir == 0)
            g_021DE60C.FocusPos = 2;
        else if (dir == 2)
            g_021DE60C.FocusPos = 1;
        else if (dir == 1)
            g_021DE60C.FocusPos = 3;
        else
            g_021DE60C.FocusPos = 4;
        break;
    case 1:
        g_021DE60C.MemSssa->column = 1;
        if (dir == 0)
            g_021DE60C.FocusPos = 0;
        else if (dir == 2)
            g_021DE60C.FocusPos = 2;
        else if (dir == 1)
            g_021DE60C.FocusPos = 3;
        else
            g_021DE60C.FocusPos = 5;
        break;
    case 2:
        g_021DE60C.MemSssa->column = 2;
        if (dir == 0)
            g_021DE60C.FocusPos = 1;
        else if (dir == 2)
            g_021DE60C.FocusPos = 0;
        else if (dir == 1)
            g_021DE60C.FocusPos = 3;
        else
            g_021DE60C.FocusPos = 6;
        break;
    case 3:
        clear = g_021DE60C.MemSssa->column;
        next = clear + 4;
        if (dir == 1)
            g_021DE60C.FocusPos = next;
        else if (dir == 3)
            g_021DE60C.FocusPos = clear;
        else
            move = 0;
        break;
    case 4:
        g_021DE60C.MemSssa->column = 0;
        if (dir == 0)
            g_021DE60C.FocusPos = 6;
        else if (dir == 2)
            g_021DE60C.FocusPos = 5;
        else if (dir == 1)
            g_021DE60C.FocusPos = 0;
        else
            g_021DE60C.FocusPos = 3;
        break;
    case 5:
        g_021DE60C.MemSssa->column = 1;
        if (dir == 0)
            g_021DE60C.FocusPos = 4;
        else if (dir == 2)
            g_021DE60C.FocusPos = 6;
        else if (dir == 1)
            g_021DE60C.FocusPos = 1;
        else
            g_021DE60C.FocusPos = 3;
        break;
    case 6:
        g_021DE60C.MemSssa->column = 2;
        if (dir == 0)
            g_021DE60C.FocusPos = 5;
        else if (dir == 2)
            g_021DE60C.FocusPos = 4;
        else if (dir == 1)
            g_021DE60C.FocusPos = 2;
        else
            g_021DE60C.FocusPos = 3;
        break;
    }
    if (move) {
        func_021CFFAC(8);
        func_021CC46C();
    }
}
