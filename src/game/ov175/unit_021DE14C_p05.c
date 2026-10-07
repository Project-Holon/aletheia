/*
 * file:     unit_021DE14C_p05.c
 * unit:     yes
 * function: func_021DECA0, func_021DECC4, func_021DECE8
 * address:  0x021DECA0
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
 *   func_021DE2E0  0x021DE2E0  arm
 *   func_021DE8AC  0x021DE8AC  arm
 *   d_021E3C78  0x021E3C78  data
 */
typedef unsigned long u32;

extern void func_021DE2E0(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_021DE8AC(int, int, int);
extern int func_021DDB10(void *, int);
void func_021DECA0(char *obj);
void func_021DECC4(char *p);
void func_021DECE8(void *p);
extern char d_021E3C78[];


void func_021DECA0(char *obj)
{
    u32 *ip = *(u32 **)(obj + 8);
    u32 v = *(u32 *)(obj + 0xc);
    func_021DE2E0((u32)obj, v + 4, v, ip[4], ip[3]);
}


/*
 * Forward the +0x08 block's fifth word and the +0x0c cursor's two head words
 * to func_021DE8AC; a null cursor is a no-op.
 */
void func_021DECC4(char *p)
{
    int *q = *(int **)(p + 0xc);
    int *r = *(int **)(p + 8);

    if (q == 0)
        return;
    func_021DE8AC(r[4], q[0], q[1]);
}


/*
 * SDK provenance: DSP_MapProcessSegment (TwlSDK/libdsp.TWL.HYB.a, dsp_process.o),
 * ov175.  ARM tail-forwarder to func_021DDB10 with a fixed second argument.
 */
void func_021DECE8(void *p)
{
    func_021DDB10(p, (int)d_021E3C78);
}
