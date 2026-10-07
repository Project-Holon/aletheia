/*
 * file:     field_wfbc_data_local_p06.c
 * unit:     yes
 * function: func_0218677C, func_021867A8, func_021867B0, func_021867B4, func_021867C4, func_02186804, func_02186818, func_0218682C, func_02186830, func_0218683C, func_02186844, func_0218684C, func_02186854
 * address:  0x0218677C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02008530 0x02008530 thumb
 *   func_020084F4 0x020084F4 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204932C  0x0204932C  arm
 *   d_02187EB4     0x02187EB4  data  ov020  a4
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049250  0x02049250  arm
 */
#include "../../matched/include/Obj09436.h"

struct Sub0200852CObj;
struct ArcFile;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
} Nib;

extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern const void *func_020084F4(const void *p);
extern void func_02082D44(const void *src, void *dst, u32 size);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern void func_02049238(void *p);
extern u32 func_020307B0(void *p);
extern void *func_02049250(struct ArcFile *arc, unsigned int member,
                           unsigned int heap);
void func_0218677C(u8 *p, void *src);
int func_021867A8(Nib *p);
int func_021867B0(u8 *p);
int func_021867B4(u8 *p);
int *func_021867C4(int a, int id);
void func_02186804(void **p);
void func_02186818(u32 *p, u32 member);
char *func_0218682C(char *p);
void *func_02186830(struct ArcFile **p, int b, unsigned int heap);
void func_0218683C(void *p);
u8 *func_02186844(u8 *t, int i);
char *func_0218684C(char *p, int i);
int func_02186854(u16 *p);
extern int d_02187EB4;

/*
 * Follower 021867A8 is already filed separately; 020084F4 returns its unchanged incoming r0.
 */
void func_0218677C(u8 *p, void *src) { p[0] = (p[0] & ~0xF0) | 0x10; ((struct Obj09436 *)p)->f14 = func_02008530(src); func_02082D44(func_020084F4(src), p + 4, 16); }


/*
 * Unlabelled leaf (saves nothing, so disasm.py prints it as .word data);
 * filed as the blocker of func_02186D48 (ov020).
 */
int func_021867A8(Nib *p)
{
    return p->hi;
}

/*
 * Follower 021867B4 is already filed separately.
 */
int func_021867B0(u8 *p) { return p[1]; }


int func_021867B4(u8 *p)
{
    return p[2] <= 20;
}


int *func_021867C4(int a, int id)
{
    int *p = func_02030734(id, 0x38, 1, (const char *)&d_02187EB4, 0x448);

    p[0] = (int)func_020490F4(0x9a, id);
    func_0204932C((void *)p[0], a, p + 2);
    p[1] = a;
    return p;
}

void func_02186804(void **p) { func_02049238(p[0]); func_020307B0(p); }

void func_02186818(u32 *p, u32 member) { func_0204932C((struct ArcFile *)p[0], member, p + 2); p[1] = member; }

char *func_0218682C(char *p)
{
    return p + 8;
}


void *func_02186830(struct ArcFile **p, int b, unsigned int heap)
{
    return func_02049250(*p, b + 0x22, heap);
}

/*
 * Follower 02186844 is already filed separately.
 */
void func_0218683C(void *p) { func_020307B0(p); }


/*
 * Unlabelled leaf: address of the i-th two-byte pair of a table.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_02186844(u8 *t, int i)
{
    return t + i * 2;
}

char *func_0218684C(char *p, int i)
{
    return p + (i + 0xa) * 2;
}

int func_02186854(u16 *p) { int i; int n; n = 0; for (i = 0; i < 10; i++) { if (p[i] != 0xFFFF) n++; } return n; }
