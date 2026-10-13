/*
 * function: func_02204D5C
 * address:  0x02204D5C
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf of the func_022040E0 dependency tree: the scene object's teardown.
 * It releases the two +0x104/+0x108 sub-objects, tears the controller links
 * down, then frees the +0x0c/+0x08/+0x04 allocations and drops the 0x43 /
 * 0x68 pools.
 *
 * symbols:
 *   func_02208770  0x02208770  thumb
 *   func_02205D28  0x02205D28  thumb
 *   func_02205100  0x02205100  thumb
 *   func_0220506C  0x0220506C  thumb
 *   func_02205580  0x02205580  thumb
 *   func_022052E8  0x022052E8  thumb
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   func_02205A84  0x02205A84  thumb
 *   func_022059A0  0x022059A0  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   func_020306F0  0x020306F0  arm
 *   ov067_id       0x00000043  data
 */
struct PrintSys;
extern void func_02208770(char *a);
extern void func_02205D28(char *p);
extern void func_02205100(void *unused, char *p);
extern void func_0220506C(int, int *);
extern void func_02205580(void *unused, char *p);
extern void func_022052E8(int, int *);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void func_02205A84(int);
extern void func_022059A0(char *p);
extern void func_02034A5C(int);
extern void func_020306F0(unsigned int);
extern unsigned char ov067_id[];

void func_02204D5C(int a, int *p)
{
    func_02208770((char *)p[0x42]);
    func_02205D28((char *)p[0x41]);
    func_02205100((void *)a, (char *)p);
    func_0220506C(a, p);
    func_02205580((void *)a, (char *)p);
    func_022052E8(a, p);
    PRINTSYS_QUE_Clear((struct PrintSys *)p[3]);
    PRINTSYS_QUE_Delete((struct PrintSys *)p[3]);
    GF_FONT_Delete((void *)p[2]);
    func_02205A84(p[1]);
    func_022059A0((char *)p[1]);
    func_02034A5C((int)ov067_id);
    func_020306F0(0x68);
}
