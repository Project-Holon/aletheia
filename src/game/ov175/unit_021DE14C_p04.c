/*
 * file:     unit_021DE14C_p04.c
 * unit:     yes
 * function: func_021DEB5C, func_021DEB98, func_021DEBBC, func_021DEBE0, func_021DEBF4, func_021DEC54
 * address:  0x021DEB5C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02182AC0   0x02182AC0  arm  ov009
 *   func_021DE184   0x021DE184  arm  ov175
 *   g_021E3DF8      0x021E3DF8  data
 *   g_021E3EFC      0x021E3EFC  data
 *   func_021DE8AC  0x021DE8AC  arm
 *   d_021E3CA0  0x021E3CA0  data
 *   func_021DE14C  0x021DE14C  arm  ov175
 *   d_021E3DF8     0x021E3DF8  data
 *   d_021E3EFC     0x021E3EFC  data
 *   func_021DE1F8  0x021DE1F8  arm  ov175
 */
typedef unsigned int u32_021DEB5C;

typedef struct {
    u32_021DEB5C f0;
    u32_021DEB5C f4;
    u32_021DEB5C f8;
} Blk;

typedef unsigned long u32_021DEB98;

typedef unsigned int u32_021DEBF4;

typedef unsigned int u32_021DEC54;

extern int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern void func_021DE184(u32_021DEB5C ctx, u32_021DEB5C *arr, int n);
extern void func_021DE2E0(u32_021DEB98 a, u32_021DEB98 b, u32_021DEB98 c, u32_021DEB98 d, u32_021DEB98 e);
extern void func_021DE8AC(int, int, int);
extern int func_021DDB10(void *, int);
extern int func_021DE14C(char **, int);
extern void func_021DE1F8(u32_021DEC54 ctx, u32_021DEC54 *arr, int n);
u32_021DEB5C func_021DEB5C(char *obj);
void func_021DEB98(char *obj);
void func_021DEBBC(char *p);
void func_021DEBE0(void *p);
int func_021DEBF4(u32_021DEBF4 ctx);
int func_021DEC54(u32_021DEC54 ctx);
extern u32_021DEB5C g_021E3DF8[];
extern u32_021DEB5C g_021E3EFC[];
extern char d_021E3CA0[];
extern char d_021E3DF8[];
extern char d_021E3EFC[];


u32_021DEB5C func_021DEB5C(char *obj)
{
    Blk *b = *(Blk **)(obj + 8);

    func_02182AC0((void *)(*(u32_021DEB5C *)(obj + 0x18)), (char *)((u32_021DEB5C)g_021E3DF8), (char *)((u32_021DEB5C)g_021E3EFC), (char *)b->f0);
    func_021DE184((u32_021DEB5C)obj, (u32_021DEB5C *)b->f4, b->f8);
    return 0;
}


/*
 * Five-argument forward to func_021DE2E0 (ov175): the object itself
 *  *  is the first argument, its +0x0c cursor is passed bare and +4, and the
 *  *  +0x08 block contributes its second and third words.
 */
void func_021DEB98(char *obj)
{
    u32_021DEB98 *ip = *(u32_021DEB98 **)(obj + 8);
    u32_021DEB98 v = *(u32_021DEB98 *)(obj + 0xc);
    func_021DE2E0((u32_021DEB98)obj, v + 4, v, ip[2], ip[1]);
}


/*
 * Forward the +0x08 block's third word and the +0x0c cursor's two head words
 * to func_021DE8AC; a null cursor is a no-op.
 */
void func_021DEBBC(char *p)
{
    int *q = *(int **)(p + 0xc);
    int *r = *(int **)(p + 8);

    if (q == 0)
        return;
    func_021DE8AC(r[2], q[0], q[1]);
}


void func_021DEBE0(void *p)
{
    func_021DDB10(p, (int)d_021E3CA0);
}


/*
 * SDK provenance: sakeiGetSpecificRecordsValidateInput
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.
 */
int func_021DEBF4(u32_021DEBF4 ctx)
{
    u32_021DEBF4 *p = *(u32_021DEBF4 **)((char *)ctx + 8);

    if (p[0] == 0)
        return 4;
    if ((int)p[2] <= 0)
        return 0xd;
    if (p[1] == 0)
        return 0xc;
    if ((int)p[4] <= 0)
        return 6;
    if (p[3] == 0)
        return 5;
    return func_021DE14C((char **)p[3], p[4]);
}


/*
 * SDK provenance: sakeiGetSpecificRecordsFillSoapRequest
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.  Emit the SOAP
 * envelope, the name list and the specific-record table.
 */
int func_021DEC54(u32_021DEC54 ctx)
{
    u32_021DEC54 *p = *(u32_021DEC54 **)((char *)ctx + 8);

    func_02182AC0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3EFC,
                  (void *)p[0]);
    func_021DE1F8(ctx, (u32_021DEC54 *)p[1], p[2]);
    func_021DE184(ctx, (u32_021DEC54 *)p[3], p[4]);
    return 0;
}
