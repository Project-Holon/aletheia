/*
 * function: func_021D4DC8
 * address:  0x021D4DC8
 * packet:   pkt_ov016_021D4DC8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CELLlEnd (libdwcutil.TWL.HYB.a(cell.o))
 *
 * symbols:
 *   func_021D6D70  0x021d6d70  arm  ov016
 *   func_021D5450  0x021d5450  arm  ov016
 *   func_021D6438  0x021d6438  arm  ov016
 *   g_021DE670  0x021de670  data
 *   g_021DE670_free  0x021DE670  data
 */

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

extern MEMCELL *g_021DE670;

extern MEMCELL *g_021DE670_free;
extern void func_021D6D70(void *list);
extern void func_021D5450(void *queue);
extern void func_021D6438(void **mem);

void func_021D4DC8(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_021D6D70(g_021DE670->c[i].list);
        func_021D5450(g_021DE670->c[i].queue);
    }
    func_021D6438((void **)&g_021DE670_free);
}
