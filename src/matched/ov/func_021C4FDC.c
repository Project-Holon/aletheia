/*
 * function: ZUKAN_DETAIL_FORM_ExitModelSystem
 * address:  0x021C4FDC
 * packet:   pkt_021C4FDC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_Exit  0x02014BA8  thumb  arm9
 *   MCSS_CloseHandle  0x02014CD4  thumb  arm9
 *   TCB_Noop  0x02030DA4  arm  arm9
 *   (none)

 * Releases the file and the two allocations held in the 0x10-byte records.
 */


typedef unsigned char  u8;
struct Sub02014CB8Obj;
extern void MCSS_CloseHandle(struct Sub02014CB8Obj *o);
extern void MCSS_Exit(u8 *a0);
extern void TCB_Noop(int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

typedef struct {
    int a;
    int b;
    int c;
    int d;
} T;

void ZUKAN_DETAIL_FORM_ExitModelSystem(int unused, T *p)
{
    MCSS_CloseHandle((struct Sub02014CB8Obj *)p[0].c);
    MCSS_Exit((u8 *)p[0].c);
    TCB_Noop(p[0x12].a);
    func_020307B0((void *)p[0x11].d);
}

