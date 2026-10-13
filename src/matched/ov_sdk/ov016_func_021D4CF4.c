/*
 * function: DWCi_CELLlInit
 * address:  0x021D4CF4
 * packet:   pkt_ov016_021D4CF4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CELLlInit (libdwcutil.TWL.HYB.a(cell.o))
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021d6414  arm  ov016
 *   DWCi_QUElFormEx  0x021d5410  arm  ov016
 *   DWCi_LSTlForm  0x021d6d44  arm  ov016
 *   DWCi_OBJlGetOam  0x021d6f84  arm  ov016
 *   DWCi_LSTlPushFront  0x021d6e04  arm  ov016
 *   DWCi_LSTlPushBack  0x021d6df4  arm  ov016
 *   gCellWork  0x021de670  data
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

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void *DWCi_QUElFormEx(long size, void *data, long dataSize);
struct ListCB;
extern struct ListCB *DWCi_LSTlForm(void);
extern GXOamAttr *DWCi_OBJlGetOam(int lcd, int idx);
extern void DWCi_LSTlPushFront(char *p, void *ob);
extern void DWCi_LSTlPushBack(char *p, void *ob);

void DWCi_CELLlInit(void)
{
    int i;

    gCellWork = (MEMCELL *)DWCi_HEAPlAllocEx(0x450, 4);
    for (i = 0; i < 2; i++) {
        gCellWork->c[i].queue = DWCi_QUElFormEx(0x20, &gCellWork->c[i], 0x10);
        gCellWork->c[i].list = DWCi_LSTlForm();
        gCellWork->c[i].oam = DWCi_OBJlGetOam(i, 0x40);
        gCellWork->c[i].oamEnd = DWCi_OBJlGetOam(i, 0x7F) + 1;
        DWCi_LSTlPushFront(gCellWork->c[i].list, gCellWork->c[i].lstA);
        DWCi_LSTlPushBack(gCellWork->c[i].list, gCellWork->c[i].lstB);
    }
}
