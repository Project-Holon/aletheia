/*
 * file:     field_gimmick_gate_p05.c
 * unit:     yes
 * function: func_021F3AB4, func_021F3AD4, func_021F3B64
 * address:  0x021F3AB4
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200725C  0x0200725C  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200ECB4  0x0200ECB4  thumb
 *   func_0200ECD0  0x0200ECD0  thumb
 *   func_0200ECF0  0x0200ECF0  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 *   func_02012F68  0x02012F68  thumb
 *   func_0200EC14  0x0200EC14  thumb
 *   func_0200EC2C  0x0200EC2C  thumb
 */
#include "../../matched/include/Obj20532.h"

struct BigObj;
struct Big;
struct Sub020072A4Ctrl;
struct Sub020073D8Ctrl;
struct U16Vec;
struct Src0200EC2C;
struct Dst0200EC2C;
typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct St {
    void *p0;
    void *p1;
    int a;
    int b;
    u16 c;
    u8 pad[10];
} St;

extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void *func_02012EBC(struct Big *p);
extern u32 func_0200725C(void *s, u32 id, u32 heap);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern u32 func_0200ECB4(char *o);
extern int func_0200ECD0(char *o, int idx);
extern void func_0200ECF0(void *a0, u32 a1, void *a2, void *a3);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02012F68(void **h);
extern int func_0200EC14(char *p);
extern void func_0200EC2C(const struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst);
int func_021F3AB4(void *p);
void func_021F3AD4(const u16 *p, u32 *out, int *cnt);
void func_021F3B64(u16 *p, u32 *out, int *cnt);


int func_021F3AB4(void *p)
{
    return func_020142E8((void *)func_0201296C((const struct BigObj *)(((struct Obj20532 *)p)->f8)), 0x97b) == 1;
}


void func_021F3AD4(const u16 *p, u32 *out, int *cnt)
{
    int i;
    void *s;
    void *t;
    St st;

    i = 0;
    *cnt = 0;
    s = func_02012EBC((struct Big *)(((int *)p)[2]));
    if (func_0200725C(s, 8, p[0]) - 1 <= 1) {
        t = func_020073D8(s, 8, i);
        if (func_0200ECB4(t) != 0) {
            *cnt = func_0200ECD0(t, i);
            for (; i < *cnt; i++) {
                st.p0 = func_020457B0(0x40, p[0]);
                st.p1 = func_020457B0(0x40, p[0]);
                func_0200ECF0(t, 0, (void *)i, &st);
                out[i] = st.c;
                func_02045808(st.p0);
                func_02045808(st.p1);
            }
        }
    }
    func_020072A4(s, 8);
}


void func_021F3B64(u16 *p, u32 *out, int *cnt)
{
    void *s;
    int i;
    St st;

    s = func_02012F68((void **)(((int *)p)[2]));
    *cnt = func_0200EC14(s);
    for (i = 0; i < *cnt; i++) {
        st.p0 = func_020457B0(0x40, p[0]);
        st.p1 = func_020457B0(0x40, p[0]);
        func_0200EC2C(s, i, (struct Dst0200EC2C *)&st);
        out[i] = st.c;
        func_02045808(st.p0);
        func_02045808(st.p1);
    }
}
