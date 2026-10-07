/*
 * file:     unit_021D4CF4_p01.c
 * unit:     yes
 * function: func_021D4CF4, func_021D4DC8
 * address:  0x021D4CF4
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
 *   func_021D6414  0x021d6414  arm  ov016
 *   func_021D5410  0x021d5410  arm  ov016
 *   func_021D6D44  0x021d6d44  arm  ov016
 *   func_021D6F84  0x021d6f84  arm  ov016
 *   func_021D6E04  0x021d6e04  arm  ov016
 *   func_021D6DF4  0x021d6df4  arm  ov016
 *   g_021DE670  0x021de670  data
 *   func_021D6D70  0x021d6d70  arm  ov016
 *   func_021D5450  0x021d5450  arm  ov016
 *   func_021D6438  0x021d6438  arm  ov016
 *   g_021DE670_free  0x021DE670  data
 */
struct ListCB;
typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;

typedef struct tagCELLPRM {
    unsigned char pad[0x200];
    unsigned char lstA[8];
    GXOamAttr *oam;
    void *oamPad;
    unsigned char lstB[8];
    GXOamAttr *oamEnd;
    void *oamEndPad;
    void *list;
    void *queue;
} CELLPRM;

typedef struct tagMEMCELL {
    CELLPRM c[2];
} MEMCELL;

extern void *func_021D6414(unsigned long size, int alignment);
extern void *func_021D5410(long size, void *data, long dataSize);
extern struct ListCB *func_021D6D44(void);
extern GXOamAttr *func_021D6F84(int lcd, int idx);
extern void func_021D6E04(char *p, void *ob);
extern void func_021D6DF4(char *p, void *ob);
extern void func_021D6D70(void *list);
extern void func_021D5450(void *queue);
extern void func_021D6438(void **mem);
void func_021D4CF4(void);
void func_021D4DC8(void);
extern MEMCELL *g_021DE670;
extern MEMCELL *g_021DE670_free;


/*
 * sdk:      DWCi_CELLlInit (libdwcutil.TWL.HYB.a(cell.o))
 */
void func_021D4CF4(void)
{
    int i;

    g_021DE670 = (MEMCELL *)func_021D6414(0x450, 4);
    for (i = 0; i < 2; i++) {
        g_021DE670->c[i].queue = func_021D5410(0x20, &g_021DE670->c[i], 0x10);
        g_021DE670->c[i].list = func_021D6D44();
        g_021DE670->c[i].oam = func_021D6F84(i, 0x40);
        g_021DE670->c[i].oamEnd = func_021D6F84(i, 0x7F) + 1;
        func_021D6E04(g_021DE670->c[i].list, g_021DE670->c[i].lstA);
        func_021D6DF4(g_021DE670->c[i].list, g_021DE670->c[i].lstB);
    }
}


/*
 * sdk:      DWCi_CELLlEnd (libdwcutil.TWL.HYB.a(cell.o))
 */
void func_021D4DC8(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_021D6D70(g_021DE670->c[i].list);
        func_021D5450(g_021DE670->c[i].queue);
    }
    func_021D6438((void **)&g_021DE670_free);
}
