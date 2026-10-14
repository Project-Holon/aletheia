/*
 * function: DWCi_CELLlEnd
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
 *   DWCi_LSTlDelete  0x021d6d70  arm  ov016
 *   DWCi_QUElDelete  0x021d5450  arm  ov016
 *   DWCi_HEAPlFree_  0x021d6438  arm  ov016
 *   gCellWork  0x021de670  data
 *   gMemCell  0x021DE670  data
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

extern MEMCELL *gCellWork;

extern MEMCELL *gMemCell;
extern void DWCi_LSTlDelete(void *list);
extern void DWCi_QUElDelete(void *queue);
extern void DWCi_HEAPlFree_(void **mem);

void DWCi_CELLlEnd(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        DWCi_LSTlDelete(gCellWork->c[i].list);
        DWCi_QUElDelete(gCellWork->c[i].queue);
    }
    DWCi_HEAPlFree_((void **)&gMemCell);
}
