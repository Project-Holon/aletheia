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
 *   func_02030DA4  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02005DF8  0x02005DF8  thumb
 *   func_020312F8  0x020312F8  arm
 *   ov088_id       0x00000058  data  a1
 *   d_021BD574     0x021BD574  data  a4
 */

extern void func_02184408(void *);
extern void func_02184138(void *);
extern void func_02183F98(void *);
extern void func_02184360(void *);
extern void func_021841C8(void *);
extern void func_02183F08(void);
extern void func_02030EAC(int);
extern void func_02030DA4(int);
extern void func_020307B0(int);
extern void func_020315D4(int);
extern void func_020306F0(int);
extern void func_02005DF8(int);
extern void func_020312F8(void *, void *, int);
extern char ov088_id[];
extern char d_021BD574[];

int func_02183C50(int a, int b, int c, void *p)
{
    unsigned short v;

    func_02184408((char *)p + 0xf8);
    func_02030EAC(*(int *)((char *)p + 0x148));
    func_02030DA4(*(int *)((char *)p + 0x144));
    func_020307B0(*(int *)((char *)p + 0x140));
    func_02184138(p);
    func_02183F98(p);
    func_02184360((char *)p + 0xe4);
    func_021841C8((char *)p + 0xe4);
    func_02183F08();
    v = (unsigned short)*(int *)((char *)p + 0x14c);
    func_020315D4(a);
    func_020306F0(v);
    func_02005DF8(0xa);
    func_020312F8(ov088_id, d_021BD574, 0);
    return 1;
}