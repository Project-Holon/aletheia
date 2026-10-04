/*
 * function: func_02180EB0
 * address:  0x02180EB0
 * packet:   pkt_ov018_02180EB0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Callback pointer is copied unchanged by func_0201232C into task +4;
 * its legacy int parameter represents the same full-word payload.
 * symbols:
 *   func_0201232C  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_02180ED4  0x02180ED4  thumb ov018
 */

typedef unsigned int u32;
typedef struct {
    void *unk_00;
    u32 unk_04;
    u32 unk_08;
    void *unk_0c;
    void *unk_10;
} Obj;

extern void func_0201232C(char *p, int a1, int a2);
extern void *func_020124E8(Obj *);
extern void func_02082D44(const void *, void *, u32);
extern int func_02180ED4(void *, int *, void *);

void func_02180EB0(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02180ED4, 0xA0);
    dst = func_020124E8(task);
    func_02082D44(src, dst, 0x98);
}
