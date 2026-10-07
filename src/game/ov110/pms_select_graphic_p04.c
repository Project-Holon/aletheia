/*
 * file:     pms_select_graphic_p04.c
 * unit:     yes
 * function: func_021C1798, func_021C17D0, func_021C17D4, func_021C17DC, func_021C181C, func_021C1838, func_021C1840
 * address:  0x021C1798
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021C3A74 0x021C3A74 data a4
 *   func_020419E4  0x020419E4  arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021C3A28 0x021C3A28 data a4
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204A648 0x0204A648 arm
 */
struct Cfg;
struct Bank;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u32 id; u32 rest[10];} Row;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_020403F4(u32);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void *,int,u32);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(unsigned, unsigned);
extern void func_02043598(unsigned, unsigned);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
void func_021C1798(void *p);
void func_021C17D0(void *a0);
void func_021C17D4(void *a0);
void func_021C17DC(void **p, unsigned arg, unsigned heap);
void func_021C181C(void **p);
void func_021C1838(void *a0);
void func_021C1840(void *a0);
extern Row d_021C3A74[];
extern const unsigned d_021C3A28[];

/*
 * lever: observed 44-byte table rows use a typed Row pointer; integer address
 * arithmetic swaps base/index colours, Row member access is EXACT.
 */
void func_021C1798(void *p) { const Row *base; unsigned long i; base=d_021C3A74; for(i=0;i<6;i++) func_020403F4((u8)base[i].id); func_020450C8(); func_0203F9B4(); func_02082BCC(p,0,4); }


void func_021C17D0(void *a0) { }


void func_021C17D4(void *a0)
{
    func_020419E4();
}

void func_021C17DC(void **p, unsigned arg, unsigned heap) {
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)d_021C3A28, arg, heap);
    *p = func_0204B100(128, 0, heap);
    func_0204B270(*p);
    func_020434DC(16, 1);
    func_02043598(16, 1);
}

void func_021C181C(void **p) { func_0204B1CC(*p); func_0204A5AC(); func_02082BCC(p,0,4); }

void func_021C1838(void *a0) { func_0204A600(); }


void func_021C1840(void *a0)
{
    func_0204A648();
}
