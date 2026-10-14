/*
 * function: MAILTOOL_ProcExit
 * address:  0x021C3F98
 * packet:   pkt_ov136_021C3F98
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MAILTOOL_ProcExit 0x021C3F98 thumb
 *   MAILSYS_DeleteMessage 0x021C4134 thumb
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_0203084C 0x0203084C arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct S020314B8;
extern void func_0203133C(struct S020314B8 *v);
typedef unsigned char  u8;
extern void MAILSYS_DeleteMessage(u8 *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *v);
extern void *func_0203084C(u32 heapId);
extern void func_020306F0(u32 v);
int MAILTOOL_ProcExit(u32 a, void *b, void *c, u32 *p)
{
    u32 h;
    func_0203133C((struct S020314B8 *)p[7]);
    MAILSYS_DeleteMessage((void *)p[4]);
    h = (u16)p[0];
    func_020315D4((struct S020315D4 *)a);
    func_0203084C(h);
    func_020306F0(h);
    return 1;
}
