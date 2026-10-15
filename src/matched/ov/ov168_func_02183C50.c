/*
 * function: func_02183C50
 * address:  0x02183C50
 * packet:   pkt_ov168_02183C50
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_02184408  0x02184408  thumb  ov168
 *   func_02184138  0x02184138  thumb  ov168
 *   func_02183F98  0x02183F98  thumb  ov168
 *   func_02184360  0x02184360  thumb  ov168
 *   func_021841C8  0x021841C8  thumb  ov168
 *   func_02183F08  0x02183F08  thumb  ov168
 *   func_02030EAC  0x02030EAC  arm
 *   TCB_Noop  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   PROCSYS_ReplaceGlobal  0x020312F8  arm
 *   ov088_id       0x00000058  data  a1
 *   d_021BD574     0x021BD574  data  a4
 */

typedef unsigned int   u32;
struct Node;
struct Proc;
extern void func_02184408(int *p);
extern void func_02184138(char *p);
extern void func_02183F98(void *);
extern void func_02184360(char *p);
extern void func_021841C8(void *);
extern void func_02183F08(void);
extern void func_02030EAC(struct Node *n);
extern void TCB_Noop(int);
extern u32 func_020307B0(void *p);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void PROCSYS_ReplaceGlobal(u32 a1, u32 a2, u32 a3);
extern char ov088_id[];
extern char d_021BD574[];

int func_02183C50(int a, int b, int c, void *p)
{
    unsigned short v;

    func_02184408((int *)((char *)p + 0xf8));
    func_02030EAC((struct Node *)(*(int *)((char *)p + 0x148)));
    TCB_Noop(*(int *)((char *)p + 0x144));
    func_020307B0((void *)(*(int *)((char *)p + 0x140)));
    func_02184138(p);
    func_02183F98(p);
    func_02184360((char *)p + 0xe4);
    func_021841C8((char *)p + 0xe4);
    func_02183F08();
    v = (unsigned short)*(int *)((char *)p + 0x14c);
    func_020315D4((struct Proc *)a);
    GFL_HEAP_DeleteChecked(v);
    GFL_USE_FadeInBgmFull(0xa);
    PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)d_021BD574, 0);
    return 1;
}